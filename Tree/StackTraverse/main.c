
#include <stdio.h>
#include "STACKTRAVERSE.h"
#include <stdlib.h>
int main() {
    Node *Btree;
    CreateBtree(&Btree);
    printf("PreorderTraverse");
//    PreorderTraverse(Btree);
    printf("InorderTraverse\n");
    InorderTraverse(Btree);
    printf("PreorderTraverse\n");
    PreorderTraverse(Btree);
    printf("PostorderTraverse\n");
    PostorderTraverse(Btree);
    printf("PostorderTraverse in 2 stack:\n");
    PostorderTraverse2(Btree);
    return 0;
}
