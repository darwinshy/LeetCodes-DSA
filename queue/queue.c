#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int start_pointer, end_pointer, size;
    unsigned capacity;
    int *data;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->capacity = capacity;
    queue->size = 0;
    queue->start_pointer = 0;
    queue->end_pointer = capacity - 1;
    return queue;
}

// Member Functions
int isQueueFull(struct Queue *queue)
{
    return (queue->capacity == queue->size);
}
int isQueueEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}
void enQueue(struct Queue *queue, int newItem)
{
    if (isQueueFull(queue))
        return;

    queue->end_pointer++;
    queue->size++;
    queue->data[queue->end_pointer] = newItem;
    printf("New item added to the queue : %d\n", &newItem);
}

int deQueue(struct Queue *queue)
{
    if (isQueueEmpty(queue))
        return;
    int itemRemoved = queue->data[queue->start_pointer];
    queue->start_pointer++;
    queue->size--;
    printf("Item removed from the queue : %d\n", &itemRemoved);

    return itemRemoved;
}

int firstItem(struct Queue *queue)
{
    if (isQueueEmpty(queue))
        return;
    return queue->data[queue->start_pointer];
}
int lastItem(struct Queue *queue)
{
    if (isQueueEmpty(queue))
        return;
    return queue->data[queue->end_pointer];
}