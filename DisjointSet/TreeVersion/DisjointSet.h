//
// Created by 周龙 on 2021/11/23.
//

#ifndef DISJOINTSET_DISJOINTSET_H
#define DISJOINTSET_DISJOINTSET_H
/*
 * 使用树形结构实现disjoint set
 * 同时采用压缩路径和按秩合并操作使树高度降低
 * 令find、union等操作变得快速、便捷
 */
#include <stdlib.h>
#include <stdio.h>
typedef _Bool bool;

typedef struct DisjointSet{
    struct DisjointSet*parent;//指向parent的指针
    int rank;
    int data;
}*Set,Node;

//初始化并查集
Set MakeSet(int data);

//查找节点内容 路径压缩
Set FindSet(Set set);

//合并集合 按秩合并
void Union(Set set1,Set set2);


#endif //DISJOINTSET_DISJOINTSET_H
