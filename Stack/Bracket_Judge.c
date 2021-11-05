////
//// Created by 龙舌兰 on 2021/9/23.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include "STACK.h"
//#define SIZE 100
//#include <string.h>
//
//_Bool Bracket(const char *S);//判断括号是否合法
//
//void s_gets(char *S,int size);//无换行符获取字符串
//
//int main(void){
//    char *S;
//    char buf[SIZE];
//    printf("Please enter the Bracket Component.\n");
//    s_gets(buf,SIZE);
//    S=buf;
//    _Bool Judge=Bracket(S);
//    printf("%d\n",Judge);
//    return 0;
//}
//
//_Bool Bracket(const char *S){
//    Stack stack;
//    Initial_Stack(&stack);
//    _Bool Judge=1;
//    while(*S!='\0'){
//        if(*S=='{'||*S=='('||*S=='['){
//            Push(&stack,(Item){*S});
//            S++;
//        }
//        else if(*S=='}'||*S==')'||*S==']'){
//            char temp;
//            switch (*S) {
//                case '}':
//                    temp='{';
//                    break;
//                case ')':
//                    temp='(';
//                    break;
//                case ']':
//                    temp='[';
//                    break;
//            }
//            if(Get_Top(&stack).data!=temp){
//                Judge=0;
//                return Judge;
//            };
//            Pop(&stack);
//            S++;
//        }
//        else{
//            Judge=0;
//            return Judge;
//        }
//    }
//    if(!Stack_Empty(&stack)){
//        Judge=0;
//    }
//    return Judge;
//}
//
//void s_gets(char *S,int size){
//    char *temp=S;
//    temp=fgets(temp,size,stdin);
//    if(temp==NULL){
//        fprintf(stderr,"Error.\n");
//        return;
//    }
//    char*ch=strchr(temp,'\n');
//    if(*ch=='\n'){
//        *ch='\0';
//    }
//    else{
//        while(getchar()!='\n'){
//            continue;
//        }
//    }
//}
