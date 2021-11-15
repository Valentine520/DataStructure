#ifndef REDBLACKTREE_REDBLACKTREE_H
#define REDBLACKTREE_REDBLACKTREE_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/*
 * 沿用正统版设置parent指针的二叉树的数据结构
 * 使用着色的方式进行树的高度管理
 * 使用一个nil节点代表原node中的null节点减小内存的消耗
 * 这个nil节点很关键 且只能通过root->parent进行访问(本代码中parent用P简化)
 * 源自算法导论中的思想
 */


typedef _Bool bool;
typedef int Item;
//定义枚举常量表示红黑
enum Color{
    Red,Black
};
typedef struct RBTree{
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

RBTreePointer Maximum(RBTreePointer Tree,RBTreePointer node);

RBTreePointer Successor(RBTreePointer Tree, Item data);

//Traverse the binary search tree
void InorderTraverse(RBTreePointer Tree,RBTreePointer nil);

#endif //REDBLACKTREE_REDBLACKTREE_H
