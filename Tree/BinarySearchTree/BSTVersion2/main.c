#include "BinarySearchTree.h"
int main(void){
    NodePointer Tree=NULL;
    Tree= Insert(Tree,10);
    InorderTraverse(Tree);
    Delete(&Tree,10);//使用地址传递以修改Tree的值 遇到需要修改根节点时修改值
    InorderTraverse(Tree);
    return 0;
}