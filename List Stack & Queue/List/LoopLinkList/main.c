#include <stdio.h>
#include <stdbool.h>
#include "Loop_List.h"
int main(void) {
//    Loop_List *List=NULL;//创建指针则置空
//    bool judge_I=Initial(&List);
//    printf("%d\n",judge_I);
//    bool judge_E= ListEmpty(List);
//    bool judge_In= Insert_Elem(&List,1,(Item){10});
//    judge_In= Insert_Elem(&List,2,(Item){20});
//    Insert_Elem(&List,1,(Item){30});
//    Insert_Elem(&List,3,(Item){30});
//    bool judge_T= Traverse(List);
//    printf("Judge_Insert: %d\n",judge_In);
//    printf("Judge_Empty: %d\n",judge_E);
//    printf("Judge_Traverse: %d\n",judge_T);
//    int site=Locate_Elem(List,(Item){30});
//    printf("%d\n",site);
//    Delete_Elem(&List,1);
//    Delete_Elem(&List,2);
//    Delete_Elem(&List,3);
//    Traverse(List);
//    List_Clear(&List);
//    Traverse(List);//nice
//
    Loop_List *L1,*L2;
    Initial(&L1);
    Initial(&L2);
    for(int i=1;i<10;i++){
        Insert_Elem(&L1,i,(Item){i*3-2+i*i});
    }
    for(int i=1;i<8;i++){
        Insert_Elem(&L2,i,(Item){i*4+9-i*i});
    }
    printf("L1:\n");
    Traverse(L1);
    printf("L2:\n");
    Traverse(L2);
    List_Merge(&L1,&L2);
    Traverse(L2);
    int length=L2->Next->data.data;
    printf("%d\n",length);
    return 0;
}
