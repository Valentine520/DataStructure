//
// Created by 龙舌兰 on 2021/9/23.
//

#ifndef DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
typedef int Item;//自定数据类型
typedef _Bool bool;
typedef struct double_list{
    struct double_list*prior;//指向上一节点
    struct double_list*next;//指向下一节点
    Item data;//数据
}Double_List;

bool Initial(Double_List**L);

bool Insert(Double_List *L,int index,Item data);//插入数据

void Traverse(Double_List*L);//遍历表中的数据


#endif //DOUBLE_LINKED_LIST_DOUBLE_LINKED_LIST_H
