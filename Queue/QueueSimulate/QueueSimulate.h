//
// Created by 龙舌兰 on 2021/9/24.
//
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


//定义bool类型 作为判断
typedef _Bool bool;

//data中的数据内容
typedef struct item{
    int ArriveTime;//到达时间
    int ServeTime;//服务时间(1,2,3,4)随机
}Item;

//节点
typedef struct node{
    Item data;
    struct node*next;
    struct node*prior;
}Node;

//队列数据类型
typedef struct queue{
    Node *head;//头指针
    Node *rear;//尾指针
//    int size;//记录队列元素的个数
}Queue;

//初始化
void Initial(Queue*queue);

//队列是否空
bool QueueEmpty(const Queue*queue);

//添加元素 尾
void AddElem(Queue*queue,Item data);

//删除元素 头
bool DeleteElem(Queue*queue);

//获取元素
void GetTopElem(Queue*queue,Item *Info);

//是否存在
bool Queue_Exist(Queue*queue);

//利用队列进行模拟仿真
void SimulateQueue(double AverageArriveTime,int *RejectNum,int *ServedNum,int *WaitTime);


#endif //QUEUE_QUEUE_H
