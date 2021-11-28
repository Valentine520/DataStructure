//
// Created by ���� on 2021/11/28.
//
#include "queue.h"

/*
 * ��������ʵ��˳�����
 * �ڶ��еĲ������ܻ��漰��font��rear���ƶ�
 * ������еĿ��ÿռ��ڲ�������
 * �����в��� ���rear������ĵײ�
 * �������Ԫ�ؿ���һ�鵽ͷ��
 * �������鿽������ʵ��ѭ�����е�����
 * ��ʵ���Ͻ��� mod n ���±�����
 * ���Ժ����ɵ�ʵ��ѭ������
 */

//��������Ϊn������
Queue* Initial(int n){
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->data = (Item*) malloc (sizeof(Item)*n);
    queue->n = n;//���е�����Ϊn
    queue->font=queue->rear=0;//����ͷ��
    return queue;
}

//���
void Enqueue(Queue *queue,int data){
    int size = queue->rear-queue->font;
    if(size==queue->n){
        printf("The queue is full.\n");
        return;
    }
    if(queue->rear==queue->n){
        //��ԭ�������ݿ�����ǰ��
        for(int i=0;i<size;i++){
            queue->data[i]=queue->data[i+queue->font];
        }
        queue->rear=size;
        queue->font=0;
        queue->data[size]=data;//��size���ȴ����������
    }
    else{
        queue->data[queue->rear++]=data;
    }
}

//����
Item* Dequeue(Queue *queue){
    if(IsEmpty(queue)){
        printf("The queue is empty.\n");
        return NULL;
    }
    return &queue->data[queue->font++];
}

bool IsEmpty(Queue *queue){
    if(queue->font==queue->rear){
        return 1;//��
    }
    return 0;//����
}

bool IsFull(Queue *queue){
    if(queue->rear-queue->font>=queue->n){
        return 1;//��
    }
    return 0;//δ��
}


void Show(const Queue*queue){
    for(int i=queue->font;i<queue->rear;i++){
        printf("%d ",queue->data[i]);
    }
    putc('\n',stdout);
}