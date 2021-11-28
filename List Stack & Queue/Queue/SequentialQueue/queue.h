//
// Created by ���� on 2021/11/28.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <stdlib.h>
#include <stdio.h>
typedef int Item;
typedef _Bool bool;
//˳����� ��ѭ��
typedef struct {
    Item *data;//�������� ������
    int font,rear;
    int n;
}Queue;

Queue* Initial(int n);//��������Ϊn������

void Enqueue(Queue *queue,int data);//���

Item* Dequeue(Queue *queue);//����

bool IsEmpty(Queue *queue);//�Ƿ��

bool IsFull(Queue *queue);//�Ƿ���

void Show(const Queue*queue);
#endif //QUEUE_QUEUE_H
