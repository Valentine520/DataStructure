//
// Created by LongSheLan on 2021/11/24.
//

#ifndef HEAPSORT2_HEAPSORT_H
#define HEAPSORT2_HEAPSORT_H

/*
 * 借助Heap堆中Build、Percolate Down两个操作
 * 利用待排序数组建堆 交换堆顶元素和堆末元素
 * 调整堆的大小 size-1
 * 调整堆的元素 Percolate Down
 * 经size-1次上述操作 得到的堆（数组）
 * 即为有序的有效的数组
 * 在其中要注意下标的计算和Heap中以1开始不同
 * 数组是以0开始的下标计算
 */

#include <stdio.h>
#include <stdlib.h>

void ShowArray(const int *array,int size);

void HeapSort(int *Data,int size);

void PercolateDown(int*heap,int index,int size);

void BuildHeap(int *heap,int size);

void Swap(int *num1,int *num2);


#endif //HEAPSORT2_HEAPSORT_H
