//
// Created by 龙舌兰 on 2021/9/27.
//

#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

typedef _Bool bool;

//定义节点的数据类型
typedef int Item;

//定义节点的数据结构
typedef struct node{
    Item data;//数据内容
    struct node *Lchild;//左孩子
    struct node *Rchild;//右孩子
}Node;

//构造二叉树
void CreateBtree(Node**Btree);

//清空二叉树
void ClearTree(Node**Btree);

//是否空
bool BtreeEmpty(Node*Btree);

//树的深度
int BtreeDepth(Node*Btree);

//查找节点的parent
bool SearchBtreeParent(Node*Btree,Item data,Node **result,int flag);

//查找指定节点的值
bool SearchBtree(Node*Btree,Item data,Node **result,int flag);

//打印待查找节点的信息 双亲 儿子 兄弟 高度
void ShowTargetNode(Node*Btree,Item data);

//给树指定的节点分配值
bool AssignValue(Node*Btree,Item data,Item new_value);

//遍历树 (first mid last traverse , three kinds of methods )
int FTraverseBtree(Node*Btree);//先序遍历

void MTraverseBtree(Node*Btree);//中序遍历

void LTraverseBtree(Node*Btree);//后序遍历

void StepTraverse(Node *Btree);//层序遍历

void StackPreTraverse(Node*Btree);//使用stack进行先序遍历

void Insert(Node *Btree,Item data);//插入节点

bool DeleteNode(Node *Btree,Item data);//删除节点

#endif //BINARY_TREE_BINARYTREE_H
