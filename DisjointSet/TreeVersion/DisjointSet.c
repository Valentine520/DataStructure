//
// Created by 周龙 on 2021/11/23.
//

#include "DisjointSet.h"

//初始化并查集
Set MakeSet(int data){
    Set Item=(Set)malloc(sizeof(Node));
    Item->rank=0;
    Item->data=data;
    Item->parent=Item;//指向自己
    return Item;
}

//查找节点内容
Set FindSet(Set set){
    if(set!=set->parent){
        set->parent= FindSet(set->parent);
    }
    return set->parent;//保证每次都返回root 为查找的路径进行压缩
}

//合并集合
void Union(Set set1,Set set2){
    Set parent1= FindSet(set1);
    Set parent2= FindSet(set2);
    if(parent1!=parent2){
        if(set1->rank>set2->rank){
            parent2->parent=parent1;//合并到set1上
        }
        else{
            parent1->parent=parent2;//合并到set2上
            //如果二者rank相等 则令其中rank+1
            if(set1->rank==set2->rank){
                set2->rank++;
            }
        }
    }
}