#include <stdio.h>
#include <stdlib.h>
#include "HuffmanTree.h"
int main() {
    Huff *HT;
    HuffmanTable table;
    char data[]={'C','Z','W',' ','M','Y',' ','D','E','A','R',' ','L','O','V','E','R'};
    int size=sizeof(data)/sizeof(data[0]);
    int weight[size];

    for(int i=size;i>=0;i--){
        weight[size-i]=i;
    }
    HuffmanCreate(&HT,data,weight,size);
    HuffmanCode(HT,&table,size);
    Item *solve_table=NULL;
    SolveHuffmanCode(HT,table,&solve_table,size);
    return 0;
}
