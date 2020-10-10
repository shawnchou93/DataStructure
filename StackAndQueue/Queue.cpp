/**
 * @Author: Shawn-Bo Zhou
 * @Description: Implement of queue, with test main function
 * @Parameters: 
 * @Return: 
 */
#include <stdio.h>

// defines
#define QUEUE_MAX_LENGTH 10

typedef struct
{
    int data[QUEUE_MAX_LENGTH]; //
    int front; // point to queue head
    int rear; // point to queue end
}MyQueue;

// functions

// initialize a queue
void initQueue(MyQueue* queue)
{
    for (int x = 0; x < QUEUE_MAX_LENGTH; x++)
    {
        queue->data[x] = 0;
    }
    queue->front = 0;
    queue->rear = 0;
}

// check empty
bool isEmpty(MyQueue* queue)
{
    if (queue->front == queue->rear)
        return true;
    else
        return false;
    
}

// check full, keep one data not use
bool isFull(MyQueue* queue)
{
    if ((queue->rear+1)%QUEUE_MAX_LENGTH == queue->front)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// get length
int getLength(MyQueue* queue)
{
    return ((queue->rear - queue->front + QUEUE_MAX_LENGTH) % QUEUE_MAX_LENGTH);
}

// pop
int pop(MyQueue* queue)
{
    if (isEmpty(queue) == true)
    {
        printf("queue is empty, pop error!\n");
        return false;
    }

    int temp = queue->data[queue->front];
    queue->data[queue->front] = 0;
    queue->front = (queue->front++) % (QUEUE_MAX_LENGTH);
    return temp;
}

// push
bool push(MyQueue* queue, int value)
{
    if (isFull(queue) == true)
    {
        printf("queue is full, push error!\n");
        return false;
    }
    
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear++) % QUEUE_MAX_LENGTH;
    return true;
}

// traverse queue
void traverseQueue(MyQueue* queue)
{
    if (isEmpty(queue) == true)
    {
        printf("queue is empty, traverse error!\n");
    }
    else
    {
        for (int x = 0; x < QUEUE_MAX_LENGTH; x++)
        {
            printf("%d ", queue->data[x]);
        }
        printf("\n");
    }
    
}


int main()
{
    MyQueue queue;

    initQueue(&queue);
    traverseQueue(&queue);
    printf("****************\n");

    for (int x = 0; x < QUEUE_MAX_LENGTH+1; x++)
    {
        push(&queue, x);
        traverseQueue(&queue);
        printf("queue length = %d\n", getLength(&queue));
        printf("****************\n");
    }

    for (int x = 0; x < QUEUE_MAX_LENGTH+1; x++)
    {
        (void)pop(&queue);
        traverseQueue(&queue);
        printf("queue length = %d\n", getLength(&queue));
        printf("****************\n");
    }
    


    return 0;
}


// end of file
