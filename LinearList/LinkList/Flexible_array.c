////
//// Created by 龙舌兰 on 2021/9/20.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//typedef struct Flexible_array{
//    int count;
//    double *array;//变长数组
//    //和指针是不是类似的？？都是通过申请内存空间来维护？？
//}F_array;
//int main(void){
//    F_array *ptr1=(F_array*) malloc(sizeof(F_array)+sizeof(double)*10);//为flexible_array 开辟内存空间
//    ptr1->count=10;
//    for(int i=0;i<20;i++){
//        ptr1->array[i]=i*10-2*i*i;//为数组中的变量赋值
//    }
//    //内存溢出
//    for(int i=0;i<20;i++){
//        printf("%.2f ",ptr1->array[i]);
//    }
//    putchar('\n');
//    realloc(ptr1,sizeof(F_array)+sizeof(double)*30);
//    for(int i=0;i<30;i++){
//        printf("%.2f ",ptr1->array[i]);
//    }
//    putchar('\n');
//    F_array *ptr2=(F_array*)malloc(sizeof(F_array)+sizeof(double)*20);
//    ptr2->count=20;
//    for(int i=0;i<20;i++){
//        ptr2->array[i]=i*i*i+2*i*i-3;
//    }
//    for(int i=0;i<20;i++){
//        printf("%.2f ",ptr2->array[i]);
//    }
//    free(ptr1);
//    free(ptr2);
//    ptr1=NULL;
//    ptr2=NULL;
//
//    return 0;
//}
