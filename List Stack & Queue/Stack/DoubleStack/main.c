#include "DoubleStack.h"

int main(int argc, char *argv[]) {
    Stack S=Initial();
    printf("%d\n",IsEmpty(S));
    Push(S,1,10);
    printf("%d\n",IsEmpty(S));
    Push(S,2,10);
    printf("%d\n",IsEmpty(S));
    int data=Pop(S,1);
    printf("%d\n",IsEmpty(S));
    printf("data=%d\n",data);
    return 0;
}
