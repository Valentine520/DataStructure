//
// Created by 龙舌兰 on 2021/9/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "Double_Linked_List.h"
bool Initial(Double_List**L){
    bool flag=1;
    //创建头节点
    (*L)=(Double_List*) malloc(sizeof(Double_List));
    if((*L)==NULL){
        flag=0;
        fprintf(stderr,"Can't malloc the space.\n");
        return flag;
    }
    (*L)->next=(*L);
    (*L)->prior=(*L);
    (*L)->data=0;//空
    return flag;
}

bool ListEmpty(Double_List*L){
    bool flag=0;
    if(L->next==L->prior){
        flag=1;
    }
    return flag;
}

bool Insert(Double_List*L,int index,Item data){
    bool flag=1;
    Double_List *temp=L;
    if(index<=0||index>L->data+1){
        flag=0;
        fprintf(stderr,"Invalid index.\n");
        return flag;
    }
    Double_List *New_Node=(Double_List*) malloc(sizeof(Double_List));
    //找前驱
    for(int i=0;i<index-1;i++){
        temp=temp->next;
    }
    New_Node->data=data;
    New_Node->next=temp->next;
    New_Node->prior=temp;
    //改变前驱指针和后继指针
    temp->next->prior=New_Node;
    temp->next =New_Node;
    L->data+=1;
    return flag;
}

void Traverse(Double_List*L){
    Double_List *temp=L->next;
    while(temp!=L){
        //不等于头节点
        printf("%2d ",temp->data);
        temp=temp->next;
    }
    putchar('\n');
}