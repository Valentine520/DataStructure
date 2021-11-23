#include <stdio.h>
#include "Linear_LinkADT.h"
int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    Link_List*list=malloc(sizeof(Link_List));
    Initial(&list);
    ListInsert(list,1,(Item){12});
    ListInsert(list,1,(Item){19});
    ListInsert(list,1,(Item){121});
    ListInsert(list,1,(Item){2});
    ListInsert(list,1,(Item){21});
    ListTraverse(list);
    ListInsertSort(list);
    ListTraverse(list);
    int data= RandomSearch(list,(Item){12},4);
    printf("%d\n",data);
    return 0;
}