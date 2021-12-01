#include "ShellSort.h"
#define MAXSIZE 10988
#define MAXTIME 109
int count_h;//记录比较次数
int count_s;
int count_i;
int main(void){
    //测试使用不同增量序列的性能差异
    srand((unsigned int)time(NULL));
    int Counts[MAXTIME];
    int Counth[MAXTIME];
    int Counti[MAXTIME];
    for(int i=0;i<MAXTIME;i++){
        int array1[MAXSIZE];
        int array2[MAXSIZE];
        int array3[MAXSIZE];
        for(int j=0;j<MAXSIZE;j++){
            array1[i]=rand()%19822;
            array2[i]=rand()%39821;
            array3[i]=rand()%30982;
        }
        InsertSort(array1,MAXSIZE);
        ShellSort_H(array2,MAXSIZE);
        ShellSort_S(array3,MAXSIZE);
        Counts[i]=count_s;
        Counth[i]=count_h;
        Counti[i]=count_i;
        count_s=0;
        count_h=0;
        count_i=0;
    }
    printf("Pure Insert:\n");
    ShowArray(Counti,MAXTIME);
    printf("Hibbard:\n");
    ShowArray(Counth,MAXTIME);
    printf("Sedgewick:\n");
    ShowArray(Counts,MAXTIME);
    return 0;
}

