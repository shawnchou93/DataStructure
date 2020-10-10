/**
 * @Author: Shawn-Bo Zhou
 * @Description: Implement of linked queue, with test main function
 * @Parameters: 
 * @Return: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// create node
typedef struct node
{
    int data;
    struct node* pNext;
    
}Node, *pNode;

// create a queue
typedef struct
{
    pNode front;
    pNode rear;

}linkedQueue;

// initialize linked queue
void initQueue(linkedQueue* lq)
{
    // len = 2 for a initialized queue
    lq->front = (pNode)malloc(sizeof(Node));
    lq->rear = (pNode)malloc(sizeof(Node));
    lq->front->data = 0;
    lq->front->pNext = lq->rear;
    lq->rear->data = 0;
    lq->rear->pNext = NULL;
}

// check empty
bool isEmpty(linkedQueue* lq)
{
    if (lq->front == lq->rear)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

// check full

// get length
int getLength(linkedQueue* lq)
{
    int len = 0;
    if (isEmpty(lq))
    {
        return len;
    }

    pNode tmpNode = lq->front;
    while(tmpNode->pNext != NULL)
    {
        len++;
        tmpNode = tmpNode->pNext;
    }
    len++;
    return len;
}

// traverse queue
void traverseQueue(linkedQueue* lq)
{
    if (isEmpty(lq))
    {
        printf("Queue is empty!\n");
    }

    pNode tmpNode = lq->front;
    for (; tmpNode->pNext != NULL; tmpNode = tmpNode->pNext)
    {
        printf("%d ", tmpNode->data);
    }
    printf("%d ", tmpNode->data); // print the last node
    printf("\n");
}

// pop
int pop(linkedQueue* lq)
{
    if (isEmpty(lq))
    {
        printf("queue is empty\n");
        return -1;
    }
    int temp = 0;
    pNode tmpNode = NULL;

    temp = lq->front->data;

    tmpNode = lq->front;
    lq->front = lq->front->pNext;
    free(tmpNode);

    return temp;
}

// push
bool push(linkedQueue* lq, int val)
{
    // create node to push
    pNode temp = (pNode)malloc(sizeof(Node));
    assert(temp != NULL);
    temp->data = val;
    temp->pNext = NULL;

    // push
    lq->rear->pNext = temp;
    lq->rear = temp; // rear node moves backwards

    return true;

}

// destroy queue
void destroyQueue(linkedQueue* lq)
{
    pNode tmpNode = lq->front;
    while(tmpNode)
    {
        tmpNode = lq->front->pNext;
        free(lq->front);
        lq->front = tmpNode;
    }
}

// clear queue
void clearQueue(linkedQueue* lq)
{
    pNode tmpNode = lq->front;
    while(tmpNode->pNext != NULL)
    {
        tmpNode->data = 0;
        tmpNode = tmpNode->pNext;
    }
    tmpNode->data = 0;
}

int main()
{

    // create head node;
    linkedQueue lq;
    initQueue(&lq);
    printf("queue length = %d\n", getLength(&lq));
    printf("**************\n");

    printf("status[%d]\n", push(&lq, 1));
    printf("queue length = %d\n", getLength(&lq));
    traverseQueue(&lq); // 0 0 1
    printf("status[%d]\n", push(&lq, 2));
    traverseQueue(&lq); // 0 0 1 2
    printf("**************\n");

    clearQueue(&lq);
    traverseQueue(&lq);

    printf("pop val[%d]\n", pop(&lq));
    printf("pop val[%d]\n", pop(&lq));
    printf("pop val[%d]\n", pop(&lq));
    printf("pop val[%d]\n", pop(&lq)); // return -1

    // destroyQueue(&lq);
    // traverseQueue(&lq);
    


    return 0;
}

// end of file

