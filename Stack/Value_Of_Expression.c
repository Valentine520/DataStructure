////
//// Created by 龙舌兰 on 2021/9/23.
////
//
//#include "STACK.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//static int Value(const char *str);//对表达式求值
//static int compare(char ch);//比较是运算符还是数据
//Item operator(Item data1,Item data2,char ch);//传入操作符
//int My_compare(Item data1,Item data2);
//int main(void){
//    int value= Value("1*2*10+1*2+2/2");
//    printf("%d\n",value);
//    return 0;
//}
//
//
//int Value(const char *str){
//    char buf[100];
//    int value=0;
//    //操作栈和数据栈两者数据类型不同 如何处理？？使用int扩张？？？
//    Stack S_O;//操作栈
//    Stack S_N;//数据栈
//    Initial_Stack(&S_N);
//    Initial_Stack(&S_O);
//    while(*str!='\0'&&*str!='\n'){
//        //如果是操作符
//        if(compare(*str)){
//            if(Stack_Empty(&S_O)){
//                Push(&S_O,(Item){*str});
//            }
//            else{
//                //和栈顶操作符相比 优先级相同则取出计算 优先级高则同样取出计算 优先级低则压入栈
//                //栈顶的优先级高
//                if(My_compare(Get_Top(&S_O),(Item){*str})==1){
//                    char ch=*str;
//                    Item temp2= Get_Top(&S_N);
//                    Pop(&S_N);
//                    //进行操作后压入栈
//                    Item temp1= Get_Top(&S_N);
//                    Pop(&S_N);
//                    Item temp_O= Get_Top(&S_O);
//                    Pop(&S_O);
//                    Push(&S_N,operator(temp1,temp2,(char)temp_O.data));
//                    Push(&S_O,(Item){ch});
//                }
//                else{
//                    Push(&S_O,(Item){*str});//押入栈
//                }
//            }
//            str++;//下一个
//        }
//        else{
//            int index=0;
//            while(!compare(*str)&&*str!='\n'&&*str!='\0'){
//                buf[index++]=(*str);
//                str++;
//            }
//            buf[index]='\0';//结束标记
//            //压入栈
//            Push(&S_N,(Item){atoi(buf)});
//        }
//    }
//    //对栈中剩余的元素进行继续计算
//    while(!Stack_Empty(&S_O)){
//        Item temp1= Get_Top(&S_N);
//        Pop(&S_N);
//        Item temp2= Get_Top(&S_N);
//        Pop(&S_N);
//        Item Op_temp= Get_Top(&S_O);
//        Pop(&S_O);
//        Push(&S_N,operator(temp2,temp1,Op_temp.data));
//    }
//    value=S_N.data->data;
//    return value;
//}
//int compare(char ch){
//    int judge=0;
//    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
//        judge=1;
//    }
//    return judge;
//}
////分离操作符和数据
//
//// 首元素应该是
//int My_compare(Item data1,Item data2){
//    int flag=-1;
//    //低优先级
//    if((data1.data=='+'||data1.data=='-')&&(data2.data=='*'||data2.data=='/')){
//        flag=0;
//    }
//    //高优先级
//    else{
//        flag=1;
//    }
//    return flag;
//}
//
//Item operator(Item data1,Item data2,char ch){
//    Item result=(Item ){-1};
//    switch (ch) {
//        case '+':
//            result.data=data1.data+data2.data;
//            break;
//        case '-':
//            result.data=data1.data-data2.data;
//            break;
//        case '*':
//            result.data=data1.data*data2.data;
//            break;
//        case '/':
//            result.data=data1.data/data2.data;
//            break;
//        default:
//            result.data=-1;
//            break;
//    }
//    return result;
//}