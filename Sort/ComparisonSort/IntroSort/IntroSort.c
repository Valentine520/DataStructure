//
// Created by 周龙 on 2021/12/1.
//


#include "IntroSort.h"



//对外的接口
void IntroSort(int *array, int size) {
    Intro(array, 0, size - 1);
}

void Intro(int *array, int left, int right) {
    if (right - left + 1 > LIMIT2) {
        //添加阈值
        while (left < right) {
            int p = RandomParting(array, left, right);
            //p为主元的位置 主元的位置无需改变
            Intro(array, left, p - 1);
            left = p + 1;//向右递归
        }
    } else if(right-left+1 > LIMIT1) {
        int buf [right-left+1];
        for(int i=0;i<=right;i++){
            buf[i] = array[i+left];
        }
        HeapSort(buf,right-left+1);//堆排序
        for(int i=0;i<=right;i++){
            array[i+left] = buf[i];
        }
    }
    else{
        InsertSort(array,left,right);//插入排序
    }
}

//为该区间以right作为主元进行划分
int Parting(int *array, int left, int right) {
    //取最右侧数据为pivot
    int pivot = array[right];
    //划分pivot左右两边的数据
    int i = left - 1, j = left;//令i为left-1开始 可以避免极端情况
    for (; j < right; j++) {
        //如果小于左元则和i交换 令i+1处永远都是大于主元的数据
        if (array[j] < pivot) {
            i++;
            Swap(&array[j], &array[i]);
        }
    }
    Swap(&array[i + 1], &array[right]);//不能直接拿pivot交换 而要改变right的数据
    return i + 1;//i+1则是pivot所在的位置
}


//利用随机函数划分主元
int RandomParting(int *array, int left, int right) {
    //生成left到right之间左开右闭区间的随机数
    //如果和边界相等又该如何
    //不存在right == left 的情况
    int site = rand() % (right - left) + left + 1;//如果遇到right和left相等的情况 这样取值就会error
    if (site > right || site < left) {
        fprintf(stderr, "This random number is wrong\n");
    }
    //保证最右侧数据为pivot
    if (array[left] > array[right]) {
        Swap(&array[left], &array[right]);
    }
    if (array[left] > array[site]) {
        Swap(&array[left], &array[site]);
    }
    if (array[site] > array[right]) {
        Swap(&array[site], &array[right]);
    }
    Swap(&array[site], &array[right]);//交换right和site的位置
    int pivot = array[right];
    //划分pivot左右两边的数据
    int i = left - 1, j = left;//令i为left-1开始 可以避免极端情况
    for (; j < right; j++) {
        //如果小于左元则和i交换 令i+1处永远都是大于主元的数据
        if (array[j] < pivot) {
            i++;
            Swap(&array[j], &array[i]);
        }
    }
    Swap(&array[i + 1], &array[right]);//不能直接拿pivot交换 而要改变right的数据
    return i + 1;//i+1则是pivot所在的位置
}





void InsertSort(int *array, int left, int right) {
    int temp;
    for (int i = left + 1; i <= right; i++) {
        temp = array[i];
        int j = i - 1;
        for (; j >= left; j--) {
            if (array[j] > temp) {
                array[j + 1] = array[j];
            } else {
                break;
            }
        }
        array[j + 1] = temp;//空穴位置
    }
}

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
        if ((i + 1) % 10 == 0) {
            putchar('\n');
        }
    }
    putchar('\n');
}