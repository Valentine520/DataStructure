//
// Created by 龙舌兰 on 2021/9/24.
//
#include "Loop_Queue.h"
#include <stdlib.h>
#include <stdio.h>
//队列初始化
bool Initial(Loop_Queue *queue){
    bool flag=1;
    queue->data=(Item*) malloc(sizeof(Item)*QUEUESIZE);
    if(queue->data==NULL){
        flag=0;
        fprintf(stderr,"Fail to allocate the storage of queue.\n");
        return flag;
    }
    queue->font=queue->rear=0;//空
    return flag;
}

//获取队列元素的个数
size_t QueueLength(const Loop_Queue *queue){
    size_t size=0;
    if(QueueEmpty(queue)){
        size=0;
    }
    else{
        size=(queue->rear-queue->font+QUEUESIZE)%QUEUESIZE;//借助%运算实现诸多操作
    }
    return size;
}

//尾端进入
bool EnQueue(Loop_Queue*queue,Item data){
    int flag=1;
    //如果队列已满
    if(QueueFull(queue)){
        fprintf(stderr,"The queue is full of elements.\n");
        flag=0;
    }
    else{
        queue->data[queue->rear]=data;
        queue->rear=(queue->rear+1)%QUEUESIZE;//更新相对与QUEUE的位置
    }
    return flag;
}

//头端删除
bool DeQueue(Loop_Queue*queue,Item *data){
    int flag=1;
    if(QueueEmpty(queue)){
        flag=0;
        fprintf(stderr,"The queue is empty.\n");
    }
    else{
        *data=queue->data[queue->font];
        queue->font=(queue->font+1)%QUEUESIZE;
    }
    return flag;
}

//是否空
bool QueueEmpty(const Loop_Queue*queue){
    bool flag=0;
    if(queue->rear==queue->font){
        flag=1;
    }
    return flag;
}

//是否满
bool QueueFull(const Loop_Queue*queue){
    bool flag=0;
    //如果只剩下唯一一个剩余空间 则满
    if((queue->rear+1)%QUEUESIZE==queue->font){
        flag=1;
    }
    return flag;
}


void Traverse(const Loop_Queue*queue){
    int temp=(queue->font)%QUEUESIZE;
    do{
        printf("%d \n",queue->data[temp].data);
        temp=(temp+1)%QUEUESIZE;
    } while (temp%QUEUESIZE!=(queue->rear-1)%QUEUESIZE);
    putchar('\n');
}