//
// Created by 周龙 on 2021/11/30.
//

#include "LinearSort.h"

//打印数组的元素
void ShowArray(int *array,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    putc('\n',stdout);
}

//寻找数组中的最大值
int MaxNum(const int *array,int size){
    int max = array[0];
    for(int i=1;i<size;i++){
        if(array[i]>max){
            max = array[i];
        }
    }
    return max;
}
//计数排序
void CountSort(int *array,int size){
    int k = MaxNum(array, size);
    printf("%d\n",k);
    Count(array,size,k);
}

void Count(int *array,int size,int k){
    //申请k大小的空间记录array的数据相同的次数
    int buf[k+1];
    int B[size];
    //注意对边界条件的判断 该处buf中的i应该最多能取到k 即该数组中的最大元素
    for(int i=0;i<=k;i++){
        buf[i] = 0;
    }
    //处理元素中的相同元素
    for(int i=0;i<size;i++){
        buf[array[i]]++;//相同元素自增
    }
    //Less and Equal 计数
    for(int i=1;i<=k;i++){
        buf[i]+=buf[i-1];
    }
    //从size-1开始保证原来最后的（count大）在后面 即保证算法是稳定的
    for(int i=size-1;i>=0;i--){
        B[buf[array[i]]-1]=array[i];//按照计数去安置元素的位置
        buf[array[i]]--;//消除相同元素
    }
    //将元素拷贝回原数组
    for(int i=0;i<size;i++){
        array[i] = B[i];
    }
}

//基数排序
void RadixSort(int *array,int size){
    //同样查找最大元素k 以k的元素规模确定排序次数
    int k = MaxNum(array,size);
    int i=1;
    //边界条件要找准 是在k为0后才停止 k如果为个位数表示还可以进行最高位的比较
    while(k>=1){
        Mysort(array,i,size);//需要使用稳定排序 针对每次的基数进行排序
        i*=10;
        k/=10;//每次让k/10 代表其中的最高位数/10
    }
}


//以i指定的方法分割位数 i为1 n/i%10 即可
//对不同的位进行计数排序 以达到排序整个大型数据的效果
void Mysort(int *array,int m,int size){
    int k=10;//基数决定了数据最大为9
    //申请k大小的空间记录array的数据相同的次数
    int buf[k+1];
    int *B = (int*)malloc(sizeof(int)*size);
    //注意对边界条件的判断 该处buf中的i应该最多能取到k 即该数组中的最大元素
    for(int i=0;i<=k;i++){
        buf[i] = 0;
    }
    for(int i=0;i<size;i++){
        buf[array[i]/m%10]++;//元素自增
    }
    //Less and Equal 计数
    for(int i=1;i<=k;i++){
        buf[i]+=buf[i-1];
    }
    for(int i=size-1;i>=0;i--){
        B[buf[(array[i]/m%10)]-1]=array[i];//按照计数去安置元素的位置
        buf[array[i]/m%10]--;//消除相同元素
    }
    for(int i=0;i<size;i++){
        array[i] = B[i];
    }
    free(B);
}




//桶排序
void BucketSort(int *array,int size){
    //建立含有元素的桶
    //仍然是用K进行建桶
    int k = MaxNum(array,size);
    Link Bucket = (Link) malloc(sizeof (Node)*k);//建立规模为k的桶
    for(int i=0;i<k;i++){
        Bucket[i].data=0;//记录是否有元素
        Bucket[i].next=NULL;
        Bucket[i].pre=NULL;
    }
    for(int i=0;i<size;i++){
        InsertBucket(&Bucket[array[i]%10],array[i]);//向桶中插入元素
    }
    //桶中元素排序后取出
    //对相同桶中元素进行插入排序
    for(int i=0;i<size;i++){
        BucketInsertSort(Bucket[i].next);
    }
    int site = 0;
    for(int i=0;i<k,site<size;i++){
        Link node = Bucket[i].next;
        while(node != NULL){
            array[site++] = node->data;
            node = node->next;
        }
    }
}



//向桶中插入数据
void InsertBucket(Link node,int data){
    //直接头插 在插入后实现排序
    Link NewNode = (Link) malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->next = node->next;
    //是否为空 避免操纵空指针
    if(node->next!=NULL){
        node->next->pre=NewNode;
    }
    node->next = NewNode;
    NewNode->pre=node;
}


void BucketInsertSort(Link L){
    if(L==NULL||L->next==NULL){
        return;//只有一个元素无需排序
    }
    Link head = L->pre;//头节点
    Link node = L->next;//待排序的首个数组
    Link pre ;
    while(node!=NULL){
        pre = node->pre;
        Link temp=NULL;
        while(pre!=head){
            if(pre->data > node->data){
                pre=pre->pre;//向前
            }
            else{
                break;
            }
        }
        temp = node->next;
        node->pre->next=node->next;
        if(node->next!=NULL){
            node->next->pre=node->pre;
        }
        node->next=pre->next;//链接上node
        if(pre->next!=NULL){
            pre->next->pre=node;
        }
        pre->next = node;
        node->pre = pre;
        node = temp;
    }
}