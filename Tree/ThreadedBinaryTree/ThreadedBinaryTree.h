//
// Created by 龙舌兰 on 2021/9/30.
//

#ifndef THEARDEDBINARYTREE_THREADEDBINARYTREE_H
#define THEARDEDBINARYTREE_THREADEDBINARYTREE_H

typedef _Bool bool;

typedef int Item;

typedef struct node{
    Item data;
    //用于区分是链还是线索 针对线索和链予以不同类型的访问方式
    bool Lsurplus;
    bool Rsurplus;
    
    struct node *Lchild;//左孩子
    struct node *Rchild;//右孩子
}Node;

//构造二叉树 （非常弱智的构造方式）
void CreateBtree(Node**Btree);

//遍历树 (first mid last traverse , three kinds of methods )
int FTraverseBtree(Node*Btree);//先序遍历

void MTraverseBtree(Node*Btree);//中序遍历

void LTraverseBtree(Node*Btree);//后序遍历

//线索化二叉树
void Double_Thread_Binary_Tree(Node*Btree);

void Single_Thread_Binary_Tree(Node*Btree,Node*pre);

//打印线索二叉树的节点 (无需recursion)
//顺序 Single 和 Double 均可
void Show(Node*Btree);

//逆序 仅支持Double的线索化 
void ReverseShow(Node*Btree);

#endif //THEARDEDBINARYTREE_THREADEDBINARYTREE_H
