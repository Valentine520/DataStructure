#include <stdio.h>
#include "AVLtree.h"
#include <stdlib.h>

int main() {
    //insert_key(&Node,10);
//    insert_key(&Node,20);
//    insert_key(&Node,30);20
//利用返回值的形式进行值的传递 比直接使用地址传递更加容易理解 二级指针嵌套是真的不好写
    BSTNode *Node=NULL;
    Node= insert_recursion_balance(Node,10);
    Node= insert_recursion_balance(Node,11);
    Node= insert_recursion_balance(Node,2);
    Node= insert_recursion_balance(Node,19);
    Node= insert_recursion_balance(Node,20);
    traverse(Node);
    Node=AVLdelete(Node,11);
    Node=AVLdelete(Node,2);
    
    traverse(Node);
//    BSTNode *pretemp=NULL;
//    BSTNode *temp=NULL;
//    search(Node,40,&temp,&pretemp);
//    printf("pretemp:%d temp:%d\n",pretemp->data,temp->data);
//    if(temp==NULL){
//        fprintf(stderr,"fuck you!\n");
//    }
//    if(pretemp==NULL){
//        fprintf(stderr,"fuck you!\n");
//    }
//   bool fuck= deletew(&Node,10);
//    printf("fuck:%d\n\n",fuck);
//    traverse(Node);
}
