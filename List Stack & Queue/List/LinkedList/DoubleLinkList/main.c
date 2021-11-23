#include <stdio.h>
#include "Double_Linked_List.h"
int main() {
    Double_List *L;
    bool judge_In= Initial(&L);
    printf("Judge_In :%d\n",judge_In);
    Insert(L,1,10);
    Insert(L,2,20);
    Traverse(L);
    return 0;
}
