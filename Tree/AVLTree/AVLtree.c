//
// Created by 龙舌兰 on 2021/10/4.
//
#include "AVLtree.h"
#include <stdlib.h>
#include <stdio.h>

//左旋转
static BSTNode *LeftRotate(BSTNode*node);

//右旋转
static BSTNode *RightRotate(BSTNode*node);

//获取树的高度（深度）
static int Depth(BSTNode*node);

//获取右子树的最小节点
static BSTNode *GetRightMinNode(BSTNode*node);

//获取平衡值
static int GetBalance(BSTNode*BST);

//获取树的高度
static int GetLength(BSTNode*BST);

//创建新的节点
static  BSTNode * CreateNewnode(int key);

static int GetLength(BSTNode*BST){
    int length=0;
    if(BST==NULL){
        return length;
    }
    length=BST->length;
    return length;
}

//获取平衡值 根据平衡值去调整二叉树的高度
int GetBalance(BSTNode*BST){
    return GetLength(BST->Lchild)- GetLength(BST->Rchild);
}

BSTNode * CreateNewnode(int key){
    BSTNode *NewNode=(BSTNode*)malloc(sizeof(BSTNode));
    NewNode->data=key;
    NewNode->Lchild=NewNode->Rchild=NULL;
    NewNode->length=0;
    return NewNode;
}


BSTNode *insert_recursion_balance(BSTNode *BST,int key){
    if(BST==NULL){
        return CreateNewnode(key);
    }
    else{
        if(BST->data>key)
        {
            BST->Lchild=insert_recursion_balance(BST->Lchild,key);
        }
        else if(BST->data<key)
        {
            BST->Rchild= insert_recursion_balance(BST->Rchild,key);
        }
            //插入失败则不会引起高度的变化
        else{
            return BST;
        }
        //更新高度 计算节点的平衡值 调整不平衡的节点
        
        //更新高度 挨着被修改的路径依次更新
        int LDepth=Depth(BST->Lchild);
        int RDepth= Depth(BST->Rchild);
        BST->length=LDepth>RDepth?LDepth+1:RDepth+1;
        int balance= GetBalance(BST);//检查其高度是否满足unbalance条件
        
        //删除的四种不同情况
        
        //左低右高 插在右侧 直接左旋
        if(balance<-1&&BST->Rchild->data<key){
            //为了不影响接下来的内容 如在旋转操作过后右存在一系列操作 直接return
            return LeftRotate(BST);
        }
        //左低右高 插在左侧 先把right右侧的节点 右旋至全在右侧 然后再左旋节点至左侧 保证高度满足平衡要求
        if(balance<-1&&BST->Rchild->data>key){
            BST->Rchild= RightRotate(BST->Rchild);
            return LeftRotate(BST);
        }
        //左高右低 插在左侧 直接右旋
        if(balance>1&&BST->Lchild->data>key){
            return RightRotate(BST);
        }
        //同理 left左侧的节点 左旋至全在左侧 然后右旋节点至右侧 
        if(balance>1&&BST->Lchild->data<key){
            //右旋左 再右旋
            BST->Lchild= LeftRotate(BST->Lchild);
            return RightRotate(BST);
        }
        return BST;//不进行上述任何操作则直接返回原节点即可
    }
}


