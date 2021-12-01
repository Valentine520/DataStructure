#include "LinearSort.h"


int main(int argc, char *argv[]) {
	srand((unsigned int)time(NULL));
	int size=20;
	int *array1 = (int *)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		array1[i] = rand() % 100;
	}
    printf("\nBucket Sort:\n");
    printf("Array1 排序前:\n");
	ShowArray(array1,size);
    BucketSort(array1,size);//桶排序
    printf("Array1 排序后(以个位数字作为桶的index进行排序 保证桶内元素有序）:\n");
    //使用基数排序分别对位进行操作 利用稳定排序 多排几趟就可以实现好的排序
    // 同时每次排序都是数字型 使用count sort同样迅速
	ShowArray(array1,size);

    int *array2 = (int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        array2[i] = rand() % 71;
    }
    printf("\nCount Sort:\n");
    printf("Array2 排序前:\n");
    ShowArray(array2,size);
    CountSort(array2,size);//计数排序
    printf("Array2 排序后）:\n");
    ShowArray(array2,size);


    int *array3 = (int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        array3[i] = rand() % 113;
    }
    printf("\nRadix Sort:\n");
    printf("Array3 排序前:\n");
    ShowArray(array3,size);
    RadixSort(array3,size);//计数排序
    printf("Array3 排序后）:\n");
    ShowArray(array3,size);
	return 0;
}
