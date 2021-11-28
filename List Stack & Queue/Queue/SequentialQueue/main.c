#include "queue.h"

int main() {
    Queue *queue = Initial(5);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Enqueue(queue,10);
    Show(queue);
    return 0;
}
