//
// Created by 龙舌兰 on 2021/9/23.
//
#ifndef STACK_STACK_H
#define STACK_STACK_H
#define BASE_LENGTH 100  //基本长度
#define MORE_LENGTH 10   //每次新增的长度
//stack数据结构 基于数组的实现 动态栈
typedef struct item{
    int data;//不同的测试函数需要调整不同的数据类型
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

void Traverse_Stack(const Stack*S,void (*Visit)(Item*));//遍历栈的数据(针对数值类型而言）

bool Stack_Empty(const Stack*S);//是否空

bool Stack_Full(const Stack*S);//是否满

void Visit(Item*Data);//访问元素
#endif //STACK_STACK_H
