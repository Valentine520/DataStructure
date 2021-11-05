#include <stdio.h>
#include "Queue.h"
#include <stdlib.h>
static void Visit(Item data);
int main() {
    Queue queue;
    bool Judge_E= QueueEmpty(&queue);
    printf("Judge_E=%d\n",Judge_E);
    Initial(&queue);
    Judge_E= QueueEmpty(&queue);
    printf("Judge_E=%d\n",Judge_E);
    AddElem(&queue,(Item){10});
    DeleteElem(&queue);
    TraverseQueue(&queue,Visit);
    Back_Traverse(&queue,Visit);
    bool Judge_D= DeleteElem(&queue);
    printf("Judge_D=%d\n",Judge_D);
    TraverseQueue(&queue,Visit);
    Queue_Clear(&queue);
    Judge_E= QueueEmpty(&queue);
    TraverseQueue(&queue,Visit);
    Back_Traverse(&queue,Visit);
//    printf("Judge_E=%d\n",Judge_E);
//    bool Judge_Ex= Queue_Exist(&queue);
//    printf("%d\n",Judge_Ex);
//    Destroy(&queue);
//    Judge_Ex= Queue_Exist(&queue);
//    printf("%d\n",Judge_Ex);
    return 0;
}

static void Visit(Item data){
    printf("%d ",data.data);
}
