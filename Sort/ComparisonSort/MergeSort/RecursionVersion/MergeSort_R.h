//
// Created by 周龙 on 2021/11/25.
//

#ifndef MERGESORT_MERGESORT_R_H
#define MERGESORT_MERGESORT_R_H
#include <stdlib.h>
#include <stdio.h>

void Merge(int *array,int *buf,int left,int mid,int right);

//传入真实的下标而不是需要换算的size
void MergeSort_R(int *array,int *buf,int left,int right);

void MergeSort(int *array,int size);

#endif //MERGESORT_MERGESORT_R_H
