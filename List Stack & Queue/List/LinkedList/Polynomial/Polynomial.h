//
// Created by 龙舌兰 on 2021/9/23.
//

#ifndef POLYNOMIAL_POLYNOMIAL_H
#define POLYNOMIAL_POLYNOMIAL_H

#include <stdlib.h>
//定义多项式数据类型 指数、系数
typedef struct item{
    int Coefficient;//指数
    int Index;//系数
}Item;

typedef _Bool bool;//定义bool数据类型

typedef struct link_list{
    struct link_list *next;//指向下一结点的指针
    Item data;//保存数据
}Link_List;

typedef Link_List Polynomial;//定义多项式数据类型

/*初始化多项式P*/
bool Initial(Polynomial **P);//初始化一个空的线性表L

/*创建多项式P*/
void Create_Polynomial(Polynomial*P);

/*销毁一元多项式*/
void DestroyList(Polynomial**P);

/*清空多项式*/
void ClearList(Polynomial *P);

/*多项式是否为空*/
bool ListEmpty(Polynomial *P);

/*多项式是否存在*/
bool ListExist(Polynomial *P);

/*多项式的项数*/
size_t ListLength(Polynomial *P);

/*打印多项式*/
void Print_Polynomial(const Polynomial*P);

//两个多项式相加
void AddPolyn(Polynomial*P1,Polynomial*P2);

//两个多项式相减
void SubtractPolyn(Polynomial*P1,Polynomial*P2);

//两个多项式相乘
void MultiplyPolyn(Polynomial*P1,Polynomial*P2,Polynomial*P3);


#endif //POLYNOMIAL_POLYNOMIAL_H
