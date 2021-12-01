#include "MergeSort_I.h"
int main(void){
    int array[]={1,2,3,1};
    int size=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    putchar('\n');
    MergeSort(array,size);
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    return 0;
}
