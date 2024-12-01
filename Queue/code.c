#include <stdio.h>
#define MAX 5

struct Queue
{
    int arr[MAX];
    int front;
    int rear;
};
void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isFull(struct Queue *q)
{
    return q->rear == MAX - 1;
}
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full.\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = value;
}
int dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty, can't dequeue.\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->rear == q->front)
    {
        printf("Queue is empty, can't dequeue.\n");
    }
    q->front++;
    return value;
}
int peek(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty cant get peek value");
        return -1;
    }
    int value = q->arr[q->front];
    return value;
}
void printQueue(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty. \n");
        return;
    }
    printf("Elements are :");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d  ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue harsh;
    initializeQueue(&harsh);
    enqueue(&harsh, 10);
    enqueue(&harsh, 40);
    enqueue(&harsh, 13);
    printf("Dequed : %d\n ", dequeue(&harsh));
    printQueue(&harsh);
    printf("Peek value : %d \n", peek(&harsh));

    return 0;
}