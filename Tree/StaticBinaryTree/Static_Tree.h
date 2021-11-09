//
// Created by 龙舌兰 on 2021/9/29.
//

#ifndef STATIC_BINARY_TREE_STATIC_TREE_H
#define STATIC_BINARY_TREE_STATIC_TREE_H
#define MAXSIZE 100
//使用静态链表构建树
typedef int Item;
typedef struct node{
    Item data;
    int Lchild;
    int Rchild;
}Node;

typedef struct sbtree{
    Node Tree[MAXSIZE];//创建结构体数组 用于存储节点的信息
}SBtree;

//利用静态链表创建树
int CreateTree(Node *tree);

//找到根节点
int Root();

//遍历
void PreTraverse(Node *tree,int cur);

void PostTraverse(Node *tree,int cur);

void MidTraverse(Node *tree,int cur);

#endif //STATIC_BINARY_TREE_STATIC_TREE_H
