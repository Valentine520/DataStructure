#include <stdio.h>
#include "SString.h"
int main() {
    SString S1,S2,S3;
    StrAssign(S1,"hello");//字符串字面量
    TraverseString(S1);
    printf("The length of S1 is :%d\n",S1[0]);
    StrAssign(S2," world");
    TraverseString(S2);
    printf("The length of S2 is %d\n",S2[0]);
    Concat(S3,S1,S2);
    printf("S3:\n");
    TraverseString(S3);
    StrInset(S3,S1,2);
    TraverseString(S3);
    StrDelete(S3,2,4);
    TraverseString(S3);
    int index=Index_SubStr("baabaabbaaaaaba","aaaab");
    printf("%d\n",index);
    return 0;
}
