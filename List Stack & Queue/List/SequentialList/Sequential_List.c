//
// Created by 龙舌兰 on 2021/9/18.
//
//在源文件中实现ADT接口
#include <stdio.h>
#include <stdlib.h>
#include "Sequential_List.h"

//#define LIST_INITIAL_SIZE 100//定义数组的初始储存空间大小

//如果需要改变线性表中的内容 则使用指针传入 否则使用结构体传入即可 避免不必要的修改 但随之而来的内存开销是非常大的
bool Initial(S_map*L){
    int flag=1;
//    L=(S_map*) malloc(sizeof(S_map));//为其分配一块内存空间  改变了指向
    //进行初始化
    (L)->item=(Item*) malloc(sizeof(Item)*LIST_INITIAL_SIZE); //定义数组的初始储存空间
    (L)->length=0;//数组长度为0
    (L)->size=LIST_INITIAL_SIZE;//数组存储空间为LIST_INITIAL_SIZE 100
    //判断是否创建成功
    if((L)->item==NULL){
        flag=0;
    }
    return flag;
}//初始化一个空的线性表L

bool DestroyList(S_map*L){
    int flag=0;
    if(L!=NULL){
        free(L);//释放申请的内存空间
        flag=1;
    }
    L=NULL;//置为空
    printf("Destroy Success!\n");
    return flag;
};//销毁创建的线性表 (真正意义上的销毁初始化创建的线性表) 返回值表示是否删除成功

//清空线性表 （仅仅只是把线性表中存储的内容置空而已 但线性表仍然存在）
bool ClearList(S_map*L){
    int flag=0;
    if(L!=NULL&&L->item!=NULL){
        free(L->item);//释放创建的内存空间
        flag=-1;
    }
    L->length=0;
    return flag;
}

//线性表是否空 1则空 0则非空
bool ListEmpty(S_map L){
    int flag=0;
    if(L.length==0){
        flag=1;
    }
    return flag;
}

//线性表是否满 1则满 0则未满
bool ListFull(S_map L){
    int flag=0;
    if(L.length==L.size){
        flag=1;
    }
    return flag;
}

int ListLength(S_map L){
    return L.length;
};//获取线性表的长度

Item GetElem(S_map L,int index){
    if(index<0&&index>L.length){
        fprintf(stderr,"Invalid index.\n");
        exit(EXIT_FAILURE);
    }
    return L.item[index];
};//获取指定位置的数据 (如果指定的位置不合法，即为负值或超出数组的当前数据上限）

//利用compare指定的比较函数的函数指针 进行Elem的定位
int LocateElem(S_map L,Item data,bool (*compare)(Item data1,Item data2) ){
    int site=-1;
    for(int i=0;i<L.length;i++){
        if(compare(data,L.item[i])){
            site=i;
            break;
        }
    }
    return site;
}

//如果data是S_map中的数据 且不是第一个 则返回其前驱
Item PriorElem(S_map L,Item data){
   int index= LocateElem(L,data,compare);
   if(index!=-1&&index!=0){
       return L.item[index-1];
   }
   else{
       fprintf(stderr,"Invalid input.\n");
       exit(EXIT_FAILURE);
   }
}

Item NextElem(S_map L,Item data){
    int index= LocateElem(L,data,compare);
    if(index!=-1&&index!=L.length-1){
        return L.item[index+1];
    }
    else{
        fprintf(stderr,"Invalid input.\n");
        exit(EXIT_FAILURE);
    }
}//如果data是S_map中的数据 且不是最后一个 则返回其后继

bool ListInsert(S_map *L,int index,Item data){
    bool flag=1;
    if(ListEmpty(*L)){
        L->item[0]=data;
        L->length++;
    }
    else {
        //插入数据的时候涉及到数组的移动 从尾部开始
        //不合法的插入位置
        if (index < 0 && index > L->length) {
            flag = 1;
            fputs("Invalid input.\n", stderr);
            return flag;
        }
        if (L->length + 1 >= L->size) {
            //如果内存空间满 则为其重新分配一块内存空间 (向后移动后的存储空间)
            L->item = realloc(L->item, sizeof(Item) * LISTINCREMENT + L->size);//在L的内存基础上增加
            L->size += LISTINCREMENT;//更新线性表的内容
            //判断是否重新分配成功
            if (L->item == NULL) {
                flag = 0;
            }
        };

        //开始插入数据
        //从最后一个位置后移一位开始，直到插入位置
        int site=L->length-1;
        while (index <= site) {
            L->item[site + 1].data = L->item[site].data;
            site--;
        }
        L->item[index] = data;//插入数据
        L->length++;//长度增加
    }
    return flag;
}//向线性表中指定的位置插入数据 如果插入失败 则返回0

//删除线性表中的指定元素
bool ListDelete(S_map *L,int index){
    int flag=1;
    if(ListEmpty(*L)){
        fprintf(stderr,"The sequential map is empty.\n");
        flag=0;
        return flag;
    }
    if(index<0&&index>L->length-1){
        fprintf(stderr,"Invalid index.\n");
        flag=0;
        return flag;
    }
    while(index++<L->length-1){
        //移动位置 拷贝内容
        L->item[index]=L->item[index+1];
    }
    L->length--;//长度缩短
    return flag;
}//删除线性表中指定位置的数据

bool ListTraverse(S_map L){
    int flag=1;
    if(ListEmpty(L)){
        flag=0;
        return flag;
    }
    for(int i=0;i<L.length;i++){
        ShowItem(L.item[i]);
    }
    printf("\n");
    return flag;
}//依次访问表中的元素

//用于源文件内部的比较函数
bool compare(Item data1,Item data2){
    int flag=0;
    if(data1.data==data2.data){
        flag=1;
    }
    return flag;
}

void ShowItem(Item item){
    printf("%d ",item.data);
}