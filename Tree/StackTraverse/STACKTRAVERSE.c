//
// Created by 龙舌兰 on 2021/9/30.
//

//
// Created by 龙舌兰 on 2021/9/24.
//

#include "STACKTRAVERSE.h"
#include <stdlib.h>
#include <stdio.h>


bool Initial_Stack(Stack *S) {
    bool flag = 1;
    S->data = (Item *) malloc(sizeof(Item) * BASE_LENGTH + 1);//初始化为基础长度
    if (S->data == NULL) {
        flag = 0;
        fprintf(stderr, "Fail to allocate the memory.\n");
        return flag;
    }
    S->base = S->data;
    S->top = S->data;//空表
    S->Stack_Size = BASE_LENGTH;//初始容量
    return flag;
}

bool Stack_Empty(const Stack *S) {
    bool flag = 0;
    if (S->base == S->top) {
        flag = 1;
        return flag;
    }
    return flag;
}

bool Stack_Full(const Stack *S) {
    bool flag = 0;
    const Item *temp = S->top;
    int index = 0;
    while (temp != S->base) {
        temp--;
        index++;
    }
    if (index >= S->Stack_Size) {
        flag = 1;
    }
    return flag;
}

//删除栈
void Destroy_Stack(Stack *S) {
    free(S->data);//删除分配的内存空间
    S->data = NULL;
    S->base = NULL;
    S->top = NULL;
    S->Stack_Size = 0;
    //栈还在 只是被清空了
    Initial_Stack(S);//重新初始化
}

//清空栈
bool Clear_Stack(Stack *S) {
    int flag = 1;
    if (S == NULL) {
        //如果栈根本不存在
        flag = 0;
        fprintf(stderr, "The stack is not exist.\n");
        return flag;
    }
    free(S->data);//删除分配的内存空间
    //可要可不要
    S->data = NULL;
    S->base = NULL;
    S->top = NULL;
    S->Stack_Size = 0;
    Initial_Stack(S);
    return flag;
}

//栈的长度
int Stack_Length(const Stack *S) {
    int index = 0;
    if (S == NULL) {
        index = -1;
        fprintf(stderr, "The Stack is not exist.\n");
        return index;
    }
    const Item *temp = S->top;
    while (temp != S->base) {
        temp--;
        index++;
    }
    return index;
}

//访问栈顶元素
Item Get_Top(const Stack *S) {
    Item data = (Item) {-1};
    if (Stack_Empty(S)) {
        fputs("The Stack is empty.\n", stderr);
        return data;
    }
    data = *(S->top - 1);
    return data;
}

//压入栈
void Push(Stack *S, Item item) {
    *(S->top) = item;
    (S->top)++;
    //表满 分配更大的空间
    if (Stack_Full(S)) {
        S->data = realloc(S, S->Stack_Size + MORE_LENGTH + 1);
    }
}

//弹出栈 不显示其值
bool Pop(Stack *S) {
    bool flag = 1;
    if (Stack_Empty(S)) {
        flag = 0;
        fprintf(stderr, "Error.\n");
        return flag;
    }
    *(S->top) = (Item) {0};
    S->top--;
    return flag;
}

//遍历栈的数据
void Traverse_Stack(const Stack *S, void (*Visit)(Item *)) {
    Item *temp = S->top;
    while (temp != S->base) {
        temp--;
        Visit(temp);
    }
    putchar('\n');

}

void Visit(Item *Data) {
    printf("%d ", Data->data.data);
}





////树///////


//构造二叉树
//使用递归的方法构造 在构造结束时其头指针方向不变
void CreateBtree(Node **Btree) {
    int num;
    int judge = scanf("%d", &num);
    while (getchar() != '\n') {
        continue;
    }
    //未输入值 则表示没有节点
    if (judge != 1) {
        *Btree = NULL;//节点为空
    } else {
        *Btree = (Node *) malloc(sizeof(Node));//创建节点
        (*Btree)->data = num;
        CreateBtree(&(*Btree)->Lchild);//创建左节点
        CreateBtree(&(*Btree)->Rchild);//创建右节点
    }
}

void InorderTraverse(Node *Btree) {
    Stack stack;
    Initial_Stack(&stack);//初始化
    if (Btree != NULL) {
        Item temp;
        temp.data = *Btree;
        //初始化
        Push(&stack, temp);//压入第一个元素
        //初始化 压入所有节点元素
        while (temp.data.Lchild != NULL) {
            temp.data = *(temp.data.Lchild);
            Push(&stack, temp);
        }
        while (!Stack_Empty(&stack)) {
            //弹出节点
            temp = Get_Top(&stack);
            printf("\n%d\n", temp.data.data);//打印节点信息
            Pop(&stack);//删除节点
            if (temp.data.Rchild != NULL) {
                temp.data = *(temp.data.Rchild);
                Push(&stack, temp);
                while (temp.data.Lchild != NULL) {
                    temp.data = *(temp.data.Lchild);
                    Push(&stack, temp);
                }
            }
        }
    }

}

