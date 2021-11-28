//
// Created by 周龙 on 2021/11/28.
//
#include "queue.h"

/*
 * 基于数组实现顺序队列
 * 在队列的操作中总会涉及到font和rear的移动
 * 因而队列的可用空间在不断缩短
 * 当队列不满 如果rear在数组的底部
 * 则将数组的元素拷贝一遍到头部
 * 利用数组拷贝操作实现循环队列的内容
 * 但实际上借助 mod n 的下标运算
 * 可以很轻松地实现循环队列
 */

//创建容量为n的数组
Queue* Initial(int n){
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->data = (Item*) malloc (sizeof(Item)*n);
    queue->n = n;//队列的容量为n
    queue->font=queue->rear=0;//均在头部
    return queue;
}

//入队
void Enqueue(Queue *queue,int data){
    int size = queue->rear-queue->font;
    if(size==queue->n){
        printf("The queue is full.\n");
        return;
    }
    if(queue->rear==queue->n){
        //将原来的内容拷贝到前端
        for(int i=0;i<size;i++){
            queue->data[i]=queue->data[i+queue->font];
        }
        queue->rear=size;
        queue->font=0;
        queue->data[size]=data;//在size长度处插入该数据
    }
    else{
        queue->data[queue->rear++]=data;
    }
}

//出队
Item* Dequeue(Queue *queue){
    if(IsEmpty(queue)){
        printf("The queue is empty.\n");
        return NULL;
    }
    return &queue->data[queue->font++];
}

bool IsEmpty(Queue *queue){
    if(queue->font==queue->rear){
        return 1;//空
    }
    return 0;//不空
}

bool IsFull(Queue *queue){
    if(queue->rear-queue->font>=queue->n){
        return 1;//满
    }
    return 0;//未满
}


void Show(const Queue*queue){
    for(int i=queue->font;i<queue->rear;i++){
        printf("%d ",queue->data[i]);
    }
    putc('\n',stdout);
}