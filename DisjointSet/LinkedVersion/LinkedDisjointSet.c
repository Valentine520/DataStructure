//
// Created by 周龙 on 2021/11/22.
//

#include "LinkedDisjointSet.h"
//以data为节点构建集合
Set MakeSet(int data){
    Set Item=(Set) malloc(sizeof(Node));
    Item->data=data;
    Item->font=(Head*) malloc(sizeof(Head));
    Item->next=NULL;
    Item->font->tail=Item->font->head=Item;
    Item->font->size=1;
    return Item;
}

//归并两个集合
void Union(Set set1,Set set2){
    //在同一个集合中则无需归并
    if(Find(set1,set2)){
        return;
    }
    if(set1->font->size>=set2->font->size){
        if(set1->font->size==set2->font->size){
            set1->font->size++;//而后再归并
        }
        //假设set2归并到set1上
        set1->font->tail->next=set2;
        set1->font->tail=set2->font->tail;
        Set temp=set2;
        while(temp!=NULL){
            temp->font=set1->font;//只需要修改头指针的指向就可以了
            temp=temp->next;
        }
    }
    else{
       //将1归并到2
        set2->font->tail->next=set1;
        set2->font->tail=set1->font->tail;
        Set temp=set1;
        while(temp!=NULL){
            temp->font=set2->font;//只需要修改头指针的指向就可以了
            temp=temp->next;
        }
   }
}

//查找两个节点是否同属于一个集合
bool Find(Set node1,Set node2){
    //可以在线性时间内得到结果
    if(node1->font==node2->font){
        return 1;
    }
    else{
        return 0;
    }
}