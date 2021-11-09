//
// Created by 龙舌兰 on 2021/10/4.
//
#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000
//查找weight最小的节点
static int FindHuffMin(Huff *HT,int j);

void HuffmanCreate(Huff **HT,const Item *data,const int *w,int n){
    if(n<=1){
        fprintf(stderr,"Invalid num of n");
        return;
    }
    int m=2*n-1;//节点的总数
    *HT=(Huff*)malloc(sizeof(Huff)*(m+1));//多申请一个空间 0号位置用于作为一个flag 存放编码字符的个数
    if(*HT==NULL){
        fprintf(stderr,"Fail to alocate the memory.\n");
        return;
    }

    //初始化特殊0节点
    (*HT)[0].parent=-1;
    (*HT)[0].Rchild=-1;
    (*HT)[0].Lchild=-1;
    (*HT)[0].data='#';//表示为头节点
    (*HT)[0].weight=n;//存储编码数目

    //初始化非空节点
    int i=1;
    for(;i<n+1;i++){
        (*HT)[i].data=data[i-1];//data表示节点的内容
        (*HT)[i].parent=0;
        (*HT)[i].Lchild=0;
        (*HT)[i].Rchild=0;
        (*HT)[i].flag=1;
        (*HT)[i].weight=w[i-1];
    }
    for(;i<m+1;i++){
        (*HT)[i].data='*';//空节点 作为联结使用
        (*HT)[i].weight=0;
        (*HT)[i].flag=0;
    }

    //开始构造
    for(int j=n+1;j<m+1;j++){
        //查找其中最小的两个节点 包含已经构建好了的新节点
        int index1=FindHuffMin( (*HT),j);
        int index2= FindHuffMin( (*HT),j);
        (*HT)[j].Lchild=index1;
        (*HT)[j].Rchild=index2;
        (*HT)[j].weight= (*HT)[index2].weight+ (*HT)[index1].weight;
        (*HT)[j].flag=1;
        (*HT)[index1].parent=j;
        (*HT)[index2].parent=j;
    }
}


int FindHuffMin(Huff *HT,int j){
    if(j<=0){
        fprintf(stderr,"Invalid index.\n");
        return -1;
    }
    int min=MAX;
    int site=-1;
    for(int i=1;i<j;i++){
        if(HT[i].flag!=0) {
            if ((int) (HT[i].weight) < min) {
                min = (int) HT[i].weight;
                site = i;//保留其min下标
            }
        }
    }
    HT[site].flag=0;//修改其标记 避免重复使用 将待分配和新插入的节点作为待选区 其他的则不需要
    return site;
}

//构建HuffmanTree后开始编码
void HuffmanCode(Huff*HT,HuffmanTable*Table,int n){
    //构造完毕 开始编码
    *Table= (HuffmanTable) malloc(sizeof(char*)*(n+1));//赫夫曼表构建 n+1个节点 
    char *cd=(char*)malloc(sizeof(char)*(n));
    cd[n-1]='\0';
    for(int j=1;j<n+1;j++){
        int start=n-1;//起始位置 
        //向上  c= (HT)[c].parent向上移动
        for(int c=j; (HT)[c].parent!=0;c= (HT)[c].parent){
            if( (HT)[ (HT)[c].parent].Lchild==c){
                cd[--start]='0';
            }
            else{
                cd[--start]='1';
            }
        }
        (*Table)[j]= (char*)malloc(sizeof(char)*(n-start));
        for(int k=0;k<n-start;k++){
            (*Table)[j][k]=cd[start+k];
        }
    }
    printf("\n_____________________\n");
    free(cd);//释放临时工作空间
    for(int j=1;j<n+1;j++){
        printf("%c", (HT)[j].data);
    }
    printf("\n只属于你的编码格式为：\n");
    for(int j=1;j<n+1;j++){
        printf("%s\n",(*Table)[j]);
    }
}

//编码后开始解码
void SolveHuffmanCode(Huff *HT,HuffmanTable Table,Item **SolveTable,int n){
    *SolveTable=(Item*)malloc(sizeof(Item)*(n+1));
    int m=2*n-1;
    int root_site=-1;
    //找到根
    for(int i=1;i<m+1;i++){
        if(HT[i].parent==0){
            root_site=i;
            break;
        }
    }
    if(root_site<=0){
        fprintf(stderr,"invalid index.\n");
        return;
    }
    //解码
    for(int i=1;i<n+1;i++){
        int index=0;
        int site=root_site;
        while(Table[i][index]!='\0'){
            if(Table[i][index]=='1'){
                site=HT[site].Rchild;
            }
            else if (Table[i][index]=='0'){
                site=HT[site].Lchild;
            }
            else{
                fprintf(stderr,"Error!\n");
                return;
            }
            index++;
        }
        (*SolveTable)[i]=HT[site].data;
    }
    for(int i=1;i<n+1;i++){
        printf("编码:\' %s \'对应的字符为\'%c\'\n",Table[i],(*SolveTable)[i]);
    }
}