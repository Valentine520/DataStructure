//
// Created by 龙舌兰 on 2021/10/7.
//

#ifndef DEFFIRENTTREE_TREE_H
#define DEFFIRENTTREE_TREE_H

/*构建一个含有flag的二叉搜索树 而后每次接受输入 
使用在树中查找节点的方法判断两棵二叉树是否同构
如果所有节点都被访问完 则表示同构 反之不同
并且如果存在节点在没访问之前就已经访问过了该节点 则表示不同构
通过建树的方式使比较更加简单*/

typedef struct BinaryTree{
    int flag;//保存是否被visit过的信息
    int data;//数据类型
    struct BinaryTree*Lchild;//左孩子指针
    struct BinaryTree*Rchild;//右孩子指针
}BinaryTree;

//根据输入创建二叉树
BinaryTree *Create_Binary_Tree(BinaryTree *Tree,int size);

//根据输入判断树和输入是否相等
int Judege_Binary_Tree(BinaryTree*Tree,int size);

//重写树中的flag
void Recite(BinaryTree*Tree);

#endif //DEFFIRENTTREE_TREE_H
