//
// Created by 龙舌兰 on 2021/10/19.
//
//
// Created by 龙舌兰 on 2021/10/18.
//

#include "Sort.h"


void SelectSort(int *array,int size){
    for(int i=0;i<size;i++){
        int MinIndex;
        int Min=MAXSIZE;
        for(int j=i;j<size;j++){
            if(array[j]<Min){
                Min=array[j];
                MinIndex=j;
            }
        }
        array[MinIndex]=array[i];
        array[i]=Min;
    }
}


