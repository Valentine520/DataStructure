#include "OpenHash.h"

int main() {
   Hash hash= Initial(100);
    printf("%d\n",hash->size);
    Insert(hash,10);
    Insert(hash,20);
    Insert(hash,30);
    Insert(hash,40);
    printf("Site:%d\n", Search(hash,20));
    printf("Site:%d\n", Search(hash,30));
    printf("Site:%d\n", Search(hash,40));
    printf("Site:%d\n", Search(hash,10));
    Delete(hash,10);
    printf("Site:%d\n", Search(hash,10));
    return 0;
}
