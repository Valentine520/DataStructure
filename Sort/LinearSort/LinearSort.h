//
// Created by 周龙 on 2021/11/30.
//

#ifndef RADIXSORT_LINEARSORT_H
#define RADIXSORT_LINEARSORT_H
/*
 * 基于数据下标计算的非比较排序
 * 可以对应到hash表的思想
 * 不过该线性排序方法并不具备hash表中的hash函数
 * 而是基于数据的大小进行的插空（桶排序）、计数（计数排序）、多重排序（桶排序）
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 该函数用于计算array中的元素k
 * 这也是线性时间排序的核心所在
 * k决定了桶的长度 决定了计数排序的计数数组的长度
 * 同时决定了基数排序中对不同位置排序的次数
 */
int MaxNum(const int *array,int size);//array中的最大元素k

void ShowArray(int *array,int size);//打印数组元素



/*
 * 计数排序 通过统计元素中小与或等于某元素的个数实现排序
 * 即将含n个子元素的元素大小安置在数组的 n-1 位置（注意长度和下标的换算）
 * 包含两个操作 相同元素的计数和小于元素的计数 分别用两个循环完成
 * 借助两个数组完成线性时间的排序（记得将数组倒回原始数组）
 */
//计数排序 非原址排序 需要满足排序数为k的情况
void CountSort(int *array,int size);//需要计算k

void Count(int *array,int size,int k);//需要知道k


/*
 * 基数排序 借助稳定排序算法对不同数据的不同位进行多次排序
 * 由于每次排序的数据规模都是比较适合使用计数排序等线性稳定排序的
 * 因而基数排序在解决多参数排序问题时的效率较高
 */


//对整数使用基数排序
void RadixSort(int *array,int size);//基数排序

//基数排序过程中使用的稳定排序算法 基于计数排序
void Mysort(int *array,int m,int size);




/*
 * 桶排序 定义桶的数据结构 和Hash表的链地址法解决冲突类似
 * 桶包含自身的数据（统计卫星数据的个数）和指向卫星数据的指针
 * 其中对相同桶中的元素进行插入排序 (对双向链表进行插入排序）
 * 对不同桶中的元素应用顺序合并方法使其桶外有序
 */

typedef struct Node{
    int data;
    struct Node *next,*pre;//双指针的链表
}Node,*Link;


//桶排序 适用于元素均匀分布都情况
void BucketSort(int *array,int size);

//插入元素到桶中
void InsertBucket(Link node,int data);

//桶排序算法的辅助函数 对相同桶中的元素进行插入排序
void BucketInsertSort(Link node);



//表排序 适用于对大型数据进行排序 虚假排序
void TableSort(int *array,int size);


#endif //RADIXSORT_LINEARSORT_H