//保证平衡的前提下删除节点 在递归的过程中删除 和后继节点采用交换值的方式进行删除 不断调整值 不断删除
BSTNode *AVLdelete(BSTNode *Node,int key){
    if(Node==NULL){
        return Node;//直接返回空
    }
    else{
        //key > data 则向右树继续
        if(key>Node->data){
            //通过赋值修改其节点的值 则无需指针传入
            Node->Rchild=AVLdelete(Node->Rchild,key);
        }
        else if (key < Node->data)
            {
                Node->Lchild=AVLdelete(Node->Lchild,key);
            }
        //相等则进行删除
        else if(key==Node->data){
            //三种情况
            //为叶子
            if(Node->Lchild==NULL&&Node->Rchild==NULL){
                free(Node);
                Node=NULL;
                return Node;//直接删除
            }
            //左右子树不全存在
            else if(Node->Rchild==NULL||Node->Lchild==NULL){
                if(Node->Rchild!=NULL){
                    BSTNode *temp=Node->Rchild;
                    free(Node);//释放掉node
                    Node=temp;//令node为原来的Node->Rchild 左子树不存在
                    return Node;
                }
                else{
                    BSTNode *temp=Node->Lchild;
                    free(Node);
                    Node=temp;
                    return Node;//通过返回值的形式构造
                }
            }
            //左右子树全存在 比较复杂 涉及到4种不同删除姿势的旋转
            else{
                //寻找待删除节点的后继 进行删除
                //取右侧的最小值 即右子树的最左下侧的值
                BSTNode *RightMinNode= GetRightMinNode(Node->Rchild); 
                //为了有效的删除 RightMinNode是MinNode的PreNode
                //左child存在 说明有且仅有一个更小的值 即左值 删除左即可
                if(RightMinNode->Lchild!=NULL){
                    //将节点的值赋给删除的节点 保证删除节点后左边仍然小于该节点 右边则大于
                    Node->data=RightMinNode->Lchild->data;
                    //删除该节点 降低规模 如果该节点含有右树 则使用AVL删除对其进行删除即可
                    //将删除节点的任务分而治之 降低规模
                    RightMinNode->Lchild= AVLdelete(RightMinNode->Lchild,RightMinNode->Lchild->data);
                }
                else{
                    //左孩子不存在 仅含有右侧的后继 则要删除的是本节点
                    Node->data=Node->Rchild->data;
                    //递归调用最基本的AVL删除
                    Node->Rchild= AVLdelete(Node->Rchild,Node->Rchild->data);
                }
                return Node;//将修改后的平衡的树返回给unbalanced node的predecessor
            }
        }
        else {
            return Node;
        }
        //由于递归的实现 这里处理的节点都是返回回来的已经做好删除的节点的parent节点 对该parent节点进行调整即可
        //删除完毕后更新高度 利用recursion找到删除节点后首次发生unbalanced的node
        int Llength= GetLength(Node->Lchild);
        int Rlength= GetLength(Node->Rchild);
        //由于节点的删除 该length要减少
        //查找左右子树的高度+1 而后取max 则是整个节点的高度 
        Node->length=Llength>Rlength?Llength+1:Rlength+1;//更新节点高度
        int balance= GetBalance(Node);//计算不平衡度
        
        /*
        *删除和插入是相反的 负insert 
        *相当于是在节点左或右侧删除 
        *对节点的影响和插入相反
        */
        
        //左低右高 删在左侧 直接左旋 相当于插入在右侧
        if(balance<-1&&Node->Rchild->data>key){
            //为了不影响接下来的内容 如在旋转操作过后右存在一系列操作 直接return
            return LeftRotate(Node);
        }
        //左低右高 删在右侧 相当于在左侧插入 先把right右旋至全在右侧 然后再左旋节点至左侧
        if(balance<-1&&Node->Rchild->data<key){
            Node->Rchild= RightRotate(Node->Rchild);
            return LeftRotate(Node);
        }
        //左高右低 删在右侧 插入在左侧 直接右旋
        if(balance>1&&Node->Lchild->data<key){
            return RightRotate(Node);
        }
        //同理
        if(balance>1&&Node->Lchild->data>key){
            //右旋左 再右旋
            Node->Lchild= LeftRotate(Node->Lchild);
            return RightRotate(Node);
        }
        return Node;
    }
    return Node;
}



BSTNode *GetRightMinNode(BSTNode*node){
    //左边的最小 左小右大的原则 一直向左即可
    BSTNode *prenode=NULL;
    while(node!=NULL&&node->Lchild!=NULL){
        prenode=node;
        node=node->Lchild;
    }
    return prenode;
}

//左旋
BSTNode *LeftRotate(BSTNode*node){
    //同理
    //若不为空才进行此操作
    if(node!=NULL) {
        BSTNode *y = node->Rchild;
        BSTNode *z=node;
        BSTNode *T2=y->Lchild;
        z->Rchild=T2;
        y->Lchild=z;
        int LDepth2=Depth(node->Lchild);
        int RDepth2= Depth(node->Rchild);
        node->length= LDepth2>RDepth2?LDepth2+1:RDepth2+1;
        return y;
    }
    return node;
}

//右旋
static BSTNode *RightRotate(BSTNode*node){
    //若不为空才进行此操作
    if(node!=NULL) {
        BSTNode *y = node->Lchild;
        BSTNode *z=node;
        BSTNode *T2=y->Rchild;
        z->Lchild=T2;
        y->Rchild=z;
        int LDepth=Depth(node->Lchild);
        int RDepth= Depth(node->Rchild);
        //更新length？
        node->length=LDepth>RDepth?LDepth+1:RDepth+1;
        return y;
    }
    return node;
}

//获取树的深度
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

//遍历二叉搜索树
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
