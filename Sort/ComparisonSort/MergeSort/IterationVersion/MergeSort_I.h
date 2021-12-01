//
// Created by 周龙 on 2021/11/25.
//

#ifndef MERGESORT_I_MERGESORT_I_H
#define MERGESORT_I_MERGESORT_I_H
/*
 * 归并排序不过是将大数组切分为小数组
 * 递到底而后完成划分过程
 * 即可形成许多小数组
 * 而后对每个有序的小数组层层并
 * 就可以完成归并排序
 * 而使用非递归版本的归并排序可以利用k划分区间而归并
 * 通过每次使k*=2即可实现递归版本中的归并过程
 */

#include <stdio.h>
#include <stdlib.h>


//对外接口
void MergeSort(int *array,int size);

//核心函数
void MergeSort_I(int *array,int *buff,int k,int size);

//归并有序数组
void Merge(const int *array,int *buf,int left,int mid,int right);


#endif //MERGESORT_I_MERGESORT_I_H
