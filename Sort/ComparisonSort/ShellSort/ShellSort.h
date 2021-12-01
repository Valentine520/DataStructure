//
// Created by 周龙 on 2021/11/25.
//

#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
 * 使用两个不同的增量序列进行插入排序算法的改进
 * Shell Sort会因为增量序列的选取而产生不同效率的排序算法
 * 如何设计合理、有效的增量序列是值得深入研究和探索的
 */


/*
 * Hibbard 增量序列
 * D=2^k-1 保证不是2的幂次 而且相邻元素互素
 */
void ShellSort_H(int *array,int size);


/*Sedgewick 增量序列
    * D=9∗4𝑖−9∗2𝑖+1
    * Or
    * D=4𝑖−3∗2𝑖+1
*/
void ShellSort_S(int *array,int size);


//上述两种算法的源头
void InsertSort(int *array,int size);


void ShowArray(const int *array ,int size);

#endif //SORT_SHELLSORT_H
