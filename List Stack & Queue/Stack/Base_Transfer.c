////
//// Created by 龙舌兰 on 2021/9/23.
////
//
//#include <stdio.h>
//#include "STACK.h"
//#include <stdlib.h>
//void Transfer(int num,int base);//进制的转化 base为进制 num为待转化的数据
//
//int main() {
//    //栈的应用
//    //进行进制的转换 Num=（Num div n)*n+Num mod n;
//    Transfer(19,9);
//    return 0;
//}
//void Transfer(int num,int base){
//    Stack S;
//    Initial_Stack(&S);
//    while(num){
//        Push(&S,(Item){num%base});
//        num/=base;
//    }
//    while(!Stack_Empty(&S)){
//        printf("%d",Get_Top(&S).data);
//        Pop(&S);
//    }
//    putchar('\n');
//}
