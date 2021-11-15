//
// Created by 龙舌兰 on 2021/10/2.
//
#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H
/*
 * 使用recurssion完成二叉搜索树的创建、查找、删除等操作
 * 删除时并不完全删除节点 而是使用值交换的方式对节点进行假删除
 * 和完全正统的删除方式不同
 * 基于此方法衍生出了AVLTree的操作
 */


typedef _Bool bool;
//创建BST树结构
typedef struct bstnode{
    int data;
    struct bstnode*Lchild;
    struct bstnode*Rchild;
}BSTNode;

//在树中插入节点

//使用指针的方式插入
void insert_key(BSTNode **root,int key);

//使用返回值的方式插入
BSTNode *insert_recursion(BSTNode *BST,int key);

//删除节点
bool delete(BSTNode **ROOT,int key);

//获取高度
static int GetLength(BSTNode*BST);

//查找key为key的节点 二叉搜索
void search(BSTNode*root,int key,BSTNode**target,BSTNode**pretarget);

//查找parent节点
BSTNode *presearch(BSTNode*root,int key);

//中序遍历BST
void traverse(BSTNode*Node);

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
