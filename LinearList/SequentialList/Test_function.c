//
// Created by 龙舌兰 on 2021/9/18.
//
//测试主函数
#include <stdio.h>

#include <stdlib.h>
#include "Linear_SequentialADT.h"
void my_union(S_map *L1,const S_map *L2);//求交集
int  my_compare(Item data1,Item data2);//比较元素大小
void my_merge(const S_map* L1,const S_map *L2,S_map *L3,
              int (*my_compare)(Item data1,Item data2));
int main(void){
//    S_map *L=(S_map*) malloc(sizeof(S_map));
//    bool judge=Initial(L);
//    printf("Length: %d  Size:%d\n",L->length,L->size);
//    bool empty= ListEmpty(*L);
//
////    ListInsert(&L,0,(Item){10});//传入结构体字面量
//    printf("%d\n",empty);
//    ListInsert(L,0,(Item){10});
//    ListInsert(L,0,(Item){20});
//    ListInsert(L,1,(Item){30});
//    ListInsert(L,0,(Item){40});
//    empty= ListEmpty(*L);
//    printf("%d\n",empty);
//    ListTraverse(*L);
//    ListDelete(L,0);
//    ListTraverse(*L);
//    Item temp1=PriorElem(*L,(Item){30});
//    printf("%d\n",temp1.data);
//    Item temp2= NextElem(*L,(Item){30});
//    printf("%d\n",temp2.data);
//    Item elem= GetElem(*L,1);
//    printf("elem=%d\n",elem.data);
//    printf("%d\n", ListLength(*L));
//    printf("%d\n", ListFull(*L));
//    ClearList(L);
//    empty= ListEmpty(*L);
//    printf("empty: %d\n",empty);
//    ListTraverse(*L);
//    bool fuck= DestroyList(L);
//    printf("%d\n",fuck);
//    S_map L1;
//    S_map L2;
//    Initial(&L1);
//    Initial(&L2);
//    for(int i=0;i<10;i++){
//        ListInsert(&L1,0,(Item ){i*4-2});
//    }
//    for(int i=0;i<7;i++){
//        ListInsert(&L2,0,(Item ){i*4-2});
//    }
//    printf("L1:\n");
//    ListTraverse(L1);
//    printf("L2:\n");
//    ListTraverse(L2);
//
//    my_union(&L1,&L2);
//    printf("L1:\n");
//    ListTraverse(L1);
//    printf("L2:\n");
//    ListTraverse(L2);
//    S_map L1,L2,L3;//创建三张表
//    Initial(&L1);
//    Initial(&L2);
//    Initial(&L3);
//    for(int i=0;i<10;i++){
//        ListInsert(&L1,i,(Item){i*7-2});
//        ListInsert(&L2,i,(Item){i*5+2});
//    }
//    ListTraverse(L1);
//    ListTraverse(L2);
//    my_merge(&L1,&L2,&L3,my_compare);//函数指针传入 表明改如何进行操作
//    ListTraverse(L3);
//    return 0;
    S_map L;
    Initial(&L);
    ListInsert(&L,0,(Item){10});
    ListTraverse(L);

    return 0;
}
//利用ADT将L2中的内容按照非A的方式并入其中 即求交集
void my_union(S_map *L1,const S_map *L2){
    if(ListEmpty(*L1)&& ListEmpty(*L2)){
        fprintf(stderr,"List is empty.\n");
        return;
    }
    for(int i=0;i<L2->length;i++){
        //如果遇到不在L1中的元素则插入
        if(LocateElem(*L1,L2->item[i],compare)==-1){
            ListInsert(L1,L1->length,L2->item[i]);
        }
    }
}

//L3很有讲究  按照compare指定的方式进行归并
void my_merge(const S_map* L1,const S_map *L2,S_map *L3,
              int (*my_compare)(Item data1,Item data2)){
    if(ListEmpty(*L1)&& ListEmpty(*L2)){
        L3=NULL;
        return;
    }

    //索引下标
    int index1,index2,index3;
    index1=0;index2=0;index3=0;
    while(index1<L1->length&&index2<L2->length){
        //L1较大 插入L2
        if(my_compare(L1->item[index1],L2->item[index2])==1){
            ListInsert(L3,index3,L1->item[index1]);
            index1++;index3++;
        }
        //L2较大或者两者相等 插入L1
        else{
            ListInsert(L3,index3,L1->item[index2]);
            index2++;index3++;
        }
    }
    while(index1<L1->length){
        ListInsert(L3,index3,L1->item[index1]);
        index1++;index3++;
    }
    while(index2<L2->length){
        ListInsert(L3,index3,L2->item[index2]);
        index2++;index3++;
    }
}

int my_compare(Item data1,Item data2){
    int flag;
    if(data1.data>data2.data)
        flag=-1;
    else if(data2.data==data1.data)
        flag=0;
    else
        flag=1;
    return flag;
}