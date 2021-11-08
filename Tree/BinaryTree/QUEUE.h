//
// Created by 龙舌兰 on 2021/9/27.
//

#ifndef BINARY_TREE_QUEUE_H
#define BINARY_TREE_QUEUE_H


//定义bool类型 作为判断
typedef _Bool bool;

//data中的数据内容
typedef int Item;

//节点
typedef struct mnode{
    Item data;
    struct mnode*next;
    struct mnode*prior;
}qNode;

//队列数据类型
typedef struct queue{
    qNode *head;//头指针
    qNode *rear;//尾指针
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
bool DeleteElem(Queue*queue,Item *buf);

//遍历队列的元素
void TraverseQueue(const Queue*queue,void(*Visit)(Item data));

//反向遍历队列的元素
void Back_Traverse(const Queue*queue,void (*Visit)(Item data));




//是否存在
bool Queue_Exist(Queue*queue);

#endif //BINARY_TREE_QUEUE_H
