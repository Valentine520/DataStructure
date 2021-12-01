//
// Created by 周龙 on 2021/12/1.
//

#include "QuickSort.h"



//对外的接口
void quicksort(int *array, int size) {
    quick(array, 0, size - 1);
}

void quick(int *array, int left, int right) {
    if (right - left + 1 > LIMIT) {
        //添加阈值
        while (left < right) {
            int p = RandomParting(array, left, right);
            //p为主元的位置 主元的位置无需改变
            quick(array, left, p - 1);
            left = p + 1;//向右递归
        }
    } else {
        InsertSort(array, left, right);
    }
}

//为该区间以right作为主元进行划分
int Parting(int *array, int left, int right) {
    //取最右侧数据为pivot
    int pivot = array[right];
    //划分pivot左右两边的数据
    int i = left - 1, j = left;//令i为left-1开始 可以避免极端情况
    for (; j < right; j++) {
        //如果小于左元则和i交换 令i+1处永远都是大于主元的数据
        if (array[j] < pivot) {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i + 1], &array[right]);//不能直接拿pivot交换 而要改变right的数据
    return i + 1;//i+1则是pivot所在的位置
}


//利用随机函数划分主元
int RandomParting(int *array, int left, int right) {
    //生成left到right之间左开右闭区间的随机数
    //如果和边界相等又该如何
    //不存在right == left 的情况
    int site = rand() % (right - left) + left + 1;//如果遇到right和left相等的情况 这样取值就会error
    if (site > right || site < left) {
        fprintf(stderr, "This random number is wrong\n");
    }
    //保证最右侧数据为pivot
    if (array[left] > array[right]) {
        swap(&array[left], &array[right]);
    }
    if (array[left] > array[site]) {
        swap(&array[left], &array[site]);
    }
    if (array[site] > array[right]) {
        swap(&array[site], &array[right]);
    }
    swap(&array[site], &array[right]);//交换right和site的位置
    int pivot = array[right];
    //划分pivot左右两边的数据
    int i = left - 1, j = left;//令i为left-1开始 可以避免极端情况
    for (; j < right; j++) {
        //如果小于左元则和i交换 令i+1处永远都是大于主元的数据
        if (array[j] < pivot) {
            i++;
            swap(&array[j], &array[i]);
        }
    }
    swap(&array[i + 1], &array[right]);//不能直接拿pivot交换 而要改变right的数据
    return i + 1;//i+1则是pivot所在的位置
}


void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}


void InsertSort(int *array, int left, int right) {
    int temp;
    for (int i = left + 1; i <= right; i++) {
        temp = array[i];
        int j = i - 1;
        for (; j >= left; j--) {
            if (array[j] > temp) {
                array[j + 1] = array[j];
            } else {
                break;
            }
        }
        array[j + 1] = temp;//空穴位置
    }
}

void Showarray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%2d ", array[i]);
        if ((i + 1) % 10 == 0) {
            putchar('\n');
        }
    }
    putc('\n', stdout);
}
