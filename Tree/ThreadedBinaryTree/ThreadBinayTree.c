//
// Created by 龙舌兰 on 2021/9/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ThreadedBinaryTree.h"

static Node* My_Lmost(Node*Btree);//辅助函数 一路向左 返回最左端的节点
static Node* My_Rmost(Node *Btree);//辅助函数 一路向右 返回最右端的节点

//构造二叉树
//使用递归的方法构造 在构造结束时其头指针方向不变
void CreateBtree(Node**Btree){
    int num;
    int judge=scanf("%d",&num);
    while(getchar()!='\n'){
        continue;
    }
    //未输入值 则表示没有节点
    if(judge!=1){
        *Btree=NULL;//节点为空
    }
    else{
        *Btree=(Node*)malloc(sizeof(Node));//创建节点
        (*Btree)->data=num;
        (*Btree)->Lsurplus=1;
        (*Btree)->Rsurplus=1;
        CreateBtree(&(*Btree)->Lchild);//创建左节点
        CreateBtree(&(*Btree)->Rchild);//创建右节点
    }
}

//先序遍历法
int FTraverseBtree(Node*Btree){
    static int count=0;
    if(Btree==NULL){
        return count;
    }
    else{
        printf("%d\n",Btree->data);
        count++;
        FTraverseBtree(Btree->Lchild);
        FTraverseBtree(Btree->Rchild);//前序遍历
    }
    return count;
}


//中序遍历法
void MTraverseBtree(Node*Btree){
    if(Btree==NULL){
        return;
    }
    else{
        FTraverseBtree(Btree->Lchild);
        printf("%d\n",Btree->data);
        FTraverseBtree(Btree->Rchild);
    }
}

//后序遍历法
void LTraverseBtree(Node*Btree){
    if(Btree==NULL){
        return;
    }
    else{
        FTraverseBtree(Btree->Lchild);
        FTraverseBtree(Btree->Rchild);
        printf("%d\n",Btree->data);
    }
}


//先序遍历法
void ClearTree(Node**Btree){
    if(*Btree==NULL){
        return;
    }
    else{
        //后序遍历清空节点
        ClearTree(&(*Btree)->Lchild);
        ClearTree(&(*Btree)->Rchild);
        free(*Btree);
        *Btree=NULL;//释放掉 指向为空
    }
}

//线索化二叉树
void Double_Thread_Binary_Tree(Node*Btree){
    //静态数据结构 pre应该一直适用 或者可以作为递归函数的参数
    static Node *pre=NULL;
    if(Btree){
        //中序遍历的特点
        Double_Thread_Binary_Tree(Btree->Lchild);//一直向左
        //利用Left剩余的内容指向前驱
        //如果为最左下方的第一个节点 则指向NULL
        if(!Btree->Lchild){
            Btree->Lchild=pre;
            Btree->Lsurplus=0;
        }
        if(pre&&!pre->Rchild){
            pre->Rchild=Btree;//右侧指针指向当前节点 即为线索化 指向后继
            pre->Rsurplus=0;
        }
        //后置更新 用以存储其pre节点
        pre=Btree;//指向当前节点
        Double_Thread_Binary_Tree(Btree->Rchild);//向右
    }
}


void Single_Thread_Binary_Tree(Node*Btree,Node *pre){
    if(Btree){
        Single_Thread_Binary_Tree(Btree->Lchild, pre);//一路向左
        //如果pre为NULL则表示其为最左侧的首个节点
        if(pre&&!pre->Rchild){
            pre->Rchild=Btree;//指向
            pre->Rsurplus=0;//右侧为线
        }
        Single_Thread_Binary_Tree(Btree->Rchild, pre);//向右
    }
}



void Show(Node*Btree){
    int count=0;
    Node *temp=NULL;
    temp= My_Lmost(Btree);
    //同时为空则表示到达了末尾
    while(temp!=NULL){
        printf("%d\n",temp->data);
        count++;
        //为链 则一路向右
        if(temp->Rsurplus==1){
            temp=My_Lmost(temp->Rchild);
        }
        //为线索 则为直接后继
        else{
            temp=temp->Rchild;
        }
    }
    printf("fuck:%d\n",count);
}


void ReverseShow(Node*Btree){
    int count=0;
    Node *temp=NULL;
    temp= My_Rmost(Btree);
    //同时为空则表示到达了末尾
    while(temp!=NULL){
        printf("%d\n",temp->data);
        count++;
        if(temp->Lsurplus==1){
            temp=My_Rmost(temp->Lchild);
        }
        else{
            temp=temp->Lchild;
        }
    }
    printf("fuck:%d\n",count);
}


//由于左右标记不同 因此要分别设计函数

static Node* My_Lmost(Node*Btree){
    Node*temp=Btree;
    while(temp!=NULL&&temp->Lsurplus==1&&temp->Lchild!=NULL){
        temp=temp->Lchild;
    }
    return temp;
}

static Node* My_Rmost(Node *Btree){
    Node*temp=Btree;
    while(temp!=NULL&&temp->Rchild!=NULL&&temp->Rsurplus==1){
        temp=temp->Rchild;
    }
    return temp;
}