void PreorderTraverse(Node *Btree) {
    Stack stack;
    Initial_Stack(&stack);//初始化
    if (Btree != NULL) {
        Item temp;
        Item fuck;
        temp.data = *Btree;
        //初始化
        Push(&stack, temp);//压入第一个元素
        while (!Stack_Empty(&stack)) {
            temp = Get_Top(&stack);//从stack中弹出元素 先序 弹出则直接访问
            printf("%d\n", temp.data.data);
            Pop(&stack);//删除节点
            //如果右有节点则push右 如果左有节点则push左 左在右之后 和stack的先进后出相配合
            if (temp.data.Rchild != NULL) {
                fuck.data = *(temp.data.Rchild);
                Push(&stack, fuck);
            }
            if (temp.data.Lchild != NULL) {
                fuck.data = *(temp.data.Lchild);
                Push(&stack, fuck);
            }
        }
    }
}


//单栈实现 我就是天才
void PostorderTraverse(Node *Btree) {
    Stack stack;
    Initial_Stack(&stack);//初始化
    if (Btree != NULL) {
        Item temp;
        Item fuck;
        temp.data = *Btree;
        //初始化
        Push(&stack, temp);//压入第一个元素
        while (!Stack_Empty(&stack)) {
            temp = Get_Top(&stack);
            //中间不动 只访问
            if(temp.data.Rchild==NULL&&temp.data.Lchild==NULL){
                printf("%d\n", temp.data.data);
                Pop(&stack);//删除节点
            }
            else{
                //先压右
                if(temp.data.Rchild != NULL) {
                    fuck.data = *(temp.data.Rchild);//创建副本保存
                    //取出该节点然后更改其右指针为空 避免重复访问 陷入死循环
                    Item fuck2=Get_Top(&stack);//临时保存
                    Pop(&stack);
                    fuck2.data.Rchild=NULL;//修改节点的指针
                    Push(&stack,fuck2);
                    Push(&stack, fuck);
                }
                //再压左
                //判断是否已经压入了右 
                //如果否 则pop一次就可以得到Lchild 不包含Rchild
                if(temp.data.Rchild==NULL&&temp.data.Lchild!=NULL) {
                    temp= Get_Top(&stack);//不修改temp
                    fuck.data = *(temp.data.Lchild);//创建副本保存
                    temp.data.Lchild=NULL;
                    Pop(&stack);
                    Push(&stack,temp);
                    Push(&stack,fuck);
                }
                //如果是 则应该pop两次(Pre Rchild)才能访问到Lchild
                else if(temp.data.Rchild!=NULL&&temp.data.Lchild!=NULL){
                    Item fuck4;//临时保存Lchild
                    fuck4.data=*(temp.data.Lchild);
                    Item fuck3= Get_Top(&stack);
                    Pop(&stack);
                    temp= Get_Top(&stack);
                    temp.data.Lchild=NULL;
                    Pop(&stack);
                    //按照中右左的方式压入 访问时则为反序 左右中 实现后序遍历
                    Push(&stack,temp);
                    Push(&stack,fuck3);
                    Push(&stack,fuck4);
                }
            }
        }
    }
}


//使用双栈实现
void PostorderTraverse2(Node *Btree){
    if(Btree!=NULL) {
        Stack stack_operator;//操作栈
        Stack stack_result;//结果栈
        Initial_Stack(&stack_operator);
        Initial_Stack(&stack_result);
        Item temp;
        temp.data = *Btree;
        Push(&stack_operator, temp);
        //上述进行初始化操作
        while (!Stack_Empty(&stack_operator)) {
            temp = Get_Top(&stack_operator);//获取操作栈的栈顶节点
            Push(&stack_result, temp);//压入结果栈
            Pop(&stack_operator);
            //检查是否存在左右节点 先左后右
            //左节点存在
            if (temp.data.Lchild != NULL) {
                //不能修改temp 使用temp2作为拷贝对象
                Item temp2;
                temp2.data = *(temp.data.Lchild);
                Push(&stack_operator, temp2);//压入操作栈
            }
            //右节点存在
            if (temp.data.Rchild != NULL) {
                temp.data = *(temp.data.Rchild);
                Push(&stack_operator, temp);//压入操作栈
            }
        }
        //操作完成 直接打印结果栈的内容即可 结构栈中的内容即为后序遍历
        while(!Stack_Empty(&stack_result)){
            temp= Get_Top(&stack_result);
            printf("%d\n",temp.data.data);
            Pop(&stack_result);
        }
    }
}