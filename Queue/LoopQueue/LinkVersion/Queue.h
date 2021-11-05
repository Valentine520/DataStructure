//
// Created by 龙舌兰 on 2021/9/24.
//
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

//定义bool类型 作为判断
typedef _Bool bool;

//data中的数据内容
typedef struct item{
    int data;
}Item;

//循环队列
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

//清空队列中的元素
void Queue_Clear(Queue * queue);

bool QueueEmpty(const Queue*queue);

//销毁队列
void Destroy(Queue*queue);

//添加元素 尾
void AddElem(Queue*queue,Item data);

//删除元素 头
bool DeleteElem(Queue*queue);

//遍历队列的元素
void TraverseQueue(const Queue*queue,void(*Visit)(Item data));

//反向遍历队列的元素
void Back_Traverse(const Queue*queue,void (*Visit)(Item data));

//是否存在
bool Queue_Exist(Queue*queue);



#endif //QUEUE_QUEUE_H
