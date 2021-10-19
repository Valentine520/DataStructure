//
// Created by 龙舌兰 on 2021/10/19.
//

#include "Sort.h"

//The implementation of shell sort

//The optimized of insert sort
void ShellSort(int *array,int size){
    //依次构造不同的间隔进行插入排序
    //使用Hibbard增量序列  不同增量序列对shell排序的时间复杂度改进效果不同
    int index=0;
    int factotial=2;
    while(factotial-1<size){
        array[index]= factotial-1;//构造序列
        factotial*=2;
        index++;
    }

    for(int hibbard=index-1;hibbard>=0;hibbard--){
        int dis=array[hibbard];
        //以不同间隔进行不同组的插入排序
        for(int i=0;i<dis;i++){
            //以dis为跨度
            for(int j=i+dis;j<size;j+=dis){
                int temp=array[j];
                int flag=0;
                for(int k=j-dis;k>=0;k-=dis){
                    if(temp<array[k]){
                        array[k+dis]=array[k];//移动数组元素
                    }
                    else{
                        array[k+dis]=temp;
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    array[i]=temp;
                }
            }
        }
    }
}


