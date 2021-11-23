#include <stdio.h>
#include "Polynomial.h"
int main() {
    Polynomial *P1;
    Polynomial *P2;
    Polynomial *P3;
    Initial(&P1);
    Initial(&P2);
    Initial(&P3);
    Create_Polynomial(P1);
    Create_Polynomial(P2);
    Print_Polynomial(P1);
    Print_Polynomial(P2);
    MultiplyPolyn(P1,P2,P3);
    Print_Polynomial(P3);
    printf("Success.\n!");
    return 0;
}
