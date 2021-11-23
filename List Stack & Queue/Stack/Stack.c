//
// Created by 龙舌兰 on 2021/9/23.
//
#include "STACK.h"
#include <stdlib.h>
#include <stdio.h>
//栈的初始化
bool Initial_Stack(Stack*S){
    bool flag=1;
    S->data=(Item*) malloc(sizeof(Item)*BASE_LENGTH+1);//初始化为基础长度
    if(S->data==NULL){
        flag=0;
        fprintf(stderr,"Fail to allocate the memory.\n");
        return flag;
    }
    S->base=S->data;
    S->top=S->data;//空表
    S->Stack_Size=BASE_LENGTH;//初始容量
    return flag;
}

bool Stack_Empty(const Stack*S){
    bool flag=0;
    if(S->base==S->top){
        flag=1;
        return flag;
    }
    return flag;
}

bool Stack_Full(const Stack*S){
    bool flag=0;
    const Item *temp=S->top;
    int index=0;
    while(temp!=S->base){
        temp--;
        index++;
    }
    if(index>=S->Stack_Size){
        flag=1;
    }
    return flag;
}

//删除栈
void Destroy_Stack(Stack*S){
    free(S->data);//删除分配的内存空间
    S->data=NULL;
    S->base=NULL;
    S->top=NULL;
    S->Stack_Size=0;
    //栈还在 只是被清空了
    Initial_Stack(S);//重新初始化
}

//清空栈
bool Clear_Stack(Stack*S){
    int flag=1;
    if(S==NULL){
        //如果栈根本不存在
        flag=0;
        fprintf(stderr,"The stack is not exist.\n");
        return flag;
    }
    free(S->data);//删除分配的内存空间
    //可要可不要
    S->data=NULL;
    S->base=NULL;
    S->top=NULL;
    S->Stack_Size=0;
    Initial_Stack(S);
    return flag;
}

//栈的长度
int Stack_Length(const Stack*S){
    int index=0;
    if(S==NULL){
        index=-1;
        fprintf(stderr,"The Stack is not exist.\n");
        return index;
    }
    const Item *temp=S->top;
    while(temp!=S->base){
        temp--;
        index++;
    }
    return index;
}

//访问栈顶元素
Item Get_Top(const Stack*S){
    Item data=(Item){-1};
    if(Stack_Empty(S)){
        fputs("The Stack is empty.\n",stderr);
        return data;
    }
    data=*(S->top-1);
    return data;
}

//压入栈
void Push(Stack*S,Item item){
    *(S->top)=item;
    (S->top)++;
    //表满 分配更大的空间
    if(Stack_Full(S)){
        S->data= realloc(S,S->Stack_Size+MORE_LENGTH+1);
    }
}

//弹出栈 不显示其值
bool Pop(Stack*S){
    bool flag=1;
    if(Stack_Empty(S)){
        flag=0;
        fprintf(stderr,"Error.\n");
        return flag;
    }
    *(S->top)=(Item){0};
    S->top--;
    return flag;
}

//遍历栈的数据
void Traverse_Stack(const Stack*S,void (*Visit)(Item*)){
    Item *temp=S->top;
    while(temp!=S->base){
        temp--;
        Visit(temp);
    }
    putchar('\n');
}

void Visit(Item*Data){
    printf("%d ",Data->data);
}
