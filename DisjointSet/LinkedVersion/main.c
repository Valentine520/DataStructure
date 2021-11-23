#include <stdio.h>
#include "LinkedDisjointSet.h"
int main() {
    Set set[10];
    for(int i=0;i<10;i++){
        set[i]= MakeSet(i);
    }
    printf("%d\n", Find(set[1],set[2]));
    Union(set[1],set[2]);
    printf("%d\n", Find(set[1],set[2]));
    return 0;
}
