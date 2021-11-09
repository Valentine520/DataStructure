#include <stdio.h>
#include "Tree.h"
#include <stdlib.h>

int main() {
    //先建树
    BinaryTree *Tree = NULL;
    int n = 0;
    printf("Please enter the num of tree.\n");
    scanf("%d", &n);
    while (getchar() != '\n') {
        continue;
    }
    int index = 0;
    while (index++ < n) {
        printf("Please enter the size of your data.\n");
        int size;
        scanf("%d", &size);
        while (getchar() != '\n') {
            continue;
        }
        Tree = Create_Binary_Tree(Tree, size);
        int times;
        printf("Please enter the times of your compare.\n");
        scanf("%d",&times);
        for (int i = 0; i < times; i++) {
            if (Judege_Binary_Tree(Tree, size)) {
                printf("OK!\n");
            } else {
                printf("Fail!\n");
            }
            Recite(Tree);//重置flag
        }
    }
    return 0;
}
