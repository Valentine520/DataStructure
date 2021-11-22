//
// Created by 周龙 on 2021/11/22.
//

#ifndef INTERVALTREE_INTERVALTREE_H
#define INTERVALTREE_INTERVALTREE_H

/*
 * Interval Tree 红黑树的扩张
 * 沿用红黑树的基本数据结构
 * 在其之上添加int low 和 int high 作为区间的标记
 * 同时为每个节点添加max作为节点左右侧以及自身的max值
 * 用于进行区间的缩减
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX(x1,x2,x3)  ((x1)>(x2)?((x1)>(x3)?(x1):(x3)):((x2)>(x3)?(x2):(x3)))

typedef _Bool bool;
typedef struct  Item{
    int low;//区间的起点
    int high;//区间的终点
}Item;
//定义枚举常量表示红黑
enum Color{
    Red,Black
};
typedef struct RBTree{
    Item data;
    int max;//以节点为根的子树以及节点的区间端点的最大值
    //以左区间low作为key进行bst的组织
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

RBTreePointer Maximum(RBTreePointer Tree,RBTreePointer node);

RBTreePointer Successor(RBTreePointer Tree, Item data);

//Traverse the binary search tree
void InorderTraverse(RBTreePointer Tree,RBTreePointer nil);

//查找区间树中树否存在与i重合的区间
RBTreePointer Interval_Search(RBTreePointer Tree,Item i);

//判断两者是否同属于一个区间
bool In_Interval(Item x,Item y);

#endif //INTERVALTREE_INTERVALTREE_H
