#include <Stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
};

int isFull(struct queue *q)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full cannot add elements");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
        printf("Enqueue operation performed successfully");
    }
}

int dequeue(struct queue *q)
{
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        value = q->arr[q->front];
        printf("Dequeue operation perfomend successfuly");
        
    }
    return value;
    
}

int main()
{
    struct queue dp;
    dp.size = 10;
    dp.front = -1;
    dp.rear = -1;
    dp.arr = (int *)malloc(dp.size * sizeof(int));
    enqueue(&dp,23);
    dequeue(&dp);
    dequeue(&dp);
}