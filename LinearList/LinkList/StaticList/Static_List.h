//
// Created by 龙舌兰 on 2021/9/20.
//
//只要不涉及到指针方向的更改就可以直接使用值传递的方式传递指针
//但如果存在malloc 则必须使用地址传递 修改原指针的指向 否则malloc是失败的

#ifndef STATIC_LIST_STATIC_LIST_H
#define STATIC_LIST_STATIC_LIST_H
#define MAXSIZE 100


typedef _Bool bool;//定义bool数据类型

typedef struct item{
    int data;
}Item;

typedef struct static_list{
    Item elem;
    int index;
}Static_List;

/*链表的初始化*/
bool Initial(Static_List**L);

/*表是否满*/
bool ListFull(Static_List*L);

/*表是否存在*/
bool ListExit(Static_List*L);

/*表是否空*/
bool ListEmpty(Static_List*L);

/*向表中插入元素*/
bool Insert(Static_List**L,int index,Item data);

//遍历表中的元素
void Traverse(Static_List*L);

//删除index指定位置的元素
bool Delete(Static_List**L,int index);

//查看剩余空间
void Remaining(Static_List*L);

//按顺序归并两个表（归并的静态链表实现）
void Merge(const Static_List*L1,const Static_List*L2,Static_List*L3,int (*compare)(Item data1,Item data2));

//直接传入的方式
bool Insert2(Static_List*L,int index,Item data);

int compare(Item data1,Item data2);
#endif //STATIC_LIST_STATIC_LIST_H
