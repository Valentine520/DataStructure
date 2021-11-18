#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

//Simply test of heap ADT ,including Create Insert Delete and Traverse
int main(void){
    int array[10];
    int size=sizeof array / sizeof array[0];
    for(int i=0;i<size;i++){
        array[i]=i*2-3-i*i;
    }
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    Heap*heap=BuildHeap(array,size);
    heap_traverse(heap);
    printf("%d\n",Find(array,size,3));
    printf("%d\n",Find(array,size,5));
    return 0;
}

