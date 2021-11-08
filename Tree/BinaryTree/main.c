#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
void ms_gets(char ch);
int main() {
    //不能出现数据重复的节点
    Node *BT=(Node*)malloc(sizeof(Node));
    BT->data=10;
    BT->Lchild=NULL;
    BT->Rchild=NULL;
    for(int i=0;i<5;i++){
        Insert(BT,11+i);
    }
    printf("先序遍历:\n");
    int size=FTraverseBtree(BT);
    printf("The size of tree is %d\n",size);
    printf("中序遍历:\n");
    MTraverseBtree(BT);
    printf("后序遍历:\n");
    LTraverseBtree(BT);
    printf("层序遍历:\n");
    StepTraverse(BT);//层序遍历
    DeleteNode(BT,11);
    printf("After delete:\n");
    FTraverseBtree(BT);
//  int fuck1,fuck2;
//    MTraverseBtree(BT);
//    LTraverseBtree(BT);
//    int length= BtreeDepth(BT);
//    printf("The length of Btree is %d\n",length);
//    ShowTargetNode(BT,10);
//    LTraverseBtree(BT);
//    AssignValue(BT,10,2021);
//    LTraverseBtree(BT);
//    ShowTargetNode(BT,10);
//    Node *temp=NULL;
//    bool judge=SearchBtree(BT,10,&temp);
//
//    printf("The judge is %d\n",judge);
//    ClearTree(&BT);//清空节点
//    LTraverseBtree(BT);
//    fuck=BtreeEmpty(BT);
//    printf("%d\n",fuck);
//
    return 0;
}

