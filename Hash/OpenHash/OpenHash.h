//
// Created by 周龙 on 2021/11/19.
//

#ifndef HASH_OPENHASH_H
#define HASH_OPENHASH_H
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
//定义两个内容分别代表空和已删除过 遇到已删除过的节点在查找时可以继续向后
//遇到空则直接表示查找失败
//在插入时 这两者都等效视为该处没有内容
#define MINIMIZE -256788
#define DELETE -1

typedef struct Hash{
    int size;
    int *data;
}hashtable,*Hash;

typedef _Bool bool;

//关键的是hash函数的设置 和hash大小的选取 根据length选取大小
Hash Initial(int n);

//计算最接近n的素数 用于确定hash表的size
int SimpleNumber(int n);

//哈希函数 用于计算散列值 除法
int HashFunction_D(Hash T,int key);

//乘法版本hash函数 具体见算法导论
int HashFunction_M(Hash T,int key);

//Linear Addressing
int Locate_L(Hash T,int site);

//Square Addressing
int Locate_S(Hash T,int site);

//Multiple Addressing
int Locate_M(Hash T,int site);

//Insert the data into hash table
bool Insert(Hash T,int data);

//Search the data in hash table
int Search(Hash T,int data);

//Delete the data from hash table
bool Delete(Hash T,int data);

#endif //HASH_OPENHASH_H
