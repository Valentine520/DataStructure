//
// Created by 龙舌兰 on 2021/10/4.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H


/*
 * 借助非正统形式(recurssion)版本的BST完成AVLTree的构建、删除等操作
 * 记录下每次插入删除的位置 从下到上 沿着递归的方式更新节点的高度length
 * 更新节点的平衡度 balance 找到不平衡的节点
 * 判断插入、删除节点和不平衡节点之间的位置关系进行不同方式的旋转
 * 总共4种不同的方式 较为简单 平衡性较好 插入查找等操作就自然很方便
 */


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
