#include <stdio.h>
#include "QueueSimulate.h"

int main() {
    double AverageArriveTime=1;
    int RejectNum=0;
    int ServedNum=0;
    int WaitTime=0;
    SimulateQueue(AverageArriveTime,&RejectNum,&ServedNum,&WaitTime);
    printf("RejectNum:%3d ",RejectNum);
    printf("ServedNum:%3d ",ServedNum);
    printf("WaitTime :%3d ",WaitTime);
    return 0;
}
