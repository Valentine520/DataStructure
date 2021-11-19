#include "LinkHash.h"

int main() {
    srand((unsigned int)time(NULL));
    Hash T= Initial(100);
    for(int i=0;i<1000;i++){
        Insert(T,rand()%100);
    }
    Traverse(T);
    return 0;
}
