//
// Created by 周龙 on 2021/11/25.
//

#include "MergeSort_I.h"


//非递归的归并排序每次都排序、导入整个数组 所以可以借助buf进行倒入
void MergeSort(int *array,int size){
    int buff[size];//创建buff
    int k=1;
    while(k<=size){
        MergeSort_I(array,buff,k,size);
        k*=2;
        MergeSort_I(buff,array,k,size);//拷贝回
        k*=2;
    }
}

void MergeSort_I(int *array,int *buff,int k,int size){
    int i=0;
    //是否存在成对出现的归并
    while(i<=size-2*k+1){
        Merge(array,buff,i,i+k-1,i+2*k-1);//长度和实际下标应该有-1关系
        i+=2*k;//更新i的值
    }
    //存在不对称的归并
    if(i<size-k){
        Merge(array,buff,i,i+k-1,size-1);
    }
    else{
        //直接倒入剩余的值
        while(i++<size){
            buff[i]=array[i];
        }
    }
}

//借助buf数组临时存放array的数据 交替排序 最终的数据存放在buf中
void Merge(const int *array,int *buf,int left,int mid,int right){
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
}