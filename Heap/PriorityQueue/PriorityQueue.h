//
// Created by 周龙 on 2021/11/24.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H
/*
 * 基于Heap数据结构实现优先队列
 * Max堆的优先队列可以用于计算机系统的调度
 * Min堆的优先队列可以用于事件先后顺序的模拟
 * 其中Insert、Delete、Decrease、Increase等操作
 * 是优先队列独有的
 * 和堆排序直接在数组上建堆不同 
 * 考虑到数组和优先队列的结构不同 使用拷贝的方式重新建堆
 * 同时基于优先队列还可以实现顺序统计量的计算
 */

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

//查找数组中第K大的元素 利用Heap求解顺序统计量
Item Find(const Item *Data,int size,int k);


#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
