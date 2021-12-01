//
// Created by 周龙 on 2021/12/1.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 20 //阈值 小规模数据则使用插入排序 优化速度


//对外的接口
void quicksort(int *array, int size);

//主要的内容
void quick(int *array, int left, int right);

//处理pivot的左右两侧数据 conqueror 标准版
int Parting(int *array, int left, int right);

//随机版 且利用三数取中
int RandomParting(int *array, int left, int right);

//打印数组内容
void Showarray(int *array, int size);

//插入排序
void InsertSort(int *array, int left, int right);

//交换两个数据
void swap(int *num1, int *num2);


#endif //QUICKSORT_QUICKSORT_H
