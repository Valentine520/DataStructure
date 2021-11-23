#include <stdio.h>
#include "Loop_Queue.h"
#include <stdlib.h>
int main() {
    Loop_Queue queue;
    Initial(&queue);
    bool Judge_Em= QueueEmpty(&queue);
    bool Judge_Fu= QueueFull(&queue);
    size_t length= QueueLength(&queue);
    bool Judge_En=EnQueue(&queue,(Item){10});
    Item data;
    bool Judge_De= DeQueue(&queue,&data);
    printf("Judge_Em:%d\n",Judge_Em);
    printf("Judge_Fu:%d\n",Judge_Fu);
    printf("Judge_En:%d\n",Judge_En);
    printf("Judge_De:%d\n",Judge_De);
    printf("Length:%zd\n",length);
    for(int i=0;i<QUEUESIZE-2;i++){
        EnQueue(&queue,(Item){i*i+2});
    }
    Traverse(&queue);
    Judge_Fu= QueueFull(&queue);
    printf("Judge_Fu:%d\n",Judge_Fu);
    return 0;
}


