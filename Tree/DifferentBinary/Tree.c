//
// Created by 龙舌兰 on 2021/10/7.
//
#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
static BinaryTree *NewNode(int data);

static BinaryTree *InsertNode(BinaryTree *Tree,int data);//插入节点


static int check_tree(BinaryTree *Tree,int data);//判断两个节点是否相等

BinaryTree *Create_Binary_Tree(BinaryTree *Tree,int size){
    int data;
    for(int i=0;i<size;i++){
        printf("Please enter the data of the node:\n");
        while(scanf("%d",&data)!=1){
            printf("Invalid data, please enter again.\n");
            while(getchar()!='\n'){
                continue;
            }
        }
        while(getchar()!='\n'){
            continue;
        }
        Tree=InsertNode(Tree,data);
    }
    return Tree;
}


BinaryTree *NewNode(int data){
    BinaryTree *newnode=(BinaryTree*)malloc(sizeof(BinaryTree));
    if(newnode==NULL){
        fprintf(stderr,"Fail to allocate the new node .\n");
        exit(EXIT_FAILURE);
    }
    newnode->Rchild=NULL;
    newnode->Lchild=NULL;
    newnode->data=data;
    newnode->flag=0;
    return newnode;
}

BinaryTree *InsertNode(BinaryTree *Tree,int data){
    if(Tree==NULL){
        return NewNode(data);
    }
    else{
        //小则向左
        if(data<Tree->data){
            Tree->Lchild= InsertNode(Tree->Lchild,data);
        }
        else if(data>Tree->data){
            Tree->Rchild= InsertNode(Tree->Rchild,data);
        }
        else{
            return Tree;//相等则原路返回
        }
    }
    return Tree;
}

int Judege_Binary_Tree(BinaryTree*Tree,int size){
    int result=1;
    int data;
    for(int i=0;i<size;i++){
        printf("please enter the value of node.\n");
        while(scanf("%d",&data)!=1){
            printf("Invalid data, please enter again.\n");
            while(getchar()!='\n'){
                continue;
            }
        }
        while(getchar()!='\n'){
            continue;
        }
        if(!check_tree(Tree,data)){
            result=0;
            return result;
        }
    }
    return result;
}

int check_tree(BinaryTree *Tree,int data){
    int result=1;
    int success=0;
    BinaryTree *temp=Tree;
    while(temp){
        //大则向右
        if(data>temp->data){
            //未被访问过则访问 表示该树不同构
            //如果同构则不会出现这种情况
            if(temp->flag==0){
                result=0;
                return result;
            }
            temp=temp->Rchild;
        }
        else if (data<temp->data){
            if(temp->flag==0){
                result=0;
                return result;
            }
            temp=temp->Lchild;
        }
        //查找到了节点
        else if(data==temp->data){
            temp->flag=1;
            result=1;
            success=1;
            return result;
        }
    }
    if(success==0){
        result=0;
    }
    return result;
}


//重写flag的内容
void Recite(BinaryTree*Tree){
    if(Tree==NULL){
        return;
    }
    else{
        //中序遍历 重置flag内容
        Recite(Tree->Lchild);
        Tree->flag=0;
        Recite(Tree->Rchild);
    }
}
