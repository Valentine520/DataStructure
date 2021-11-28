//
// Created by 周龙 on 2021/11/28.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <stdlib.h>
#include <stdio.h>
typedef int Item;
typedef _Bool bool;
//顺序队列 不循环
typedef struct {
    Item *data;//保存数据 用数组
    int font,rear;
    int n;
}Queue;

Queue* Initial(int n);//创建容量为n的数组

void Enqueue(Queue *queue,int data);//入队

Item* Dequeue(Queue *queue);//出队

bool IsEmpty(Queue *queue);//是否空

bool IsFull(Queue *queue);//是否满

void Show(const Queue*queue);
#endif //QUEUE_QUEUE_H
