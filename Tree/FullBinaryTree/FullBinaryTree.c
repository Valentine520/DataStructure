#include <stdio.h>
#include <stdlib.h>

//借助静态数组保存完全二叉树

#define MAXSIZE 100
int main() {
    int tree[MAXSIZE];
    for(int i=0;i<MAXSIZE;i++){
        tree[i]=-1;
    }
    int data;
    int index;
    int count=0;
    int Limit;
    printf("Please enter the number of your binary tree.\n");
    scanf("%d",&Limit);
    while(count<Limit){
        printf("Please enter the index and data of node.\n");
        scanf("%d %d",&data,&index);
        if(index<0||index>MAXSIZE){
            fprintf(stderr,"Invalid index.\n");
            exit(EXIT_FAILURE);
        }
        tree[index]=data;
        count++;
        while(getchar()!='\n'){
            continue;
        }
    }
    int fuck=0;
    int site=0;
    while(fuck<=count){
        if(tree[site]!=-1) {
            printf("%d\n",tree[site]);
            fuck++;
            site++;
        }
    }
}
