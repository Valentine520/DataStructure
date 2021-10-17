//
// Created by 龙舌兰 on 2021/10/16.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

//结合堆排序
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


//Buble Sort
void BubleSort(int *array,int size);

//Insert Sort
void InsertSort(int *array,int size);

//Shell Sort
void ShellSort(int *array,int size);

//Print the data of array
void show_array(int *array,int size);

//HeapSort
void HeapSort(int *array,int size);

//Select Sort
void SelectSort(int *array,int size);


#endif //SORT_SORT_H
