//
// Created by 龙舌兰 on 2021/10/4.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

typedef _Bool bool;
//创建BST树结构
typedef struct bstnode{
    int data;
    int length;//记录节点高度
    struct bstnode*Lchild;
    struct bstnode*Rchild;
}BSTNode;

//删除节点 需要进行调整和旋转
BSTNode *AVLdelete(BSTNode *Node,int key);

//插入节点 同样需要对不平衡处进行调整 旋转
BSTNode *insert_recursion_balance(BSTNode *BST,int key);

//查找key为key的节点 二叉搜索
void search(BSTNode*root,int key,BSTNode**target,BSTNode**pretarget);

//中序遍历打印节点的信息
void traverse(BSTNode*Node);

#endif //AVLTREE_AVLTREE_H
