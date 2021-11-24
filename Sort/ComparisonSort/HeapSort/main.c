
#include "HeapSort.h"

//下标的计算有所不同
int main(void){
    int array[]={1,2,4,1,34,532,4313245,1,1,3,1};
    int size=sizeof(array)/sizeof(array[0]);
    ShowArray(array,size);
    HeapSort(array,size);
    ShowArray(array,size);
    return 0;
}

