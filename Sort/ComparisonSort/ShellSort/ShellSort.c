//
// Created by 周龙 on 2021/11/25.
//

#include "ShellSort.h"
extern int count_h;
extern int count_s;
extern int count_i;

//The implementation of shell sort

void ShellSort_S(int *array,int size){

    int i=0;
    int D=1;
    int buf[size];//保存Sedgewick增量序列
    while(D<=size){
        D=9*(int)pow(4,i)-9*(int)pow(2,i)+1;
        buf[i++]=D;
    }
    //利用sedgewick增量序列作为跨度
    for(int j=i-1;j>=0;j--){
        int sed=buf[j];
        for(int k=0;k<sed;k++){
            for(int n=k+sed;n<size;n++){
                int temp=array[n];
                int m=n-sed;
                for(;m>=0;m-=sed){
                    if(array[m]>temp){
                        count_s++;//记录进行的比较的次数
                        array[m+sed]=array[m];
                    }
                    else{
                        break;
                    }
                }
                array[m+sed]=temp;
            }
        }
    }
}

void ShellSort_H(int *array,int size){
    //依次构造不同的间隔进行插入排序
    //使用Hibbard增量序列  不同增量序列对shell排序的时间复杂度改进效果不同
    int count=0;//记录Hibbard序列的长度
    int factotial=2;
    int buf[size];
    while(factotial<=size){
        buf[count]= factotial-1;//构造序列
        factotial*=2;
        count++;
    }
    //利用hibbard增量序列 从后往前 从大到小归并
    for(int hibbard=count-1;hibbard>=0;hibbard--){

        int dis=buf[hibbard];
        //以不同间隔进行不同组的插入排序
        for(int i=0;i<dis;i++){
            //以dis为跨度
            for(int j=i+dis;j<size;j+=dis){
                int temp=array[j];
                int k=j-dis;//记录最终的空穴位置
                for(;k>=0;k-=dis){
                    if(temp<array[k]){
                        array[k+dis]=array[k];//移动数组元素 以dis为间隔
                        count_h++;//记录比较的次数
                    }
                    else{
                        break;
                    }
                }
                array[k+dis]=temp;
            }
        }
    }
}

void InsertSort(int *array,int size){
    int temp;
    for(int i=1;i<size;i++){
        temp=array[i];
        for(int j=i-1;j>=0;j--){
            if(array[j]>temp){
                count_i++;
                array[j+1]=array[j];
            }
            else{
                break;
            }
            array[j+1]=temp;//空穴位置
        }
    }
}

void ShowArray(const int *array ,int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
        if((i+1)%10==0){
            putchar('\n');
        }
    }
    putchar('\n');
}