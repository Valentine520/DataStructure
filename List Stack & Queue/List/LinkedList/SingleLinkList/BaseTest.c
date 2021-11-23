//
// Created by 龙舌兰 on 2021/9/19.
//
#include <stdlib.h>
#include <stdio.h>
#include "Linear_LinkADT.h"
int main(void){
//    Link_List *L=NULL;
//    bool jude1= ListExist(L);
//    printf("%d\n",jude1);
//    Initial(&L);//初始化
//    jude1= ListExist(L);
//    printf("%d\n",jude1);
//    int judge1= ListEmpty(L);
//    printf("%d\n",judge1);
//    ListInsert(&L,1,(Item){10});
//    ListInsert(&L,2,(Item){20});
//    ListInsert(&L,3,(Item){30});
//    ListInsert(&L,4,(Item){40});
//    judge1= ListEmpty(L);
//    printf("%d\n",judge1);
//    ListTraverse(L);
//    Item data1;
//    GetElem(L,1,&data1);//获取data数据
//    int result=LocateElem(L,(Item){30},compare);//利用compare函数查找
//    printf("the index of locate is %d\n",result);
//    printf("The locate index 1 element is :");
//    ShowItem(data1);
//    putchar('\n');
//    Item data2;
//    int fuck= PriorElem(L,(Item){30},&data2);
//    printf("The PriorElement is:");
//    ShowItem(data2);
//    printf("Success or fail:%d\n",fuck);
//    ClearList(L);
//    printf("List Exit %d\n",jude1);
//    DestroyList(&L);
//    bool fuck2=ListTraverse(L);
//    printf("%d\n",fuck2);
//    jude1= ListExist(L);
//    printf("List Exit %d\n",jude1);
    Link_List *List;
    Initial(&List);
    for(int i=0;i<20;i++){
        ListInsert(List,1,(Item){i*8-10});
    }
    ListTraverse(List);
    Reverse(List,10);
    ListTraverse(List);
    Reverse(List,10);//可以复原
    ListTraverse(List);

    return 0;
}

