//
// Created by 龙舌兰 on 2021/10/16.
//
#include "Heap.h"

#include <stdio.h>
#include <stdlib.h>

static void swap(Item*data1,Item*data2);//交换元素 辅助

void Adjast(Heap*heap,int index);//调整堆

//在堆中插入元素
void Insert(Heap*heap,Item data){
    //寻找插入的位置
    int index=heap->size+1;//下标从1开始 易于index
    while(index>0){
        //判断何处可以插入
        //表示pre节点的内容
        if(heap->List[index/2].data<data){
            heap->List[index]=heap->List[index/2];//节点下移
        }
        else{
            break;
        }
        index=index/2;//向pre节点
    }
    heap->List[index].data=data;
    heap->size++;
}

//删除元素一定是从堆顶删除 堆顶元素和堆底元素对掉
void Delete(Heap*heap){
    heap->List[1].data=heap->List[heap->size].data;
    heap->size--;
    //开始调整
    int index=1;
    Adjast(heap,index);
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

void heap_traverse(Heap*heap){
    for(int i=1;i<=heap->size;i++){
        printf("%d ",heap->List[i].data);
    }
    printf("\n");
}
