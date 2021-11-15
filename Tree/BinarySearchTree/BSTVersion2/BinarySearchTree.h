//
// Created by Longshelan on 2021/11/13.
//
#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H
#include <stdio.h>
#include <stdlib.h>
//
/*
 * 和recursion实现的二叉树不同
 * 使用parent去访问相应的节点内容 减少递归过程对栈的消耗
 * 使用节点的方式进行删除 代替只进行值交换的删除 正统的删除方式是硬件的真正组织方式
 * 完全利用二叉搜索树的基本结构进行遍历和查找以及predecessor和successor操作等
 * 思想来源：算法导论
 */

typedef int Item;
//Define the bool type to compatible the C++
typedef _Bool bool;
typedef struct Node{
    Item data;
    struct Node *P,*Lchild,*Rchild;//指向双亲 左右孩子
}Node,*NodePointer;

//Search the item from binary search tree
NodePointer Search(NodePointer Tree,Item data);

//Inserting the node into binary search tree
NodePointer Insert(NodePointer Tree,Item data);

//Delete the node from binary search tree
bool Delete(NodePointer *Tree,Item data);

//Visit the prenode of the assign node from  binary search tree
NodePointer Predecessor(NodePointer Tree,Item data);

//Visit the successor of the assign node from binary search tree
NodePointer Successor(NodePointer Tree,Item data);

//Traverse the binary search tree
void InorderTraverse(NodePointer Tree);

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
