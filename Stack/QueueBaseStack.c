//
// Created by 周龙 on 2021/11/18.
//
#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 1000

/*
 * 利用双栈的push、pop实现队列的enqueue、dequeue
 * 思想源自算法导论 设置一个Restore栈和Operator栈
 * Enqueue时如果Restore不空 则直接Push进去
 * 如果空 则代表元素均在Operator栈中（全为空也可以这样考虑）
 * 那么需要将元素从Operator栈倒入Restore栈而后再Push
 * 同理在Dequeue时如果Operator栈不空 则直接Dequeue
 * 反之则从Restore栈中倒入size-1个元素入Op栈中
 * 将Re栈中的最后一个（即为需要Dequeue的元素）Pop出即可
 * 同理 使用双Queue完成Stack原理相同
 */

typedef struct Stack{
    int Top;
    int *data;
}stack,*Stack;

typedef struct Queue{
    Stack Restore;//储存栈
    Stack Operator;//操作栈
    int size;//记录队列的大小
}queue,*Queue;


//队列的初始化
Queue Initial(void){
    Queue Q=(Queue)malloc(sizeof(queue));
    Q->size=0;
    Q->Restore=(Stack) malloc(sizeof(stack));
    Q->Operator=(Stack) malloc(sizeof(stack));
    Q->Operator->Top=Q->Restore->Top=1;//起始指向
    Q->Operator->data=(int*) malloc(sizeof(int)*MAXSIZE);
    Q->Restore->data=(int*) malloc(sizeof(int)*MAXSIZE);
    return Q;
}


void Enqueue(Queue Q,int data){
    Q->size++;
    //如果operator栈空 则直接压入restore栈
    if(Q->Operator->Top==1){
        Q->Restore->data[Q->Restore->Top++]=data;
    }
    else{
        //将op栈倒回st栈
        while(Q->Operator->Top>1){
            Q->Restore->data[Q->Restore->Top++]=Q->Operator->data[--(Q->Operator->Top)];
        }
        //压入新节点
        Q->Restore->data[Q->Restore->Top++]=data;
    }
}

int Dequeue(Queue Q){
    int res=-1;
    //如果队空则返回-1
    if(Q->Restore->Top==1){
        if(Q->Operator->Top==1){
            fprintf(stderr,"the queue is empty");
            return res;
        }
        else{
            res=Q->Operator->data[--(Q->Operator->Top)];
            Q->size--;
            return res;
        }
    }
    else{
       //将n-1个节点倒入op中
        for(int i=0;i<Q->size-1;i++){
            Q->Operator->data[(Q->Operator->Top)++]=Q->Restore->data[--(Q->Restore->Top)];
        }
        //将最后一个节点pop出
        res=Q->Restore->data[--(Q->Restore->Top)];
        Q->size--;
        return res;
    }
}

int main(void){
    Queue Q;
    Q=Initial();
    Enqueue(Q,10);
    Enqueue(Q,11);
    Enqueue(Q,9);
    Enqueue(Q,17);
    while(Q->size>0){
       printf("%d ",Dequeue(Q));//按照队列的enqueue dequeue规则完成操作
    }
    return 0;
}