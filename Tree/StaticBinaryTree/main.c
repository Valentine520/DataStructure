#include <stdio.h>
#include "Static_Tree.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    //在创建时要保证合理性
    SBtree tree;
    int size;
    size=CreateTree(tree.Tree);
    int root_site=Root(tree.Tree,size);
    printf("%d\n",root_site);
    PreTraverse(tree.Tree,root_site);
    PostTraverse(tree.Tree,root_site);
    MidTraverse(tree.Tree,root_site);
    return 0;
}
