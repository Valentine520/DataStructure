//
// Created by 周龙 on 2021/11/17.
//

#ifndef DOUBLESTACK_DOUBLESTACK_H
#define DOUBLESTACK_DOUBLESTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 2000
typedef struct Stack{
    int size;
    int Top1;
    int Top2;
    int *data;
}stack,*Stack;

//使用数组实现双栈

//初始化Stack
Stack Initial(void);

//判断双栈是否为空
// 返回值 1为非空 0为全空 -1为stack1空 -2为stack2空
int IsEmpty(Stack S);

//判断双栈是否满
int IsFull(Stack S);

//压入数据
void Push(Stack S,int index,int data);

//弹出数据
int Pop(Stack S,int index);

#endif //DOUBLESTACK_DOUBLESTACK_H
