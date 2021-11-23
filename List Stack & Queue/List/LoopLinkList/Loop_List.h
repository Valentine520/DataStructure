//
// Created by 龙舌兰 on 2021/9/22.
//
//循环链表ADT

#ifndef LOOP_LIST_LOOP_LIST_H
#define LOOP_LIST_LOOP_LIST_H
//只要使用了则就需要使用头文件
#include <stdbool.h>

typedef struct item{
    int data;//定义元素内容
}Item;

typedef struct loop_list{
    struct loop_list*Next;//指针域
    Item data;//数据域
}Loop_List;

bool Initial(Loop_List**L);//初始化链表

bool ListEmpty(Loop_List*L);//是否空

/*链式存储结构 无需判断*/
//bool ListFull(Loop_List*L);//是否满

int Locate_Elem(Loop_List*L,Item data);//定位链表中的指定元素

bool Delete_Elem(Loop_List**L,int index);//删除指定位置的元素(仅有存在malloc的修改才需要使用地址传递，即二级指针去接收）

void List_Clear(Loop_List**L);//清空整个链表

bool Traverse(Loop_List*L);//遍历整个链表

bool Insert_Elem(Loop_List**L,int index,Item data);

void List_Merge(Loop_List**L1,Loop_List**L2);//合并链表


#endif //LOOP_LIST_LOOP_LIST_H
