#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

//    insert_key(&Node,10);
//    insert_key(&Node,20);
//    insert_key(&Node,30);20
//利用返回值的形式进行值的传递 比直接使用地址传递更加容易理解 二级指针嵌套是真的不好写
    BSTNode *Node=(BSTNode*)malloc(sizeof(BSTNode));
    insert_key(&Node, 10);
    traverse(Node);
    delete(&Node,10);
    traverse(Node);
    return 0;
}
