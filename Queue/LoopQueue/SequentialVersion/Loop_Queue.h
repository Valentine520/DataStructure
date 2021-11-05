//
// Created by 龙舌兰 on 2021/9/24.
//

#ifndef LOOP_QUEUE_LOOP_QUEUE_H
#define LOOP_QUEUE_LOOP_QUEUE_H
#include <stdlib.h>

#define QUEUESIZE 100 //队列的最大长度

typedef _Bool bool;

typedef struct item{
    int data;
}Item;

typedef struct loop_queue{
    Item *data;//分配数据空间
    int font;//头指针
    int rear;//尾指针
}Loop_Queue;

//队列初始化
bool Initial(Loop_Queue *queue);

//获取队列元素的个数
size_t QueueLength(const Loop_Queue *queue);

//尾端进入
bool EnQueue(Loop_Queue*queue,Item data);

//头端删除
bool DeQueue(Loop_Queue*queue,Item *data);

//是否空
bool QueueEmpty(const Loop_Queue*queue);

//是否满
bool QueueFull(const Loop_Queue*queue);

void Traverse(const Loop_Queue*queue);

#endif //LOOP_QUEUE_LOOP_QUEUE_H
