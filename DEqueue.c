#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
    int front;
    int rear;
    int *arr;
    int size;
};

int isFull(struct DEqueue *ptr)
{
    if (ptr->rear == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct DEqueue *ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueueF(struct DEqueue *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Queue is full cannot add element");
    }
    else
    {
        ptr->front++;
        ptr->arr[ptr->front] = data;
        printf("\n%d is added to the queue", data);
    }
}

void enqueueR(struct DEqueue *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("\nQueue is full cannot add element");
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = data;
        printf("\n%d is added to the queue", data);
    }
}

void dequeueF(struct DEqueue *ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        printf("\nQueue is empty data cannot be removed");
    }
    else
    {
        value = ptr->arr[ptr->front];
        ptr->front++;
        printf("\n%d is removed front the queue", value);
    }
}

void dequeueR(struct DEqueue *ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        printf("\nQueue is empty data cannot be removed");
    }
    else
    {
        value = ptr->arr[ptr->rear];
        ptr->rear--;
        printf("\n%d is removed front the queue");
    }
}

void Traversal(struct DEqueue *ptr)
{
    if (ptr->rear > ptr->front)
    {
        while (ptr->front != ptr->rear)
        {
            printf("\n%d Element of the queue", ptr->arr[ptr->front++]);
        }
    }
    else if (ptr->front > ptr->rear)
    {
        while (ptr->rear != ptr->front)
        {
            printf("\n%d Element of the queue", ptr->arr[ptr->rear++]);
        }
    }
    else
    {
        printf("\n%d Element of the queue", ptr->arr[ptr->rear]);
    }

}

int main()
{
    struct DEqueue *dp;
    dp->front = dp->rear = -1;
    dp->size = 10;
    dp->arr = (int *)malloc(dp->size * sizeof(int));
    enqueueF(dp, 23);
    enqueueR(dp, 30);
    enqueueF(dp, 45);
    dequeueF(dp);
    dequeueR(dp);
    Traversal(dp);
}