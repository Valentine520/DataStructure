//
// Created by 周龙 on 2021/12/1.
//

#ifndef BASICSORT_BASICSORT_H
#define BASICSORT_BASICSORT_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



//冒泡排序
void BubleSort(int *array, int size);

//选择排序 查找最小元素 而后交换空穴和最小元素
void SelectSort(int *array, int size);

//插入排序
void InsertSort(int *array, int size);

//显示内容
void ShowArray(int *array, int size);



#endif //BASICSORT_BASICSORT_H
