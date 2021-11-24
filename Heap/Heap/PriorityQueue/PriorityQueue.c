//
// Created by 周龙 on 2021/11/24.
//

#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>

static void swap(Item*data1,Item*data2);//交换元素 辅助


Heap* Initial(Heap*heap){
    //为heap分配内存空间
    heap=(Heap*)malloc(sizeof(Heap));
    if(heap==NULL){
        fprintf(stderr, "Fail to allocate the memory\n");
        return heap;
    }
    heap->size=0;
    heap->element=(Element*)malloc(sizeof(Element)*MAXSIZE+1);
    heap->capacity=MAXSIZE;//头节点作为哨兵使用
    heap->element[0].data=MAXSIZE;//最大堆
    return heap;
}


//在堆中插入元素 percolate up
void Insert(Heap*heap,Item data){
    if(heap->size>=heap->capacity){
        fprintf(stderr,"The heap is full.\n");
        return;
    }
    PercolateUp(heap,heap->size+1,data);//从插入位置开始向上调整
    heap->size++;//增加元素个数 代表插入
}

//删除元素一定是从堆顶删除 堆顶元素和堆底元素交换 然后再删除 3p型交换 不方便 可以保存节点的值作为参数传入
void Delete(Heap*heap){
    //不使用值交换的方式 减少内存开销
    if(heap->size==0){
        fprintf(stderr,"The heap is empty.\n");
        return;
    }
    int data=heap->element[heap->size].data;
    //开始调整
    PercolateDown(heap,1,data);//从堆顶开始向下调整
    heap->size--;//减少元素个数 代表删除
}


void swap(Item*data1,Item*data2){
    Item temp=*data1;
    *data1=*data2;
    *data2=temp;
}

//需要加入边界判断值 删除前是否为空 为空则无法删除  percolate down
void PercolateDown(Heap*heap,int index,int data){
    int child;
    int i;
    for(i=index;i*2<=heap->size;i=child){
        child=i*2;//i的child
        if(child!=heap->size&&heap->element[child].data<heap->element[child+1].data){
            child++;//右侧节点存在且大于左侧 则更新child为待移动节点
        }
        if(heap->element[child].data>data){
            heap->element[i].data=heap->element[child].data;
        }
        else{
            break;
        }
    }
    //确保for外部就是待插入的位置
    heap->element[i].data=data;
}

void PercolateUp(Heap*heap,int index,int data){
    //Heap的下标从1开始编号 易于查找index
    //避免到头 使用MAXSIZE放在0号位置 则一定会结束循环 不可能比0号位更大
    while(1){
        //判断何处可以插入
        //表示pre节点的内容 最大堆 插入的位置应该满足其最大堆的性质
        if(heap->element[index/2].data<data){
            heap->element[index]=heap->element[index/2];//节点下移
        }
        else{
            break;
        }
        index=index/2;//向pre节点
    }
    heap->element[index].data=data;//index即为查找到安放节点的位置

}



void heap_traverse(Heap*heap){
    for(int i=1;i<=heap->size;i++){
        printf("%d ",heap->element[i].data);
    }
    printf("\n");
}


Item GetTop(Heap*heap){
    //返回堆顶的元素
    if(heap->size==0){
        fprintf(stderr,"The heap is empty\n");
        return 0;
    }
    return heap->element[1].data;//堆顶元素在首位
}

//Locate the data in heap
int LocateKey(Heap*heap,int data){
    int site=-1;
    if(heap->size==0){
        site=-1;
        return site;
    }
    //有child 只能通过遍历的方式查找值
    for(int i=0;i<heap->size;i++){
        if(heap->element[i].data==data){
            site=i;
            return site;
        }
    }
    return site;//If the node is not exists in the heap
}


//Decrease the value of key
bool DecreaseKey(Heap *heap,int data,int new_value){
    //查找该值
    int site=LocateKey(heap, data);
    if(site==-1){
        fputs("The value is not exists",stderr);
        return 0;
    }
    else{
        //将该值赋予新的值过后向下调整 因为是最大堆
        PercolateDown(heap,site,new_value);//从新减少值的点向下调整 如果为最小堆的相反
    }
    return 1;
}


//Increase the value of key
bool IncreaseKey(Heap *heap,int data,int new_value){
    //查找该值
    int site=LocateKey(heap, data);
    if(site==-1){
        fputs("The value is not exists",stderr);
        return 0;
    }
    else{
        //将该值赋予新的值过后向上调整 因为是最大堆
        PercolateUp(heap,site,new_value);//从新增加值的点向上调整 如果为最小堆的相反
    }
    return 1;
}



//Delete the key node of the heap
bool DeleteKey(Heap *heap,int data){
    //升高它的优先级 升至堆顶
    if(!IncreaseKey(heap,data,heap->element[1].data+1)){
        return 0;
    }
    //删除堆顶元素 则实现该节点的删除
    Delete(heap);
    return 1;
}

//Percolate down the every root node
Heap* BuildHeap(const Item *Data,int size){
    Heap *heap;
    //先构建Heap
    heap=Initial(heap);
    for(int i=0;i<size;i++){
        heap->element[i+1].data=Data[i];//按照顺序拷贝即可
    }
    heap->size=size;
    //开始调整节点 从含有child的首个root开始
    for(int i=heap->size/2;i>=1;i--){
        PercolateDown(heap,i,heap->element[i].data);//以该处的元素下滤 类似于插入排序
    }
    return heap;
}

Item Find(const Item *Data,int size,int k){
    //以k建堆
    Heap*heap=BuildHeap(Data,k);//建堆
    //循环比对
    for(int i=k;i<size;i++){
        if(heap->element[i-1].data<Data[i]){
            //以新元素上滤
            PercolateDown(heap,k,Data[i]);
        }
    }
    return heap->element[heap->size].data;//末尾元素即是堆
}