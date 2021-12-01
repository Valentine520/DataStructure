//
// Created by 周龙 on 2021/12/1.
//

#include "BasicSort.h"


//冒泡排序
void BubleSort(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[i] < array[j]) {
                //三杯水法交换数组元素
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


//选择排序 查找最小元素 而后交换空穴和最小元素
void SelectSort(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int min = array[i];
        int min_site = i;
        int j;
        for (j = i; j < size; j++) {
            if (array[j] < min) {
                min = array[j];//记录最小元素
                min_site = j;//记录最小元素的下标
            }
        }
        //交换两者元素完成选择排序 改进则为堆排序
        array[min_site] = array[i];
        array[i] = min;
    }
}


//插入排序
void InsertSort(int *array, int size) {
    int temp;
    for (int i = 1; i < size; i++) {
        temp = array[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (array[j] > temp) {
                array[j + 1] = array[j];
            } else {
                break;
            }
        }
        array[j + 1] = temp;//空穴位置
    }
}


void ShowArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 10 == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
}





