//
// Created by 龙舌兰 on 2021/9/30.
//

#ifndef STACKTRAVERSE_STACKTRAVERSE_H
#define STACKTRAVERSE_STACKTRAVERSE_H

#define BASE_LENGTH 100  //基本长度
#define MORE_LENGTH 10   //每次新增的长度
//stack数据结构 基于数组的实现 动态栈
typedef struct node{
    int data;
    struct node *Lchild;//左孩子
    struct node *Rchild;//右孩子
}Node;

typedef struct item{
    Node data;
}Item;

typedef _Bool bool;

typedef struct stack{
    Item *base;//底指针
    Item *top;//头指针
    Item *data;//存储数据
    int Stack_Size;//当前容量
}Stack;

bool Initial_Stack(Stack*S);//栈的初始化

void Destroy_Stack(Stack*S);//删除栈

bool Clear_Stack(Stack*S);//清空栈

int Stack_Length(const Stack*S);//栈的长度

Item Get_Top(const Stack*S);//访问栈顶元素

void Push(Stack*S,Item item);//压入栈

bool Pop(Stack*S);//弹出栈

void Traverse_Stack(const Stack*S,void (*Visit)(Item*));//遍历栈的数据

bool Stack_Empty(const Stack*S);//是否空

bool Stack_Full(const Stack*S);//是否满


void Visit(Item*Data);//访问元素



//构造二叉树
void CreateBtree(Node**Btree);


//给树指定的节点分配值
bool AssignValue(Node*Btree,Item data,Item new_value);

//遍历树 (first mid last traverse , three kinds of methods )
int FTraverseBtree(Node*Btree);//先序遍历

void InorderTraverse(Node *Btree);//借助stack实现中序遍历

void PreorderTraverse(Node *Btree);//借助stack先序遍历二叉树

void PostorderTraverse(Node *Btree);//单stack实现后序遍历

void PostorderTraverse2(Node *Btree);//双stack实现后序遍历

#endif //STACKTRAVERSE_STACKTRAVERSE_H
