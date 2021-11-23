//
// Created by 龙舌兰 on 2021/9/18.
//
//防止重复编译
#ifndef LINEAR_LINKADT_H
#define LINEAR_LINKADT_H
#include <stdlib.h>
#include <time.h>
//Linear Link  ADT
//定义data的数据类型
typedef struct item{
    int data;
}Item;

typedef _Bool bool;//定义bool数据类型

//单向链表 数据结构
typedef struct link_list{
    struct link_list *next;//指向下一结点的指针
    Item data;//保存数据
}Link_List;

//基于数据结构进行的操作

/*初始化线性链表*/
//使用二级指针传入已修改指针类型的数据
bool Initial(Link_List **L);//初始化一个空的线性表L

/*销毁化线性链表（即释放掉头节点，令头指针指向的内容为NULL）*/
void DestroyList(Link_List **L);

/*清空线性链表（即清除头节点后的内容 但线性表仍然存在）*/
void ClearList(Link_List *L);

/*线性表是否空*/
bool ListEmpty(Link_List *L);

/*线性表是否存在*/
bool ListExist(Link_List *L);

/*由于逻辑存储结构的线性链表使用动态内存开辟和回收
 *没有大小限制  故无需判断是否满
*/

/*获取线性表的长度 size_t 用于存储较大的数组索引*/
size_t ListLength(Link_List *L);

/*获取线性表中指定位置的元素 存放在data中 在合法的情况下获取
 * 对于非法空间则返回失败值*/
bool GetElem(Link_List *L,int index,Item *data);

//对链表进行排序
void InsertSort(Link_List *L);

//对有序链表进行有阈值的搜索
int Search(Link_List*L,Item data,int t);
//利用compare指定的比较函数的函数指针 进行Elem的定位
int LocateElem(Link_List *L,Item data,bool (*compare)(Item data1,Item data2) );

//如果data是S_map中的数据 且不是第一个 则返回其前驱到prior中
bool PriorElem(Link_List *L,Item data,Item *prior);

//如果data是S_map中的数据 且不是最后一个 则返回其后继到next中
bool NextElem(Link_List *L,Item data,Item *next);

//向线性表中指定的位置插入数据 如果插入失败 则返回0
bool ListInsert(Link_List *L,int index,Item data);

//删除线性表中指定位置的数据
bool ListDelete(Link_List *L,int index);

//依次访问表中的元素
bool ListTraverse(Link_List *L);

bool compare(Item data1,Item data2);

void ShowItem(Item item);//打印Item中的元素 辅助traverse 提高移植性

Link_List *Reverse(Link_List*List,int k);//逆转链表中的k个节点

//使用插入排序对链表进行排序操作
void ListInsertSort(Link_List *L);

//使用随机查找算法查找链表中的元素
int RandomSearch(Link_List*L,Item data,int t);

#endif //LINEAR_LINKADT_H


