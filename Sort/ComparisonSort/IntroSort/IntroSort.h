//
// Created by 周龙 on 2021/12/1.
//

#ifndef INTROSORT_INTROSORT_H
#define INTROSORT_INTROSORT_H

/*
 * A hybird algorithm base on quick sort 、heap sort and insert sort.
 */

#define LIMIT1 50 //Heap Sort 的阈值
#define LIMIT2 10 //Insert Sort 的阈值

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//对外的接口
void IntroSort(int *array, int size);

//主要的内容
void Intro(int *array, int left, int right);

//处理pivot的左右两侧数据 conqueror 标准版
int Parting(int *array, int left, int right);

//随机版 且利用三数取中
int RandomParting(int *array, int left, int right);


//插入排序
void InsertSort(int *array, int left, int right);

//堆排序
void ShowArray(const int *array,int size);

void HeapSort(int *Data,int size);

void PercolateDown(int*heap,int index,int size);

void BuildHeap(int *heap,int size);

void Swap(int *num1,int *num2);
#endif //INTROSORT_INTROSORT_H
