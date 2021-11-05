//
// Created by 龙舌兰 on 2021/9/24.
//

#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

void Initial(Queue*queue){
    queue->head=(Node*) malloc(sizeof(Node));
    queue->rear=queue->head;
    queue->head->next=queue->head;//循环链表
    queue->head->prior=queue->head;
}

bool QueueEmpty(const Queue*queue){
    int flag=0;
    if(Queue_Exist(queue)){
        //Empty
        if(queue->head->prior==queue->head){
            flag=1;
        }
    }
    else{
        flag=0;
    }
    return flag;
}

void AddElem(Queue*queue,Item data){
//    //如果其为空 则令当别论？？
//    if(QueueEmpty(queue)){
//
//    }
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    //涉及到对队头和尾的操作 使用双向循环链表更加合适·
    temp->prior=queue->rear;
    temp->next=queue->rear->next;
    queue->rear->next->prior=temp;
    queue->rear->next=temp;
    queue->rear=temp;
}

//删除元素
bool DeleteElem(Queue*queue){
    int flag=1;
    if(QueueEmpty(queue)){
        flag=0;
        fprintf(stderr,"Queue is empty.\n");
        return flag;
    }
    Node *temp=queue->head->next;//记录待删除的节点
    queue->head->next->next->prior=queue->head;
    queue->head->next=queue->head->next->next;//指向下一个节点
    if(QueueEmpty(queue)){
        queue->rear=queue->head;// 如果为空 则要移动尾指针
    }
    free(temp);
    return flag;
}


//遍历队列的元素
void TraverseQueue(const Queue*queue,void(*Visit)(Item data)){
    Node *temp=queue->head->next;
    while(temp!=queue->head){
        Visit(temp->data);
        temp=temp->next;
    }
    putchar('\n');
}

//利用循环结构反向遍历
void Back_Traverse(const Queue*queue,void (*Visit)(Item data)){
    Node *temp=queue->rear;
    while(temp!=queue->head){
        Visit(temp->data);
        temp=temp->prior;
    }
    putchar('\n');
}


//清空
void Queue_Clear(Queue * queue){
    //不空
    while(!QueueEmpty(queue)){
        DeleteElem(queue);//清除其元素
    }
    queue->rear=queue->head;//尾指针指向头节点
}


bool Queue_Exist(Queue*queue){
    int flag=1;
    if(queue->head==NULL){
        flag=0;
    }
    return flag;
}

void Destroy(Queue*queue){
    Queue_Clear(queue);
    free(queue->head);
    queue->rear=queue->head=NULL;
}