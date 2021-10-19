//
// Created by 龙舌兰 on 2021/10/19.
//

//
// Created by 龙舌兰 on 2021/10/18.
//
#include "Sort.h"
static void RealQuickSort(int *array,int Left,int Right);

static int FindPivot(int *array,int Left,int Right);

static void swap(int *a,int *b);


void QuickSort(int *array,int size){
    RealQuickSort(array,0,size-1);
}

static void RealQuickSort(int *array,int Left,int Right){
    int i=Left;
    int j=Right;
    //判断是否小于阈值
    if(Right-Left+1>CoutOff){
        //小于则开始进行快速排序 否则对底直接使用基本的简单排序即可
        int pivot= FindPivot(array,i,j);//根据中位数原理选择中位数作为主元效率更高
        i++;
        j--;
        while(1){
            while(array[++i]<pivot){
                continue;
            }
            while(array[--j]>pivot){
                continue;
            }
            //交换两者的下标
            if(i<j){
                swap(&array[i],&array[j]);
            }
                //何时停止？？
            else{
                swap(&array[i],&array[Right-1]);//交换主元和正确位置
                break;
            }
        }
        //向左递归
        RealQuickSort(array,Left,i-1);
        RealQuickSort(array,i+1,Right);
    }
        //规模不够 直接使用简单排序 快速方便
    else{
        InsertSort(array,Right-Left+1);
    }
}

//查找主元并返回其值
static int FindPivot(int *array,int Left,int Right){
    int Center=(Right-Left)/2+Left;
    if(array[Left]>array[Right]){
        swap(&array[Left],&array[Right]);
    }
    if(array[Left]>array[Center]){
        swap(&array[Left],&array[Center]);
    }
    if(array[Center]>array[Right]){
        swap(&array[Center],&array[Right]);
    }
    int data=array[Center];
    array[Right-1]=array[Center];
    return data;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

