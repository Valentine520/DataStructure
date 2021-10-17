#include <stdio.h>
#include "Sort.h"
int main() {
    int array1[]={1,2,31,45,423,2,12,34253};
    int size1=sizeof(array1)/sizeof array1[0];
    int array2[]={1,2,3454,4345321,1234,2};
    int size2=sizeof(array2)/sizeof array2[0];
    int array3[]={4,2,544,23,4323,56,5,345,};
    int size3=sizeof(array3)/sizeof(array3[0]);
    int array4[]={3,1,41,1234,5,2,902,21};
    int size4=sizeof array4/sizeof array4[0];
    int array5[]={1,7654,2434,53,2,5,4,234,53,2,34};
    int size5=sizeof array5/sizeof array5[0];
    BubleSort(array1,size1);
    InsertSort(array2,size2);
    ShellSort(array3,size3);
    HeapSort(array4,size4);
    SelectSort(array5,size5);
    printf("Buble:\n");
    show_array(array1,size1);
    printf("Insert:\n");
    show_array(array2,size2);
    printf("Shell:\n");
    show_array(array3,size3);
    printf("Heap:\n");
    show_array(array4,size4);
    printf("Select:\n");
    show_array(array5,size5);
    return 0;
}
