//
// Created by 龙舌兰 on 2021/10/19.
//

//
// Created by 龙舌兰 on 2021/10/18.
//

#include "Sort.h"

//辅助函数
static void Adjast(Heap*heap,int index);//调整堆
static void Create(Heap*heap,const Item *Data,int size);//创建堆


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
        //比较左边 如果左child不存在 那么就无需调整了
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
            }
            //二叉堆在使用时理论上是不具备相同元素的 因此在进行堆排序算法中需要对相应的heap进行修改
            //以便其有处理左右元素相等的能力 解决相同的数据
            else if(heap->List[index*2].data==heap->List[index*2+1].data){
                if(heap->List[index].data<heap->List[index*2].data){
                    swap(&heap->List[index].data,&heap->List[index*2].data);
                    index=index*2+1;
                    //向右
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
            //右边不存在
        else if(heap->List[index].data<heap->List[index*2].data){
            swap(&heap->List[index].data,&heap->List[index*2].data);
        }
            //均没有比其大的
        else{
            break;
        }

    }
}




