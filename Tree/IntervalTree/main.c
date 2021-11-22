#include "IntervalTree.h"

int main() {
    srand((unsigned int)time(NULL));
    RBTreePointer Tree=NULL;
    Tree= Insert(Tree,(Item){10,rand()%10+10});
    Tree= Insert(Tree,(Item){11,rand()%10+10});

//    for(int i=0;i<10;i++){
//       Tree= Insert(Tree,(Item){i,rand()%10+i});
//    }
    Item interval1={119,12};
    RBTreePointer res=Interval_Search(Tree,interval1);
    printf("Low:%d High:%d Max:%d\n",res->data.low,res->data.high,res->max);
    InorderTraverse(Tree,Tree->P);
    return 0;
}
