#include "Sort.h"
#include <stdio.h>


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

    int array6[]={1,2,31,42,98,192,1,2,3,6,30,21,12,1341323};
    int size6=sizeof array6/sizeof array6[0];

    int array7[]={1,2,31,2,5,56,454,5,6,43,2,45643};
    int size7=sizeof array7/sizeof array7[0];

    int array10[]={2,1,345,243,124,354321,345,65};
    int size10=sizeof array10/sizeof array10[0];



    BubbleSort(array1,size1);//冒泡排序
    InsertSort(array2,size2);//插入排序
    ShellSort(array3,size3);//希尔排序
    HeapSort(array4,size4);//堆排序
    SelectSort(array5,size5);//选择排序
    MergeSortRecursion(array6,size6);//递归的归并排序
//    MergeSortIterator(array7,size7);//非递归的归并排序
    QuickSort(array7,size7);//快速排序
    IntroSort(array10,size10);//Intro排序


    //打印排序成果
    printf("\n");
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
    printf("MergeRecursion:\n");
    show_array(array6,size6);
    printf("Quick:\n");
    show_array(array7,size7);
    printf("IntroSort:\n");
    show_array(array10,size10);


    return 0;
}
