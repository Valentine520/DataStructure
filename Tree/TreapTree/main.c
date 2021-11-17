#include "TreapTree.h"

int main(int argc, char *argv[]) {
    srand((unsigned int)time(NULL));
    Treap tree=NULL;
    tree=Insert(tree, 10);
    tree=Insert(tree, 20);
    tree=Insert(tree, 12);
    tree=Insert(tree, 23);
    tree=Insert(tree, 11);
    tree=Insert(tree, 98);
    Delete(&tree,20);
    Delete(&tree,98);
    Traverse(tree);
    return 0;
}