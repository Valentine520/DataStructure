#include "DisjointSet.h"

int main() {
    Set* set=(Set*) malloc(sizeof(Set)*10);
    for (int i=0;i<10;i++){
        set[i] = MakeSet(i+9);
    }
    if(FindSet(set[1])!=FindSet(set[2])){
        printf("Hello world\n");
    }
    Union(set[1],set[2]);
    if(FindSet(set[1])==FindSet(set[2])){
        printf("Success!\n");
    }
    
}
