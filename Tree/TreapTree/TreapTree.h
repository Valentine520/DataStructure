//
// Created by 周龙 on 2021/11/17.
//

#ifndef TREAPTREE_TREAPTREE_H
#define TREAPTREE_TREAPTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * 随机构造二叉树的高度总是可观且平衡的
 * 因此引入一个priority类似于Heap维护二叉树的高度
 * priority是insert时创建的随机值
 * 结合Minimize Heap 和 Binary Search Tree 的思想完成Treap tree的构造
 * 其中很多操作在Heap和BST中都可见
 * 例如percolate up 在Heap的insert时常用
 * 再比如TransPlant 在 Binary Search tree 的Delete中常用
 * 以及Successor Traverse Search等操作
 */

typedef _Bool bool;

typedef struct TreapTree{
    //需要记录parent的内容 需要记录value 和 priority
    struct TreapTree *P,*Lchild,*Rchild;
    int value;
    int priority;
}TreapTree,*Treap;


//插入节点
Treap Insert(Treap tree,int data);

//删除
bool Delete(Treap *tree,int data);

//查找
Treap Search(Treap tree,int data);

//节点右旋
Treap RRotate(Treap node);

//节点左旋
Treap LRotate(Treap node);

//从下向上调整priority
Treap PercolateUp(Treap tree,Treap node);

//遍历二叉树
void Traverse(Treap tree);

//查找后继
Treap Successor(Treap node);

//拼接节点
void TransPlant(Treap *Tree, Treap u,Treap v);


#endif //TREAPTREE_TREAPTREE_H
