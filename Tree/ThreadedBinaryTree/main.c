#include <stdio.h>
#include "ThreadedBinaryTree.h"
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    Node *Tree,*Pre;
    CreateBtree(&Tree);
    Single_Thread_Binary_Tree(Tree,Pre);
    Show(Tree);
    printf("Reverse:\n");
//  reverse(Tree);
    return 0;
}
