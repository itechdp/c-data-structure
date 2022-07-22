#include<stdio.h>
#include<Stdlib.h>

struct queue{

int size;
int rear; 
int front;
int *arr;

};

int isEmpty(struct queue *que)
{
    if(que->rear == que->front)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int isFull(struct queue *que)
{
    if(que->rear == que->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *que,int data)
{
    if(isFull(que))
    {
        printf("Queue is full cannot add more elements");
    }
    else
    {
        que->rear++;
        que->arr[que->rear] = data;
        printf("%d is added to the queue",data);
    }
}

int dequeue(struct queue *que)
{
    int a = -1;
    if(isEmpty(que))
    {
        printf("Cannot remove elements queue is empty");
    }
    else
    {
        que->front++;
        a = que->arr[que->front];
        printf("%d is removed from the queue",a);
    }
    return a;
}

int main()
{
    struct queue dp;
    dp.size = 5;
    dp.rear = -1;
    dp.front = -1;
    dp.arr = (int *)malloc(dp.size * sizeof(int));
    enqueue(&dp,10);
}