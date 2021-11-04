#include <stdio.h>
#include "Static_List.h"
int main() {
    Static_List *List=NULL;
    bool judge_ex= ListExit(List);//表是否存在
    printf("%d\n",judge_ex);
    bool judge_i=Initial(&List);//初始化静态链表
    printf("%d\n",judge_i);
    bool judge_em= ListEmpty(List);//判断是否为空
    printf("%d\n",judge_em);
    judge_ex= ListExit(List);//表是否存在
    printf("%d\n",judge_ex);
    bool judge_in=Insert2(List,1,(Item){10});
    printf("Insert: %d\n",judge_in);
    judge_in=Insert2(List,2,(Item){20});
    printf("Insert: %d\n",judge_in);
    judge_in=Insert2(List,3,(Item){30});
    printf("Insert: %d\n",judge_in);
    Traverse(List);

    Delete(&List,3);
    Remaining(List);
    Traverse(List);
    Static_List *L1,*L2,*L3;
    Initial(&L1);
    Initial(&L2);
    Initial(&L3);
    for(int i=1;i<10;i++){
        Insert2(L1,i,(Item){i*9-2});
    }
    for(int i=1;i<10;i++){
        Insert2(L2,i,(Item){i*7-3});
    }
    printf("L1:");
    Traverse(L1);
    printf("L2:");
    Traverse(L2);
    printf("L3:");
    Traverse(L3);
    Merge(L1,L2,L3,compare);
    printf("L1:");
    Traverse(L1);
    printf("L2:");
    Traverse(L2);
    printf("L3:");
    Traverse(L3);
    return 0;
}
