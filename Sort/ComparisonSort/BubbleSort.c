//
// Created by 龙舌兰 on 2021/10/19.
//

#include "Sort.h"
//The detail implementation of bubblesort
void BubbleSort(int *array,int size){
    for(int i=size-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(array[i]<array[j]){
                //三杯水法交换数组元素
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

