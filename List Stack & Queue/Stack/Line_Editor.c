////
//// Created by 龙舌兰 on 2021/9/23.
////
//#include "STACK.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
////使用栈实现行缓冲输出
//void LineEdit();
//
//int main(void){
//    LineEdit();
//    return 0;
//}
//
//void LineEdit(){
//    Stack S;
//    Initial_Stack(&S);
//    char ch=getchar();
//    while(ch!='$'){
//        while(ch!='\n'){
//            switch (ch){
//                case '@':
//                    Clear_Stack(&S);
//                    break;
//                case '#':
//                    Pop(&S);
//                    break;
//                default:
//                    Push(&S,(Item){ch});
//            }
//            ch=getchar();
//        }
//        Traverse_Stack(&S,Visit);
//        Clear_Stack(&S);
//        ch=getchar();//读取首字符 用于结束
//        //清除其余内容
////        while (getchar()!='\n'){
////            continue;
////        }
//    }
//}