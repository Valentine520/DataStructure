//
// Created by 龙舌兰 on 2021/9/24.
//

#include "QueueSimulate.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//模拟仿真主函数
void SimulateQueue(double AverageArriveTime, int *RejectNum, int *ServedNum, int *WaitTime) {
    srand((unsigned int) time(NULL));
    for (int j = 0; j < 10; j++) {

        //创建队列
        Queue queue;
        Initial(&queue);
        //用于记录是否队列是否满
        int is_full = 0;
        //记录剩余等待时间
        int wait_time = 0;
        //模拟60分钟
        for (int i = 0; i < 60; i++) {
            //利用随机数作为是否有顾客到达的依据
            double number = (double) (rand() % 10) / 10;
            //判断是否有顾客到达
            // 顾客到达
            if (number <= AverageArriveTime) {
                if (is_full > 8) {
                    (*RejectNum)++;//拒绝
                } else {
                    int servetime = rand() % 3 + 1;
                    AddElem(&queue, (Item) {i, servetime});
                    is_full++;
                }
            }
            //服务结束且队列中仍有顾客在排队
            if (wait_time <= 0 && !QueueEmpty(&queue)) {
                Item temp ;
                GetTopElem(&queue,&temp);//获取首个内容
                wait_time=temp.ServeTime;
                (*ServedNum)++;
                *WaitTime+=i-temp.ArriveTime;
            }
            if(wait_time>0){
                wait_time--;
            }
        }
    }
}


void Initial(Queue *queue) {
    queue->head = (Node *) malloc(sizeof(Node));
    queue->rear = queue->head;
    queue->head->next = queue->head;//循环链表
    queue->head->prior = queue->head;
}

bool QueueEmpty(const Queue *queue) {
    int flag = 0;
    if (Queue_Exist(queue)) {
        //Empty
        if (queue->head->prior == queue->head) {
            flag = 1;
        }
    } else {
        flag = 0;
    }
    return flag;
}

void AddElem(Queue *queue, Item data) {
//    //如果其为空 则令当别论？？
//    if(QueueEmpty(queue)){
//
//    }
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    //涉及到对队头和尾的操作 使用双向循环链表更加合适·
    temp->prior = queue->rear;
    temp->next = queue->rear->next;
    queue->rear->next->prior = temp;
    queue->rear->next = temp;
    queue->rear = temp;
}

//删除元素
bool DeleteElem(Queue *queue) {
    int flag = 1;
    if (QueueEmpty(queue)) {
        flag = 0;
        fprintf(stderr, "Queue is empty.\n");
        return flag;
    }
    Node *temp = queue->head->next;//记录待删除的节点
    queue->head->next->next->prior = queue->head;
    queue->head->next = queue->head->next->next;//指向下一个节点
    if (QueueEmpty(queue)) {
        queue->rear = queue->head;// 如果为空 则要移动尾指针
    }
    free(temp);
    return flag;
}




void GetTopElem(Queue *queue, Item *Info) {
    if (queue != NULL) {
        *Info = queue->head->next->data;
    }
}


bool Queue_Exist(Queue *queue) {
    int flag = 1;
    if (queue->head == NULL) {
        flag = 0;
    }
    return flag;
}
