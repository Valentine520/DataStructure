//
// Created by 龙舌兰 on 2021/10/2.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

//获取树的高度（深度）
static int Depth(BSTNode*node);

//获取右子树的最小节点
static BSTNode *GetRightMinNode(BSTNode*node);

//建树
void insert_key(BSTNode **root,int key){
    if((*root)!=NULL) {
        BSTNode *temp = *root;
        while (temp->data != key) {
            //大于向右
            if (temp->data < key) {
                if(temp->Rchild==NULL){
                    BSTNode *Node=(BSTNode*)malloc(sizeof(BSTNode));
                    temp->Rchild=Node;
                    Node->data=key;
                    temp->Rchild->Rchild=NULL;
                    temp->Rchild->Lchild=NULL;
                    break;
                }
                temp=temp->Rchild;
            }
            else if(temp->data>key){
                if(temp->Lchild==NULL) {
                    BSTNode *Node = (BSTNode *) malloc(sizeof(BSTNode));
                    temp->Lchild = Node;
                    Node->data=key;
                    temp->Lchild->Rchild = NULL;
                    temp->Lchild->Lchild = NULL;
                    break;
                }
                temp=temp->Lchild;
            }
        }
    }
    //Update the root 
    else{
        BSTNode *Node=(BSTNode*)malloc(sizeof(BSTNode));
        *root=Node;
        (*root)->data=key;
        (*root)->Lchild=NULL;
        (*root)->Rchild=NULL;
    }
}


//Traverse the binary search tree
void traverse(BSTNode*Node){
    if(Node==NULL){
        return;
    }
    else{
        traverse(Node->Lchild);
        printf("%d\n",Node->data);
        traverse(Node->Rchild);
    }
}

static  BSTNode * CreateNewnode(int key){
    BSTNode *NewNode=(BSTNode*)malloc(sizeof(BSTNode));
    NewNode->data=key;
    NewNode->Lchild=NewNode->Rchild=NULL;
    return NewNode;
}
BSTNode *insert_recursion(BSTNode *BST,int key){
    if(BST==NULL){
        return CreateNewnode(key);
    }
    else{
        if(BST->data>key)
        {
            BST->Lchild=insert_recursion(BST->Lchild,key);
        }
        else if(BST->data<key)
        {
            BST->Rchild=insert_recursion(BST->Rchild,key);
        }
    }
    return BST;
}

//查找 这种方法很蠢 没有有效利用二叉搜索树的结构特点
void search(BSTNode*root,int key,BSTNode**target,BSTNode**pretarget){
    if(root!=NULL) {
        if (root->data == key) {
            *target=root;
            return;
        } else {
            *pretarget=root;
            //二叉树搜索树的特性
            if (root->data > key) {
                search(root->Lchild, key,target,pretarget);
            } 
            else {
                search(root->Rchild, key,target,pretarget);
            }
            //如果没有target则没有pretarget
            if(*target==NULL){
                *pretarget=NULL;
            }
        }
    }
}

//使用返回值的方式进行查找pre
BSTNode *presearch(BSTNode*root,int key){
    static BSTNode *Result=NULL;
    if(root!=NULL) {
        if (root->data == key) {
            return Result;
        } else {
            Result = root;//保存前驱
            if (root->data > key) {
                presearch(root->Lchild, key);
            } else {
                presearch(root->Rchild, key);
            }
        }
    }
    return Result;
}

//删除 类似于二叉树的删除 是一种比较弱智的方式 真正删除了内容 而不是只是修改值
bool delete(BSTNode **ROOT,int key){
    BSTNode *root=*ROOT;
    bool flag=0;
    BSTNode *node;//target
    BSTNode *prenode;//predecessor of target
    search(root,key,&node,&prenode);
    //三种情况 前提为node存在
    if(node!=NULL) {
        flag = 1;
        if(prenode!=NULL&&node->data!=root->data) {
            //node之后没有节点
            if (node->Rchild == NULL && node->Lchild == NULL) {
                if (prenode->Lchild == node)
                    prenode->Lchild = NULL;
                else
                    prenode->Rchild = NULL;
                free(node);
            }
                //node后只有一边有节点
            else if (node->Rchild == NULL || node->Lchild == NULL) {
                if (node->Rchild != NULL) {
                    if (prenode->Lchild == node)
                        prenode->Lchild = node->Rchild;
                    else
                        prenode->Rchild = node->Rchild;
                } else {
                    if (prenode->Lchild == node)
                        prenode->Lchild = node->Lchild;
                    else
                        prenode->Rchild = node->Lchild;

                }
                free(node);
            }
                //如果两边都有节点
            else {
                //如果在左边删除 删除节点的左边链接上 右边则附着在左边的右空位
                if (node->data < prenode->data) {
                    //右边附着在左的右空位
                    BSTNode *fuck1 = node;
                    while (fuck1->Rchild) {
                        fuck1 = fuck1->Rchild;
                    }
                    fuck1->Rchild = node->Rchild;//链接上
                    prenode->Lchild = node->Lchild;
                    free(node);
                }
                    //右边
                else if (node->data > prenode->data) {
                    //左边附着在右边的左空位
                    BSTNode *fuck2 = node;
                    while (fuck2->Lchild) {
                        fuck2 = fuck2->Rchild;
                    }
                    fuck2->Lchild = node->Lchild;//链接上
                    prenode->Rchild = node->Rchild;
                    free(node);
                }
            }
        }
        //如果删除的是根节点 则要判断左链右还是右链左
        else{
            BSTNode *temp=root;
            int length_l=0;
            int length_r=0;
            BSTNode *temp1=root->Lchild;
            BSTNode *temp2=root->Rchild;
            //右链左的右侧 仍旧满足左中右递增的原则
            while(temp1!=NULL&&temp1->Rchild!=NULL){
                length_l++;
                temp1=temp1->Rchild;
            }
            //左链右的左侧
            while(temp2!=NULL&&temp2->Lchild!=NULL){
                length_r++;
                temp2=temp2->Rchild;
            }
            if(length_l>length_r){
                temp1->Rchild=root->Rchild;//右插左
                *ROOT=(*ROOT)->Lchild;
            }
            else{
                temp2->Lchild=root->Lchild;//左插右
                (*ROOT)=(*ROOT)->Rchild;
            }
            free(temp);
        }
    }
    return flag;
}


int Depth(BSTNode*node){
    static int length=0;
    static int MAX=0;
    if(node==NULL){
        return 0;
    }
    else{
        length++;
        if(length>MAX){
            MAX=length;
        }
        Depth(node->Lchild);
        length--;//回退
        Depth(node->Rchild);
    }
    return MAX;
}
