#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

//Simply test of heap ADT ,including Create Insert Delete and Traverse
int main(void){
    int List[]={12,3,1,41,87,91,13,4,8,19};
    int size=sizeof(List)/sizeof(List[0]);
    Heap heap;
    Create(&heap,List,size);
    heap_traverse(&heap);
    Insert(&heap,10);
    Insert(&heap,20);
    heap_traverse(&heap);
    Delete(&heap);
    heap_traverse(&heap);
    return 0;
}

