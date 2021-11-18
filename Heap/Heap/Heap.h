//
// Created by 龙舌兰 on 2021/10/16.
//

#ifndef MY_HEAP_HEAP_H
#define MY_HEAP_HEAP_H

#define  MAXSIZE 1000
typedef int Item;//定义Item
typedef _Bool bool;
//Heap ADT
typedef struct Element{
    //也为树 也有内容
    Item data;
}Element;
//按照线性表存储heap中的节点

//基于完全二叉树实现
typedef struct Heap{
    int size;//大小
    int capacity;
    Element *element;//堆中存放的数据
}Heap;

//初始化Heap
Heap* Initial(Heap*heap);

//向堆中插入指定的元素data
void Insert(Heap*heap,Item data);

//删除堆顶元素
void Delete(Heap*heap);

//Percolate Down Function
void PercolateDown(Heap*heap,int index,int data);

//Percolate Up Function 
//The index is the percolate location
void PercolateUp(Heap*heap,int index,int data);

//Decrease the value of key
bool DecreaseKey(Heap *heap,int data,int new_value);

//Increase the value of key
bool IncreaseKey(Heap *heap,int data,int new_value);

//Delete the key node of the heap
bool DeleteKey(Heap *heap,int data);

//Locate the key node of the heap
int LocateKey(Heap*heap,int data);

//返回堆顶的元素
Item GetTop(Heap*heap);

//遍历堆中元素
void heap_traverse(Heap*heap);

//利用Data数组中的元素创建二叉堆
Heap* BuildHeap(const Item *Data,int size);

//查找数组中第K大的元素
Item Find(const Item *Data,int size,int k);

#endif //MY_HEAP_HEAP_H
