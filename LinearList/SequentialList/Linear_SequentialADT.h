//
// Created by 龙舌兰 on 2021/9/18.
//

#ifndef LINEAR_LIST_LINEAR_SEQUENTIALADT_H
#define LINEAR_LIST_LINEAR_SEQUENTIALADT_H

#define LIST_INITIAL_SIZE 100//定义数组的初始储存空间
#define LISTINCREMENT 10//定义每次新增的空间的数量
//Linear map ADT
//定义data的数据类型
typedef struct item{
    int data;
}Item;
typedef _Bool bool;//定义bool数据类型

//定义存储结构(此处为顺序)
typedef struct sequential_map{
    Item *item;//用于维护Sequential_map的存储空间
    int length;//当前数组的长度
    int size;//当前数组的容量
}S_map;


//如果需要改变线性表中的内容 则使用指针传入 否则使用结构体传入即可 避免不必要的修改 但随之而来的内存开销是非常大的
bool Initial(S_map*L);//初始化一个空的线性表L

bool DestroyList(S_map*L);//销毁创建的线性表 (真正意义上的销毁初始化创建的线性表) 返回值表示是否删除成功

bool ClearList(S_map*L);//清空线性表 （仅仅只是把线性表中存储的内容置空而已)

bool ListEmpty(S_map L);//线性表是否空

bool ListFull(S_map L);//线性表是否满

int ListLength(S_map L);//获取线性表的长度

Item GetElem(S_map L,int index);//获取指定位置的数据 (如果指定的位置不合法，即为负值或超出数组的当前数据上限）

int LocateElem(S_map L,Item data,bool (*compare)(Item data1,Item data2) );//利用compare指定的比较函数的函数指针 进行Elem的定位

Item PriorElem(S_map L,Item data);//如果data是S_map中的数据 且不是第一个 则返回其前驱

Item NextElem(S_map L,Item data);//如果data是S_map中的数据 且不是最后一个 则返回其后继

bool ListInsert(S_map *L,int index,Item data);//向线性表中指定的位置插入数据 如果插入失败 则返回0

bool ListDelete(S_map *L,int index);//删除线性表中指定位置的数据

bool ListTraverse(S_map L);//依次访问表中的元素

bool compare(Item data1,Item data2);

void ShowItem(Item item);//打印Item中的元素
#endif //LINEAR_LIST_LINEAR_SEQUENTIALADT_H
