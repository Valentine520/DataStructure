//
// Created by 龙舌兰 on 2021/10/16.
//

#ifndef MY_HEAP_HEAP_H
#define MY_HEAP_HEAP_H

#define  MAXSIZE 1000
typedef int Item;

//Heap ADT
typedef struct List{
    //也为树 也有内容
    Item data;
}List;
//按照线性表存储heap中的节点

//基于完全二叉树实现
typedef struct Heap{
    int size;//大小
    List List[MAXSIZE];//堆中存放的数据 
}Heap;

//向堆中插入指定的元素data
void Insert(Heap*heap,Item data);

//删除堆顶元素
void Delete(Heap*heap);

//遍历堆中元素
void heap_traverse(Heap*heap);


//利用Data数组中的元素创建二叉堆
void Create(Heap*heap,const Item *Data,int size);


#endif //MY_HEAP_HEAP_H
