//
// Created by 周龙 on 2021/11/25.
//

#include "MergeSort_R.h"

//Merge Sort对外的接口
void MergeSort(int *array,int size){
    int buf[size];
    //调用归并排序核心内容
    MergeSort_R(array,buf,0,size-1);
}


void MergeSort_R(int *array,int *buf,int left,int right){
    if(left<right){
        int mid=(right-left)/2+left;
        MergeSort_R(array,buf,left,mid);
        MergeSort_R(array,buf,mid+1,right);
        Merge(array,buf,left,mid,right);//归并两个有序的子数组到buf中 如何影响array？
    }
}


//借助buf数组临时存放array的数据 交替排序 需要考虑最终的数据到底存放在哪里
void Merge(int *array,int *buf,int left,int mid,int right){
    //array的数据归并到buf中
    int n1=mid+1;
    int n2=right+1;
    int j=left,k=mid+1;//保存索引
    int i;
    for(i=left;i<n2&&j<n1&&k<n2;i++){
        if(array[k]>array[j]){
            buf[i]=array[j];
            j++;
        }
        else{
            buf[i]=array[k];
            k++;
        }
    }
    //注意下标的运算
    //拷贝剩余的内容
    while(j<n1){
        buf[i++]=array[j++];
    }
    while(k<n2){
        buf[i++]=array[k++];
    }
    //将排好序的元素倒入array中 如何改进才能提高性能？？
    for(i=left;i<=right;i++){
        array[i]=buf[i];
    }
}
