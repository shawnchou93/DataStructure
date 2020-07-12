/*
 * @Author: Shawn-Bo Zhou
 * @Date: 2020-07-05 18:07:18
 * @Description:
 *      动态链表的优点：1. 灵活的长度，需要节点就请求空间，不需要就释放空间，不像数组需要固定长度；
 *                      2. 节点离散存储，不需要一大片连续的空间。
 */ 

#include "LinkedList.h"

using namespace std;


namespace List{

/**
 * @Description: Constroctor function
 * @Parameters: 
 * @Return: 
 * @Author: Shawn-Bo Zhou
 */
LinkedList::LinkedList(int len, int* arr = NULL) //使用数组中的值来初始化链表
{
    if (len<0 || arr == NULL)
    {
        printf("数组长度小于0 或 数组指针为NULL！\n");
        assert(0);
    }
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); //创建头结点
    assert(pHead != NULL);
    PNODE pTail = pHead; //创建一个pTail，其与pHead存储同一个地址
    pTail->pNext = NULL; //令pTail指向的节点的指针域为NULL，同样的pHead指向的节点的指针域为NULL

    if (arr == NULL)
    {
        for (int i=0; i<len; i++)
        {
            PNODE pNew = (PNODE)malloc(sizeof(NODE)); //生成一个新的节点
            assert(pNew != NULL);
            pNew->data = 0; //初始化数据域的值全为0
            pTail->pNext = pNew; //新生成的节点的地址挂在pTail指向的节点的地址域，同样的新节点的地址挂在了pHead所指向的头结点的地址域。这样，第一次循环生成的节点与头结点连接在了一起
            pNew->pNext = NULL; //新节点的指针域为NULL
            pTail = pNew; //第一次循环生成的节点的地址给到pTail，供第二次循环时生成的节点与第一次生成的节点产生连接所用。在第二次循环中pTail=pHew1类比于第一次循环中pTail=pHead，以此类推，使新产生的节点与上一个节点连接
        }
    }
    else
    {
        for (int i=0; i<len; i++)
        {
            PNODE pNew = (PNODE)malloc(sizeof(NODE)); //生成一个新的节点
            assert(pNew != NULL);
            pNew->data = arr[i]; //初始化数据域的值全为数组的值
            pTail->pNext = pNew; //新生成的节点的地址挂在pTail指向的节点的地址域，同样的新节点的地址挂在了pHead所指向的头结点的地址域。这样，第一次循环生成的节点与头结点连接在了一起
            pNew->pNext = NULL; //新节点的指针域为NULL
            pTail = pNew; //第一次循环生成的节点的地址给到pTail，供第二次循环时生成的节点与第一次生成的节点产生连接所用。在第二次循环中pTail=pHew1类比于第一次循环中pTail=pHead，以此类推，使新产生的节点与上一个节点连接
        }
    }
       
    m_headNode = pHead;
    m_length = len;
};

LinkedList::~LinkedList()
{
    PNODE ptr = NULL;
    PNODE ptr1 = NULL;
    ptr = m_headNode->pNext;
    free(m_headNode);
    while(ptr)
    {
        ptr1 = ptr->pNext;
        free(ptr);
        ptr = ptr1;
    }  
}

void LinkedList::traverseList()
{
    PNODE p = this->m_headNode->pNext;

    while (NULL != p)
    {
        printf("%d ", p->data); //第一个输出值为：头结点指针域存储的地址所指向的节点的数据域存储的值
        p = p->pNext; //令p等于p指向的节点的指针域存储的地址，通过循环即可由printf函数输出下一个节点数据域存储的数据
    }
    printf("\n");
}

bool LinkedList::isEmpty()
{
    if (NULL == this->m_headNode->pNext)
    {
        // printf("链表为空！");
        return true;
    }
    else
    {
        // printf("链表不为空！");
        return false;
    }
        
}

int LinkedList::getLength()
{
    return m_length;
}

bool LinkedList::insertElement(int position, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = NULL;

    PNODE p1 = this->m_headNode->pNext;
    for (int i=0; i<position-2; i++)
    {
        p1 = p1->pNext;
    } //循环结束后，p1存放的是原链表第pos-1个节点的地址域
    PNODE p2;
    p2 = p1->pNext;
    p1->pNext = pNew;
    pNew->pNext = p2;

    m_length++;

    return true;
}

void LinkedList::sortList()
{
    PNODE p, q;;
    int t;
    int len = getLength();

    p=this->m_headNode->pNext;
    for (int i=0; i<len-2; i++)
    {
        q = p->pNext;
        for (int j=0; j<len-2-i; j++)
        {
            // printf("[%d, %d]\n", p->data, q->data);
            if (p->data < q->data)
            {
                t = q->data;
                q->data = p->data;
                p->data = t;
            }
            // printf("[%d, %d]\n", p->data, q->data);
            // printf("*******\n");
            q = q->pNext;
        }
        p=p->pNext;
    }
}

bool LinkedList::deleteElement(int position)
{
    PNODE p = this->m_headNode;
    PNODE p2;
    int len = getLength();
    if (NULL==this->m_headNode->pNext || position>len || position<0)
    {
        printf("链表为空 or 要删除的链表的元素位置大于链表的长度 or pos数据出错，无法进行删除元素操作，程序终止！\n");
        return false;
    }
    for (int i=0; i<position-1; i++)
    {
        p = p->pNext;
    } //循环结束，找到第pos-1个节点，p为第pos-1个节点的地址域存储的地址
    p2 = p->pNext;
    p->pNext = p->pNext->pNext;
    free(p2);

    return true;
}

bool LinkedList::clearList()
{
    //析构函数已经实现
    return 0;
}



} // namespace List
