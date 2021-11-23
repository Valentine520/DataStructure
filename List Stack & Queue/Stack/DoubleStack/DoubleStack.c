#include "DoubleStack.h"

Stack Initial(void){
    Stack S;
    //初始化
    S=malloc(sizeof(stack));
    S->data=(int*)malloc(sizeof(int)*MAXSIZE);
    S->size=MAXSIZE;
    S->Top1=1;//stack1
    S->Top2=S->size-2;//stack2
    return S;
}
//判断栈是否空 双栈-1为栈一空 -2为栈2空 1则不空 0则全空
int IsEmpty(Stack S){
    int flag=0;
    if(S->Top1==1&&S->Top2==S->size-2){
        flag=0;
    }
    else if(S->Top1==1){
        flag=-1;
    }
    else if(S->Top2==S->size-2){
        flag=-2;
    }
    else{
        flag=1;
    }
    return flag;
}

int IsFull(Stack S){
    int flag=0;
    //Stack is full
    if(S->Top1>=S->Top2-1){
        flag=1;
    }
    return flag;
}

//向哪个栈push index=1 代表stack1   index=2 代表stack2

void Push(Stack S,int index,int data){
    if(IsFull(S)){
        fprintf(stderr,"The stack is full\n");
        return;
    }
    if(index==1){
        S->data[S->Top1++]=data;
    }
    else{
        S->data[S->Top2--]=data;
    }
}

int Pop(Stack S,int index){
    int data=-1;
    int judge=IsEmpty(S);
    if((index==abs(judge)||judge==0)&&judge!=1){
        fprintf(stderr, "The stack is empty.\n");
        return data;
    }
    else{
        //删除index指向的stack
        if(index==1){
            data=S->data[--(S->Top1)];
        }
        else{
            data=S->data[++(S->Top2)];
        }
    }
    return data;
}
