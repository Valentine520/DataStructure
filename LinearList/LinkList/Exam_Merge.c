////
//// Created by 龙舌兰 on 2021/9/20.
////
//
//#include <stdlib.h>
//#include <stdio.h>
//#include "Linear_LinkADT.h"
//int Item_compare(Item data1,Item data2);//比较大小
//void merge(Link_List*L1,Link_List*L2,Link_List**l3);//要修改L3 传递其地址
//
//int main(void){
//    Link_List *L1,*L2,*L3;
//    Initial(&L1);
//    Initial(&L2);
//    for(int i=0;i<10;i++){
//        ListInsert(&L1,i+1,(Item){i*10-2});
//    }
//    for(int i=0;i<8;i++){
//        ListInsert(&L2,i+1,(Item){i*7+2});
//    }
//    ListTraverse(L1);
//    putchar('\n');
//    ListTraverse(L2);
//    putchar('\n');
//    merge(L1,L2,&L3);
//    printf("L1:\n");
//    ListTraverse(L1);
//    printf("L2:\n");
//    ListTraverse(L2);
//    printf("L3:\n");
//    ListTraverse(L3);
//
//    return 0;
//}
//
//void merge(Link_List*L1,Link_List*L2,Link_List**L3){
//    if(!ListExist(L1)||!ListExist(L2)){
//        fprintf(stderr,"The List is't exist\n");
//        return;
//    }
//    if(ListEmpty(L1)&& ListEmpty(L2)){
//        fprintf(stderr,"The List is empty\n");
//        return;
//    }
//    Initial(L3);
//    Link_List *temp1,*temp2,*temp3;
//    temp1=L1->next;temp2=L2->next;temp3=(*L3);
//    while(temp1!=NULL&&temp2!=NULL){
//        //L1 比 L2 大
//        if(Item_compare(temp1->data,temp2->data)==1){
//            temp3->next=temp2;
//            temp3=temp3->next;
//            temp2=temp2->next;
//        }
//        else{
//            temp3->next=temp1;
//            temp3=temp3->next;
//            temp1=temp1->next;
//        }
//    }
//    if(temp1!=NULL){
//        temp3->next=temp1;//直接接上
//    }
//    if(temp2!=NULL){
//        temp3->next=temp2;
//    }
//}
//
//int Item_compare(Item data1,Item data2){
//    int judge;
//    if(data1.data>data2.data){
//        judge=1;
//    }
//    else if(data1.data<data2.data){
//        judge=-1;
//    }
//    else{
//        judge=0;
//    }
//    return judge;
//}