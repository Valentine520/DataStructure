//
// Created by 周龙 on 2021/11/22.
//

#ifndef ORDER_STATISTIC_TREE_H
#define ORDER_STATISTIC_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
 * 基于红黑树的扩张
 * 对每个节点添加size作为维护内容
 * 通过size可以很方便求出RANK
 * 在其上进行按顺序查找、求出给定元素的RANK、求给定节点的RANK等
 * 在红黑树的插入删除的两个阶段维护各个节点size的大小
 * 借助红黑树的优质特性可以使上述操作在Log(n)的时间复杂度下完成
 * 相较于线性的查找便捷许多
 */


typedef _Bool bool;
typedef int Item;
//定义枚举常量表示红黑
enum Color{
    Red,Black
};
typedef struct RBTree{
    int size;//节点所含的节点数 size.left+size.right+1
    Item data;
    enum Color color;//表示红黑的颜色标记
    struct RBTree*P,*Lchild,*Rchild;
}RBTree,*RBTreePointer;

//Search the node of item
RBTreePointer Search(RBTreePointer Tree, Item data);


//Insert the node into the binary tree
RBTreePointer Insert(RBTreePointer Tree, Item data);

RBTreePointer Delete(RBTreePointer Tree,Item data);//删除节点

//Fixup the color of the node which insert
RBTreePointer RB_Insert_Fixup(RBTreePointer Tree,RBTreePointer Node);

RBTreePointer RB_Delete_Fixup(RBTreePointer Tree,RBTreePointer Node);

//如果不使用带返回值的函数 对root的操作是很复杂的
//左旋
RBTreePointer LeftRotate(RBTreePointer Tree,RBTreePointer Node);

//右旋
RBTreePointer RightRotate(RBTreePointer Tree,RBTreePointer Node);

//The help function of delete
void TransPlant(RBTreePointer *Tree, RBTreePointer u, RBTreePointer v);

//Delete the Item from RBTree
bool RBDelete(RBTreePointer *Tree,Item data);

//The help function
RBTreePointer Minimize(RBTreePointer Tree,RBTreePointer node);

//查找第i大的元素
RBTreePointer OS_SELECT(RBTreePointer Tree,int i);

//辅助函数（核心函数
RBTreePointer OS_SELECT_Help(RBTreePointer Tree,int i);

//查找Node在Tree中的位置
int OS_RANK(RBTreePointer Tree,RBTreePointer Node);

int OS_RANK_ELEMENT(RBTreePointer Tree,int data);


RBTreePointer Successor(RBTreePointer Tree, Item data);

//Traverse the binary search tree
void InorderTraverse(RBTreePointer Tree,RBTreePointer nil);



#endif //ORDER_STATISTIC_TREE_H
