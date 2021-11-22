#include "Order_Statistic_Tree.h"

int main(void) {
    RBTreePointer Tree=NULL;
   for(int i=0;i<30;i++){
       Tree= Insert(Tree,i);
   }
    InorderTraverse(Tree,Tree->P);
    printf("The rank i:\n");
    RBTreePointer Res=OS_SELECT(Tree,8);
    printf("%d\n", OS_RANK(Tree,Res));
    int res= OS_RANK_ELEMENT(Tree,10);
    printf("%d\n",res);
    res= OS_RANK_ELEMENT(Tree,29);
    printf("%d\n",res);
    return 0;
}
