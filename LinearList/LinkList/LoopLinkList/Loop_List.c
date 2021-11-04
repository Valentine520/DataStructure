//
// Created by 龙舌兰 on 2021/9/22.
//
#include "Loop_List.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//初始化链表
bool Initial(Loop_List**L){
    int flag=1;
    //申请头节点 判断是否申请失败
    if(((*L)=(Loop_List*) malloc(sizeof(Loop_List)))==NULL){
        flag=0;
        return flag;
    };
    (*L)->Next=(*L);//指向自己 作为结束标记
    //尾指针指向头节点
    (*L)->data=(Item){0};//为空
    return flag;
}

//是否空
bool ListEmpty(Loop_List*L){
    bool judge=0;
    if(L->data.data==0){
        judge=1;
    }
    return judge;
}

int ListLength(Loop_List*L){
    int length=0;
    Loop_List *temp=L->Next->Next;//从尾指针指向的头节点开始
    //如果回到头节点则遍历完成
    while(temp!=L->Next){
        length++;
        temp=temp->Next;
    }
    return length;
}

//每次插入都需要改变尾指针的指向
bool Insert_Elem(Loop_List**L,int index,Item data){
    bool flag=1;
    int List_length= ListLength(*L);

    //Invalid index
    if(index<=0||index>List_length+1){
        flag=0;
        fprintf(stderr,"Invalid Index.\n");
        return flag;
    }
    Loop_List *temp=(*L)->Next;//temp从头节点开始
    //查找前驱和后继
    for(int i=0;i<index-1;i++){
        temp=temp->Next;
    }
    Loop_List *New_Node=(Loop_List*) malloc(sizeof(Loop_List));//申请新的节点
    New_Node->data=data;//赋值
    //不能这样判断 要分隔出尾指针和头节点!!!
    //判断是否在尾部插入 如果是 则改变尾指针的指向
    if(temp==*L){
        New_Node->Next=(*L)->Next;//指向头节点
        (*L)->Next=New_Node;
        (*L)=New_Node;//改变L的指向 尾指针
    }
    //如果不是 则无需更改尾指针的指向 只改变逻辑线性关系即可
    else{
        New_Node->Next=temp->Next;
        temp->Next=New_Node;
    }
    (*L)->Next->data.data++;//头节点
    return flag;
}

//int Locate_Elem(Loop_List*L);//定位链表中的指定元素
//
//bool Delete_Elem(Loop_List*L);//删除指定位置的元素(仅有存在malloc的修改才需要使用地址传递，即二级指针去接收）
//
//void List_Clear(Loop_List*L);//清空整个链表

//遍历整个链表
bool Traverse(Loop_List*L) {
    bool flag = 1;
    if (ListEmpty(L)) {
        fprintf(stderr, "List is empty.\n");
        flag = 0;
        return flag;
    }
    Loop_List *temp=L->Next->Next;//第一个节点
    //以头节点作为结束条件
    while(temp!=(*L).Next){
        printf("%d ",temp->data.data);
        temp=temp->Next;
    }
    putchar('\n');
    return flag;
}

//查找指定的元素
int Locate_Elem(Loop_List*L,Item data){
    int site=0;//不存在
    Loop_List *temp=L->Next->Next;//创建临时节点 指向第一个节点（非头节点）
    while(temp!=L->Next){
        site++;
        if(temp->data.data==data.data){
            return site;
        }
        temp=temp->Next;
    }
    site=-1;//元素不存在
    return site;
}

bool Delete_Elem(Loop_List**L,int index){
    bool flag=1;
    if(index<=0||index>ListLength(*L)){
        flag=0;
        fprintf(stderr,"Invalid index.\n");
        return flag;
    }
    Loop_List *temp=(*L)->Next;//头节点开始
    //查找前驱
    for(int i=0;i<index-1;i++){
        temp=temp->Next;
    }
    Loop_List *L_temp=temp->Next;//保存节点
    //是否删除尾节点 涉及到尾指针的移动
    // !!!尾指针的移动很关键
    if(index== ListLength(*L)){
        temp->Next=temp->Next->Next;
        //修改指针的指向
        (*L)=temp;//指向新的尾节点
    }
    else{
        //直接删除修改即可 无需关心尾指针
        temp->Next=temp->Next->Next;
    }
    //释放待删除的节点
    free(L_temp);
    (*L)->Next->data.data--;
    return flag;
}

void List_Clear(Loop_List**L){
    while((*L)->Next->data.data!=0){
        Delete_Elem(L,1);
    }
}

//合并到L2上 合并的使用使用三杯水法进行地址的交换 避免前一次交换对下一次交换造成的影响
//
void List_Merge(Loop_List**L1,Loop_List**L2){
    int length1=(*L1)->Next->data.data;
    int length2=(*L2)->Next->data.data;
    Loop_List *temp=(*L2)->Next;//释放L2表的头节点
    Loop_List *temp2=(*L2)->Next->Next;
    (*L2)->Next=(*L1)->Next;
    (*L1)->Next=temp2;
    (*L2)->Next->data.data=length1+length2;
    free(temp);
}
