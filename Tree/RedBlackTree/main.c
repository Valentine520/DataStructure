#include "RedBlackTree.h"

//The test function of RBTree

int main(void){
    RBTreePointer Tree=NULL;
    Tree= Insert(Tree,9);
    Tree= Insert(Tree,4);
    Tree= Insert(Tree,5);
    Tree= Insert(Tree,7);
    Tree= Insert(Tree,19);
    Tree= Insert(Tree,14);
    Tree= Insert(Tree,51);
    Tree= Insert(Tree,17);
    InorderTraverse(Tree,Tree->P);
    putchar('\n');
    bool fuck=RBDelete(&Tree,3);
    printf("%d\n",fuck);
    RBDelete(&Tree,14);
    RBDelete(&Tree,17);
    RBDelete(&Tree,51);
    InorderTraverse(Tree,Tree->P);
    return 0;
}