// Created by 周龙 on 2021/11/19.

#ifndef LINKHASH_LINKHASH_H
#define LINKHASH_LINKHASH_H

/*
 * 使用链地址法解决hash冲突
 * Hash函数和OpenHash中类似
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MINIMIZE 32768
typedef struct Link{
    int data;
    struct Link *next,*p;//用双向链表的方法易于删除
}node,*Link;

typedef struct Hash{
    int size;
    Link data;//使用链表存储key相同的数据 解决冲突
}hashtable,*Hash;

typedef _Bool bool;

//关键的是hash函数的设置 和hash大小的选取 根据length选取大小
Hash Initial(int n);

//计算最接近n的素数 用于确定hash表的size
int SimpleNumber(int n);

//用来判断数是否是素数 使用数字6的定理计算
int IsSimpleNumber(int N);

//哈希函数 用于计算散列值 除法
int HashFunction_D(Hash T,int key);

//乘法版本hash函数 具体见算法导论
int HashFunction_M(Hash T,int key);

void Insert(Hash T,int data);

Link Search(Hash T,int data);

bool Delete(Hash T,int data);

//生成新的节点
Link NewNode(int data);

//打印节点信息
void Traverse(Hash T);

#endif //LINKHASH_LINKHASH_H
