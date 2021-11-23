//
// Created by 龙舌兰 on 2021/9/21.
//
#include "Static_List.h"
#include <stdio.h>
#include <stdlib.h>
//一张表中包含两张表 已用表和可用表
bool Initial(Static_List**L){
    bool flag=1;
    *L=(Static_List*)malloc(sizeof(Static_List)*MAXSIZE);//必须使用二级指针进行操作
    //申请内存空间是否成功
    if(*L==NULL){
        flag=0;
        return flag;
    }
    //index 0 作为已用表的头节点
    //index 1 则作为可用表的头节点

    (*L)[0].elem=(Item){0};//使用结构体字面量赋值
    (*L)[0].index=-1;//作为结束标记 表示该数组空
    //剩余表
    for(int i=1;i<MAXSIZE;i++){
        (*L)[i].index=i+1;
    }
    //剩余可用空间
    (*L)[1].elem=(Item){MAXSIZE-2};
    return flag;
}

bool ListFull(Static_List*L){
    bool flag=0;
    //剩余表如果没有内容 则表示表满
    if(L[1].elem.data<=0){
        flag=1;
    }
    return flag;
}

bool Insert(Static_List**L,int index,Item data){
    bool flag=1;
    //判断插入的位置是否合法（头和末尾）
    if(index<0||index>L[0]->elem.data+1){
        fputs("Invalid index.\n",stderr);
        //插入非法
        flag=0;
        return flag;
    }
    //判断是否满
    if(ListFull(*L)){
        flag=0;
        fprintf(stderr,"List is full.\n");
        return flag;
    }
    //从剩余表中取出结点
    //修改剩余节点表 修改一定需要使用地址传递
    int R_index=(*L)[1].index;//取出待用节点
    (*L)[1].index=(*L)[R_index].index;//修改余节点表 从头部取
    (*L)[1].elem.data--;

    //处理节点
    (*L)[R_index].elem.data=data.data;//放入指定的位置

    int prior_index=0;
    //从表中找到插入的位置 修改逻辑下标

    //查找插入点的前驱 修改
    for(int i=0;i<index-1;i++){
        prior_index=(*L)[prior_index].index;//相当于指针的移动
    }
    (*L)[R_index].index=(*L)[prior_index].index;
    (*L)[prior_index].index=R_index;
    (*L)[0].elem.data++;
    return flag;
}

//使用一级指针直接完成插入
bool Insert2(Static_List*L,int index,Item data){
    bool flag=1;
    //判断插入的位置是否合法（头和末尾）
    if(index<0||index>L[0].elem.data+1){
        fputs("Invalid index.\n",stderr);
        //插入非法
        flag=0;
        return flag;
    }
    //判断是否满
    if(ListFull(L)){
        flag=0;
        fprintf(stderr,"List is full.\n");
        return flag;
    }
    //从剩余表中取出结点
    //修改剩余节点表 修改一定需要使用地址传递
    int R_index=(L)[1].index;
    (L)[1].index=(L)[R_index].index;//修改余节点表
    (L)[1].elem.data--;

    //处理节点
    (L)[R_index].elem.data=data.data;//放入指定的位置

    int prior_index=0;
    //从表中找到插入的位置 修改逻辑下标
    //查找插入点的前驱
    for(int i=0;i<index-1;i++){
        prior_index=(L)[prior_index].index;
    }
    (L)[R_index].index=(L)[prior_index].index;
    (L)[prior_index].index=R_index;
    (L)[0].elem.data++;
    return flag;
}

void Traverse(Static_List*L){
    int index=L[0].index;//头节点
    //以-1的末尾索引当作结束标记
    while(index!=-1){
        printf("%2d ",L[index].elem.data);
        index=L[index].index;
    }
    putchar('\n');
}

bool ListEmpty(Static_List*L){
    bool flag=0;
    if(L[0].elem.data==0){
        flag=1;
    }
    return flag;
}

bool ListExit(Static_List*L){
    bool judge=1;
    if(L==NULL){
        judge=0;
    }
    return judge;
}


//剩余可用空间的内容
void Remaining(Static_List*L){
    int index=L[1].index;//起始位置
    for(int i=0;i<L[1].elem.data;i++){
        printf("%d\n",index);
        index=L[index].index;//下一个位置
    }
}

bool Delete(Static_List**L,int index){
    bool judge=1;
    if(index<=0||index>(*L)[0].elem.data+1){
        judge=0;
        fprintf(stderr,"Invalid index.\n");
        return judge;
    }
    int prior_index=0;
    //查找前驱
    for(int i=0;i<index-1;i++){
        prior_index=(*L)[prior_index].index;
    }
    //更新内容表
    (*L)[(*L)[prior_index].index].elem=(Item){0};
    (*L)[prior_index].index=((*L)[(*L)[prior_index].index].index);

    //更新节点表 插入头部 下次直接使用
    (*L)[index+1].index=(*L)[1].index;
    (*L)[1].index=index+1;

    (*L)[0].elem.data--;
    (*L)[1].elem.data++;

    return judge;
}

//合并链表
void Merge(const Static_List*L1,const Static_List*L2,Static_List*L3,int (*compare)(Item data1,Item data2)){
    int index1,index2,index3;
    index1=L1[0].index;
    index2=L2[0].index;
    index3=1;
    while(index1!=-1&&index2!=-1){
        switch (compare(L1[index1].elem,L2[index2].elem)) {
            //L1.elem > L2.elem
            case 1:{
                Insert2(L3,index3,L2[index2].elem);
                //更新下标索引
                index3++;
                index2=L2[index2].index;
                break;
            }
            //L2.elem >= L1.elem
            case -1:
            case 0:{
                Insert2(L3,index3,L1[index1].elem);
                //更新下标索引
                index3++;
                index1=L1[index1].index;
                break;
            }
            default:
                fprintf(stderr,"Error!.\n");
                exit(EXIT_FAILURE);
        }
    }
    while(index2!=-1){
        Insert2(L3,index3,L2[index2].elem);
        //更新下标索引
        index3++;
        index2=L2[index2].index;
    }
    while(index1!=-1){
        Insert2(L3,index3,L1[index1].elem);
        //更新下标索引
        index3++;
        index1=L1[index1].index;
    }
}

//辅助函数
int compare(Item data1,Item data2){
    int flag;
    if(data1.data>data2.data){
        flag=1;
    }
    else if(data2.data==data1.data){
        flag=0;
    }
    else{
        flag=-1;
    }
    return flag;
}