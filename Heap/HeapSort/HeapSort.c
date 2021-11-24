#include "HeapSort.h"


void HeapSort(int *Data,int size){
    //以数组元素建堆
    BuildHeap(Data,size);
    //每次取出堆顶元素 取size-1次 交换最后一个元素的位置
    int temp=size;
    for(int i=0;i<temp-1;i++){
        Swap(&Data[0],&Data[size-1]);
        size-=1;
        PercolateDown(Data,1,size);
    }
}

void Swap(int *num1,int *num2){
    int temp=*num1;
    *num1=*num2;
    *num2=temp;
}

//Percolate down the every root node
void BuildHeap(int *heap,int size){
    //开始调整节点 从含有child的首个root开始
    for(int i=(size+1)/2;i>=1;i--){
        PercolateDown(heap,i,size);//以该处的元素下滤 类似于插入排序
    }
}

//需要加入边界判断值 删除前是否为空 为空则无法删除  percolate down
void PercolateDown(int*heap,int index,int size){
    //size是边界值 直接使用size传入实则是在原可访问区域+1 则无需+1处理
    int child;
    int i;
    int data=heap[index-1];
    for(i=index;i*2<=size;i=child){
        child=i*2;//i的child
        if(child+1<=size&&heap[child-1]<heap[child]){
            child++;//右侧节点存在且大于左侧 则更新child为待移动节点
        }
        if(heap[child-1]>data){
            heap[i-1]=heap[child-1];//赋值为自己的最大child
        }
        else{
            break;
        }
    }
    //确保for外部就是待插入的位置
    heap[i-1]=data;
}


void ShowArray(const int *array,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    putchar('\n');
}