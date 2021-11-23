//#include <stdio.h>
//#include "STACK.h"
//#include <stdlib.h>
//void Transfer(int num);//进制的转化
//
//int main() {
//    //测试内容
////    Stack S;
////    bool Judge1=Initial_Stack(&S);
////    printf("1:%d\n",Judge1);
////    int length= Stack_Length(&S);
////    Push(&S,(Item){10});
////    Push(&S,(Item){20});
////    Push(&S,(Item){30});
////    Get_Top(&S);
////    Traverse_Stack(&S,Visit);
////    Pop(&S);
////    Traverse_Stack(&S,Visit);
////    bool Judge2= Stack_Empty(&S);
////    printf("2:%d\n",Judge2);
////    Clear_Stack(&S);
////    Judge2= Stack_Empty(&S);
////    printf("3:%d\n",Judge2);
////    Destroy_Stack(&S);
//    //栈的应用
//    //进行进制的转换 Num=（Num div n)*n+Num mod n;
//    Transfer(13);
//    return 0;
//}
//void Transfer(int num){
//    Stack S;
//    Initial_Stack(&S);
//    while(num){
//        Push(&S,(Item){num%8});
//        num/=8;
//    }
//    while(!Stack_Empty(&S)){
//        printf("%d",Get_Top(&S).data);
//        Pop(&S);
//    }
//    putchar('\n');
//}
