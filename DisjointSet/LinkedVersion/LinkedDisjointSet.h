//
// Created by 周龙 on 2021/11/22.
//

#ifndef LINKEDJOINTSET_LINKEDDISJOINTSET_H
#define LINKEDJOINTSET_LINKEDDISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>
typedef _Bool bool;
/*
 * 并查集的链表表示方式
 * 使用next和head指针维护next和represent
 * head指针指向的head包含一个head指针 指向represent元素
 * 同时包含一个tail指针 指向末尾的元素
 * 基于head一个size进行数据结构的扩张
 * 基于union操作一种加权合并的启发式算法
 */
struct Head;
typedef struct DisjointSet{
    struct DisjointSet * next;//指向下一个元素
    struct Head* font;//指向头节点的指针
    int data;//节点数据
}*Set,Node;

typedef struct Head{
    int size;//记录大小
    Set head;//指向头
    Set tail;//指向尾
}Head;

//以data为节点构建集合
Set MakeSet(int data);

//归并两个集合
void Union(Set set1,Set set2);

//查找两个节点是否同属于一个集合
bool Find(Set node1,Set node2);



#endif //LINKEDJOINTSET_LINKEDDISJOINTSET_H
