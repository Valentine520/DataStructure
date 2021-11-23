//
// Created by 龙舌兰 on 2021/9/23.
//
#include "Polynomial.h"
#include <stdlib.h>
#include <stdio.h>

/*初始化多项式P*/
bool Initial(Polynomial **P){
    bool flag=1;
    if(((*P)=(Polynomial*) malloc(sizeof(Polynomial)))==NULL){
        flag=0;
        fprintf(stderr,"Fail to allocate the memory for Polynomial.\n");
        return flag;
    }
    (*P)->next=NULL;//置空
    return flag;
}

/*创建多项式*/
void Create_Polynomial(Polynomial*P){
    Polynomial *temp;
    int coe,index;
    printf("Please enter the coe and index of your Polynomial.\n");
    while(scanf("%d %d",&coe,&index)==2){
        temp=(Polynomial*)malloc(sizeof(Polynomial));
        temp->data.Coefficient=coe;
        temp->data.Index=index;
        //寻找前驱
        while(P->next!=NULL){
            P=P->next;
        }
        temp->next=P->next;
        P->next=temp;
        //链接上
        while (getchar()!='\n'){
            continue;//清空
        }
        printf("Please enter the coe and index of your Polynomial.\n");
        printf("Enter nonumeric to stop.\n");
    }
    //清理剩余输入
    while(getchar()!='\n'){
        continue;
    }
}


/*销毁一元多项式*/
void DestroyList(Polynomial **P){
    Polynomial *Head=*P;
    Polynomial *temp=NULL;
    while((*P)!=NULL){
        temp=*P;
        *P=(*P)->next;
        free(temp);
    }
    Head=NULL;//头指针置空
}

/*清空多项式 头节点不清空*/
void ClearList(Polynomial *P){
    Polynomial *Head=P;
    Head=Head->next;
    Polynomial *temp=NULL;
    while((Head)!=NULL){
        temp=Head;
        Head=Head->next;
        free(temp);
    }
    P->next=NULL;//置空
}

/*多项式是否为空*/
bool ListEmpty(Polynomial *P){
    bool flag=0;
    if(P->next==NULL){
        flag=1;
    }
    return flag;
}

/*多项式是否存在*/
bool ListExist(Polynomial *P){
    bool flag=0;
    if(P==NULL){
        flag=1;
    }
    return flag;
}

/*多项式的项数*/
size_t ListLength(Polynomial *P){
    int index=0;

    if(!ListExist(P)){
        index=-1;
        fputs("The polynomial is not exist.\n",stderr);
        return index;
    }

    P=P->next;

    while(P!=NULL){
        index++;
        P=P->next;
    }
    return index;
}

/*打印多项式*/
void Print_Polynomial(const Polynomial*P){
    if(ListEmpty(P)){
        return ;
    }
    P=P->next;
    if(P->next!=NULL) {
        //为0的项没有意义
        while (P->next != NULL) {
            if (P->data.Coefficient != 0) {
                printf(" %d*x^%d+", P->data.Coefficient, P->data.Index);
            }
            P = P->next;
        }
    }
    printf(" %d*x^%d.\n", P->data.Coefficient, P->data.Index);
}

//两个多项式相加
void AddPolyn(Polynomial*P1,Polynomial*P2){
    Polynomial *temp=P1;
    Polynomial *prior=P1;
    //通过多项式相加法则
    P1=P1->next;
    P2=P2->next;
    while(P1!=NULL&&P2!=NULL){
        if(P1->data.Index<P2->data.Index){
            prior=prior->next;
            P1=P1->next;
        }
        else if(P1->data.Index==P2->data.Index){
            P1->data.Coefficient+=P2->data.Coefficient;
            P1=P1->next;
            prior=prior->next;
            P2=P2->next;
        }
        else{
            //向P1插入P2
            //创建新的节点 而不插入整个P2
            Polynomial *Insert_Temp=(Polynomial*) malloc(sizeof(Polynomial));
            Polynomial *Delete_Temp=P2;
            Insert_Temp->data=P2->data;//直接结构体赋值
            //插入P1的前驱
            Insert_Temp->next=prior->next;
            prior->next=Insert_Temp;
            P2=P2->next;
            prior=prior->next;//前驱指针移动
//            free(Delete_Temp);//释放掉P2
        }
    }
    if(P1==NULL&&P2!=NULL){
        //查找前驱
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=P2;//接上P2剩余内容
    }
}

//两个多项式相减
void SubtractPolyn(Polynomial*P1,Polynomial*P2){

}

//两个多项式相乘
void MultiplyPolyn(Polynomial*P1,Polynomial*P2,Polynomial*P3){
    Polynomial *P1_Temp=P1->next;
    //基于多项式加法实现多项式乘法
    while(P1_Temp!=NULL){
        Polynomial *P2_Temp=P2->next;
        Polynomial *temp;
        Initial(&temp);//创建temp
        Polynomial*Copy_temp=temp;
//        Polynomial **Elem_Temp=&(temp->next);
        while (P2_Temp!=NULL){
            //从尾部插入数据
            Polynomial *Insert_Temp=(Polynomial*) malloc(sizeof(Polynomial));
            //单独元素相乘
            Insert_Temp->data.Index=P2_Temp->data.Index+P1_Temp->data.Index;
            Insert_Temp->data.Coefficient=P2_Temp->data.Coefficient*P1_Temp->data.Coefficient;
            Insert_Temp->next=NULL;
            temp->next=Insert_Temp;
            temp=temp->next;
            P2_Temp=P2_Temp->next;
        }
        //使用多项式中间量保存其中的值
        AddPolyn(P3,Copy_temp);//累积求和
        P1_Temp=P1_Temp->next;
    }
}
