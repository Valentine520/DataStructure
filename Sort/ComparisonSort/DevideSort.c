//
// Created by 龙舌兰 on 2021/10/19.
//
#include "Sort.h"

//递归版归并排序的辅助函数
static void MergeSortBase(int *array,int *Buff,int Start,int End);

static void MergeHelp(int *array,int *Buff,int L,int R,int Rend);

static void IteratorMergeHelp(const int *array,int *Buff,int L,int R,int Rend);

static void MergeIterator(int *array,int *Buff,int k,int size);


//借助Buff数组 节省空间
void MergeSortRecursion(int *array,int End){
    int Start=0;
    int size=End-Start;
    int Buff[size];
    MergeSortBase(array,Buff,Start,End-1);//注意下标
}


void MergeHelp(int *array,int *Buff,int L,int R,int Rend){
    int size=Rend-L+1;
    int Lend=R-1;
    int index=L;
    while(L<=Lend&&R<=Rend){
        if(array[L]<array[R]){
            //存放小的
            Buff[index++]=array[L++];
        }
        else{
            Buff[index++]=array[R++];
        }
    }
    //左边未归并完
    while(L<=Lend){
        Buff[index++]=array[L++];
    }
    while(R<=Rend){
        Buff[index++]=array[R++];
    }
    for(int i=0;i<size;i++,Rend--){
        array[Rend]=Buff[Rend];
    }
}





//Divide and conqueror
void MergeSortBase(int *array,int *Buff,int Start,int End){
    if(Start<End){
        int Center=(End-Start)/2+Start;
        //归

        MergeSortBase(array,Buff,Start,Center);//归并左半部分
        MergeSortBase(array,Buff,Center+1,End);//归并右半部分

        //并
        MergeHelp(array,Buff,Start,Center+1,End);
    }
}








//非递归实现的归并排序

//非递归实现归并排序
void MergeIterator(int *array,int *Buff,int k,int size){
    int i=0;
    while(i<=size-2*k+1){
        IteratorMergeHelp(array,Buff,i,i+k,i+2*k-1);//R应该在哪？？？ 非递归实现的数组索引十分复杂 十分十分复杂
        i+=2*k;//以k为间隔进行归并
    }
    //处理剩下的对
    if(i<size-k){
        IteratorMergeHelp(array,Buff,i,i+k,size-1);
    }
        //如果只存在单个有序列则保留array的内容 不进行任何操作
    else{
        //把1归并到2
        for(i;i<size;i++){
            Buff[i]=array[i];//拷贝内容
        }
    }
}

//按其大小进行归并排序
void MergeSortIterator(int *array,int size){
    int Buff[size];
    int k=1;
    while(k<=size){
        MergeIterator(array,Buff,k,size);//将array归并到Buff中
        k*=2;
        MergeIterator(Buff,array,k,size);//将Buff归并到array中  保证array中的始终保存着Buff的数据
        k*=2;
    }
}


void IteratorMergeHelp(const int *array,int *Buff,int L,int R,int Rend){
    int Lend=R-1;
    int index=L;
    while(L<=Lend&&R<=Rend){
        if(array[L]<array[R]){
            //存放小的
            Buff[index++]=array[L++];
        }
        else{
            Buff[index++]=array[R++];
        }
    }
    //左边未归并完
    while(L<=Lend){
        Buff[index++]=array[L++];
    }
    while(R<=Rend){
        Buff[index++]=array[R++];
    }
}