//
// Created by 龙舌兰 on 2021/9/29.
//
#include "Static_Tree.h"
#include <stdio.h>
//利用静态链表创建树 知道树的节点数
int CreateTree(Node *tree){
    for(int i=0;i<MAXSIZE;i++){
        tree[i].data=-MAXSIZE;
    }
    printf("Please enter the information of your tree.\n"); 
    Item data;
    int Lchild;
    int Rchild;
    int index=0;
    while(scanf("%d %d %d",&data,&Lchild,&Rchild)==3){
        tree[index].Rchild=Rchild;
        tree[index].Lchild=Lchild;
        tree[index].data=data;
        index++;
        printf("Please enter the information of your tree again.\n");
        //清除输入
        while(getchar()!='\n'){
            continue;
        }
    }
    return index;//节点个数
}

//找到根节点
int Root(Node *tree,int length){
    int site=-1;
    int index=0;
    int flag[MAXSIZE]={0};
    while(index<length){
        //只要一个节点没有前驱 其flag就是0 以此寻找头节点
        if(tree[index].Lchild!=-1) {
            flag[tree[index].Lchild] = 1;
        }
        if(tree[index].Rchild!=-1) {
            flag[tree[index].Rchild] = 1;
        }
        index++;
    }
    //未被访问过则代表其为根节点
    for(int i=0;i<length;i++){
        //表示尚未访问
        if(flag[i]==0){
            site=i;
            return site;
        }
    }
    printf("Site is %d\n",site);
    return site;
}

//遍历 先序遍历
void MidTraverse(Node *tree,int cur){
    if(tree[cur].data==-MAXSIZE||cur==-1){
        return;
    }
    else{
        MidTraverse(tree,tree[cur].Lchild);
        printf("%d\n",tree[cur].data);
        MidTraverse(tree,tree[cur].Rchild);

    }
}

void PreTraverse(Node *tree,int cur){
    if(tree[cur].data==-MAXSIZE||cur==-1){
        return;
    }
    else{
        printf("%d\n",tree[cur].data);
        PreTraverse(tree,tree[cur].Lchild);
        PreTraverse(tree,tree[cur].Rchild);
    }
}
void PostTraverse(Node *tree,int cur){
    if(tree[cur].data==-MAXSIZE||cur==-1){
        return;
    }
    else{
        PostTraverse(tree,tree[cur].Lchild);
        PostTraverse(tree,tree[cur].Rchild);
        printf("%d\n",tree[cur].data);
    }
}