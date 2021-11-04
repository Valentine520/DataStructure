//
// Created by 龙舌兰 on 2021/9/19.
//
#include "Linear_LinkADT.h"
#include <stdio.h>
#include <stdlib.h>

//链表的初始化
bool Initial(Link_List **L){
    bool flag=1;
    *L=(Link_List*) malloc(sizeof(Link_List));//为头指针创建头节点
    if((*L)==NULL){
        flag=0;
        return flag;
    }
    (*L)->next=NULL;//指向为空
    (*L)->data=(Item){0};
    return flag;
}

void DestroyList(Link_List**L){
    //直接删除头节点
    free(*L);
    *L=NULL;//指向为空 (使用地址传入)!!!
}

//不易清空 每次都要从节点开始释放？？
void ClearList(Link_List *L){
    Link_List *temp1=L->next;
    Link_List *temp2=NULL;
    //找到末尾节点
    //如果链表非空
    while(temp1!=NULL) {
        temp2=temp1;
        temp1=temp1->next;
        free(temp2);//利用temp2临时保存temp1的节点而后释放
    }
    L->next=NULL;//清空节点 但不删除头节点
}

bool ListEmpty(Link_List *L){
    int flag=0;
    //判断是否为空
    if(L->next==NULL){
        flag=1;
    }
    return flag;
}

bool ListExist(Link_List *L){
    bool flag=1;
    if (L==NULL){
        flag=0;//链表不存在
    }
    return flag;
}
//有副作用吗？？ 没有
size_t ListLength(Link_List *L){
    Link_List *temp=L->next;
    size_t size=0;
    if(!ListExist(L)){
        size=-1;//链表不存在
        return size;
    }
    if(ListEmpty(L)){
        size=0;//链表空
        return size;
    }
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}

bool GetElem(Link_List *L,int index,Item *data){
    int flag=1;
    size_t List_length= ListLength(L);

    //访问地址非法 返回-1
    if(index<0&&index>List_length){
        flag=-1;
        return flag;
    }

    //从头节点 移动index次
    for(int i=0;i<index;i++){
        L=L->next;
    }

    *data=L->data;//赋值给data
    return flag;
}

//通过compare函数比较两者的大小 类似于线性表
int LocateElem(Link_List *L,Item data,bool (*compare)(Item data1,Item data2)){
    int index=-1;
    int flag=1;
    Link_List *temp=L;
    while(L!=NULL){
        index++;
        if(compare(L->data,data)){
            flag=0;
            break;
        }
        L=L->next;//向后移动
    }
    //如果都没有遇到相等的比较则表示元素不存在
    if(flag) {
       index=-1;//元素不存在
    }
    return index;
}

bool PriorElem(Link_List*L,Item data,Item *prior){
    int flag=1;
    //这里要考虑LocateElem有没有副作用
    //几重判断 不空 存在 而且要元素存在 而且元素不要位于头 头的index 为1
    //写错判断条件 老毛病又犯了 fuck！！！！ 注意｜｜和 && 的区别
    if(ListEmpty(L)|| !ListExist(L)||(flag=LocateElem(L,data,compare))==1||flag==-1 ){
        flag=0;
        return flag;
    }
    //找前驱 flag 所定位处之前则为前驱
    for(int i=0;i<flag-1;i++){
        L=L->next;
    }
    *prior=L->data;
    return flag;
}

bool NextElem(Link_List *L,Item data,Item *next){
    int flag=1;
    size_t List_length= ListLength(L);
    //这里要考虑LocateElem有没有副作用
    //几重判断 不空 存在 而且要元素存在(flag!=-1) 而且元素不要位于尾(flag!=list_length-1)
    if(ListEmpty(L)&& !ListExist(L)&&(flag=LocateElem(L,data,compare))==List_length-1&&flag==-1 ){
        flag=0;
        return flag;
    }
    //查找后继
    for(int i=0;i<flag+2;i++){
        L=L->next;
    }
    *next=L->data;
    return flag;
}

//在进行前驱和后继的查找等不希望原头节点位置发生变化的操作时
//需要创建一个副本 用于代替头节点进行操作 但头节点的位置仍然不变
//如果使用return的方式也可以解决节点的赋值操作 主要是头节点如果不使用二级指针则无法插入
bool ListInsert(Link_List *L,int index,Item data){
    int flag=1;
    Link_List *list_copy=L;//创建副本 不改变L
    size_t List_length= ListLength(L);
    if(index<0&&index>List_length+1){
        flag=0;
        return flag;
    }
    //找前驱和后继然后插入  产生了副作用
    for(int i=0;i<index-1;i++){
        (list_copy)=(list_copy)->next;//要对实参产生影响则必须采用地址传递
    }
    //此时L为前驱
    Link_List *temp=(Link_List*) malloc(sizeof(Link_List));
    temp->data=data;//赋值
    //改变指针的指向
    temp->next=(list_copy)->next;
    (list_copy)->next=temp;
    return flag;
}

bool ListDelete(Link_List *L,int index){
    int flag=1;
    size_t List_length= ListLength(L);
    //非法的下标索引
    if(index<0&&index>List_length-1){
        flag=0;
        return flag;
    }
    //需要释放吗？？
    //查找节点的前驱 后继 相连即可
    for(int i=0;i<index-1;i++){
        L=L->next;
    }
    Link_List *temp=L->next;
    L->next=L->next->next;
    free(temp);//释放该节点
    return flag;
}

bool ListTraverse(Link_List *L){
    int flag=1;
    //如果链表不存在或者空
    if(!ListExist(L)|| ListEmpty(L)){
        flag=0;
        return flag;
    }
    while(L->next!=NULL){
        L=L->next;
        ShowItem(L->data);
    }
    putchar('\n');
    return flag;
}

void ShowItem(Item item){
    printf("%2d ",item.data);
}


bool compare(Item data1,Item data2){
    int flag;
    if(data1.data==data2.data){
        flag=1;
    }
    else{
        flag=0;
    }
    return flag;
}

//使用三个指针实现链表的逆转
Link_List *Reverse(Link_List*MyList,int k){
    Link_List *List=MyList;
    size_t Length= ListLength(List);
    int count=0;
    //首先判断k和链表长度的关系 k不能大于链表的表长
    if(k>Length||Length==0){
        fprintf(stderr,"Invalid number of node.\n");
        return NULL;
    }
    //在起始时就已经假定进行了一次reverse 即New=List->next 该New就是经过一次reverse的链表
    else if(k==Length){
        Link_List *New=List->next;//New节点
        Link_List *Old=New->next;//Old节点
        Link_List *Temp=Old->next;//Temp节点
        while(count<k-2){
            Old->next=New;
            New=Old;
            Old=Temp;
            Temp=Old->next;
            count++;
        }
        //处理最后一个节点
        Old->next=New;
        New=Old;
        List->next->next=NULL;
        List->next=New;
    }
    else{
        Link_List *New=List->next;//New节点
        Link_List *Old=New->next;//Old节点
        Link_List *Temp=Old->next;//Temp节点
        while(count<k-1){
            Old->next=New;
            New=Old;
            Old=Temp;
            Temp=Old->next;
            count++;
        }
        //处理头节点和最后一个节点（逆转后的）
        List->next->next=Old;
        List->next=New;
    }
    return List;
}