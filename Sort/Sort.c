//
// Created by 龙舌兰 on 2021/10/16.
//
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000
void Adjast(Heap*heap,int index);//调整堆
void Create(Heap*heap,const Item *Data,int size);//创建堆


void BubleSort(int *array,int size){
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


void InsertSort(int *array,int size){
    //从1开始 默认第0号元素已经在其中
    //查找其插入的位置
    for(int i=1;i<size;i++){
        int temp=array[i];
        int flag=0;
        for(int j=i-1;j>=0;j--){
            if(temp<array[j]){
                array[j+1]=array[j];//移动数组元素
            }
            else{
                array[j+1]=temp;
                flag=1;
                break;
            }
        }
        if(flag==0){
            array[0]=temp;//表明需要插在头部
        }
    }
}



void ShellSort(int *array,int size){
    //依次构造不同的间隔进行插入排序
    //使用Hibbard增量序列
    int index=0;
    int factotial=2;
    while(factotial-1<size){
        array[index]= factotial-1;//构造序列
        factotial*=2;
        index++;
    }
    for(int hibbard=index-1;hibbard>=0;hibbard--){
        int dis=array[hibbard];
        //以不同间隔进行不同组的插入排序
        for(int i=0;i<dis;i++){
            //以dis为跨度
            for(int j=i+dis;j<size;j+=dis){
                int temp=array[j];
                int flag=0;
                for(int k=j-dis;k>=0;k-=dis){
                    if(temp<array[k]){
                        array[k+dis]=array[k];//移动数组元素
                    }
                    else{
                        array[k+dis]=temp;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    array[i]=temp;
                }
            }
        }
    }
}



//堆排序
void HeapSort(int *array,int size){
    int sizecopy=size;
    Heap heap;
    //创建堆
    Create(&heap,array,size);
    //首节点不用 但还是可以用来当哨兵
    while(size>0){
        //将大元素和小元素互换
        int temp=heap.List[1].data;
        heap.List[1].data= heap.List[size].data;
        heap.List[size].data=temp;
        heap.size--;
        size--;
        //从顶点调整剩余元素
        Adjast(&heap,1);
    }
    for(int i=0;i<sizecopy;i++){
        array[i]= heap.List[i+1].data;
    }
}





void show_array(int *array,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}




//创建堆
void Create(Heap*heap,const Item *Data,int size){
    //先直接插入 而后调整 从第一个含根的节点开始调整 向下调整
    for(int i=1;i<=size;i++){
        heap->List[i].data=Data[i-1];//直接拷贝
    }
    heap->size=size;
    int index=size/2;//第一个含根的亲节点
    for(int i=index;i>=1;i--){
        Adjast(heap,i);
    }
}

void swap(Item*data1,Item*data2){
    Item temp=*data1;
    *data1=*data2;
    *data2=temp;
}


void Adjast(Heap*heap,int index){
    //向下调整
    while(index*2<=heap->size){
        //比较左边 如果左child 不存在那么就无需调整了
        if(index*2+1<=heap->size) {
            //看右边是否存在
            //右边存在比较左边和右边的大小 右边大
            if (heap->List[index * 2].data < heap->List[index * 2 + 1].data &&
                heap->List[index * 2 + 1].data > heap->List[index].data) {
                //和右边交换
                swap(&heap->List[index].data, &heap->List[index * 2 + 1].data);
                index = index * 2 + 1;//向右
            } else if (heap->List[index * 2].data > heap->List[index * 2 + 1].data &&
                       heap->List[index * 2].data > heap->List[index].data) {
                //和左边交换
                swap(&heap->List[index].data, &heap->List[index * 2].data);
                index *= 2;//向左
            } else {
                break;//无须调整
            }
        }
        else if(heap->List[index].data<heap->List[index*2].data){
            swap(&heap->List[index].data,&heap->List[index*2].data);
            break;
        }
            //均没有比其大的
        else{
            break;
        }

    }
}

void SelectSort(int *array,int size){
    for(int i=0;i<size;i++){
        int MinIndex;
        int Min=MAX;
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