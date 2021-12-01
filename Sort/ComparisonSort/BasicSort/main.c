#include "BasicSort.h"
#define SIZE 10
int main() {
    srand((unsigned int)time(NULL));
    int array1[SIZE];
    int array2[SIZE];
    int array3[SIZE];
    for(int i=0;i<SIZE;i++){
        array1[i] = rand()%17;
        array2[i] = rand()%23;
        array3[i] = rand()%31;
    }
    printf("排序前\n");
    ShowArray(array1,SIZE);
    ShowArray(array2,SIZE);
    ShowArray(array3,SIZE);
    InsertSort(array1,SIZE);
    BubleSort(array2,SIZE);
    SelectSort(array3,SIZE);
    printf("排序后\n");
    ShowArray(array1,SIZE);
    ShowArray(array2,SIZE);
    ShowArray(array3,SIZE);
    return 0;
}
