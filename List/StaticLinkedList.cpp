/*
 * @Author: Shawn-Bo Zhou
 * @Date: 2020-07-10 21:38:25
 * @Description: static linked list
 */ 

#include "StaticLinkedList.h"

using namespace std;

namespace List{

    StaticLinkedList::StaticLinkedList()
    {
        //第一个元素的游标存放第一个未使用元素的下标，因此初始化时，第一个元素的游标存放0
        //最后一个元素的游标存放第一个使用元素的下标，初始化时，无已使用元素，因此存放0
        for(int i = 0; i < MAXLISTLENGTH-1; i++)
        {
            m_staticLinkedList[i].data = 0;
            m_staticLinkedList[i].cursor = i+1;
        }
        m_staticLinkedList[MAXLISTLENGTH-1].data = 0;
        m_staticLinkedList[MAXLISTLENGTH-1].cursor = 0;

        m_length = 0;
        m_maxLength = MAXLISTLENGTH;
    }

    StaticLinkedList::StaticLinkedList(int* arr, int arrlen)
    {
        //第一个元素的游标存放第一个未使用元素的下标，因此初始化时，第一个元素的游标存放0
        //最后一个元素的游标存放第一个使用元素的下标，初始化时，无已使用元素，因此存放0
        for(int i = 0; i < MAXLISTLENGTH-1; i++)
        {
            m_staticLinkedList[i].data = 0;
            m_staticLinkedList[i].cursor = i+1;
        }
        m_staticLinkedList[MAXLISTLENGTH-1].data = 0;
        m_staticLinkedList[MAXLISTLENGTH-1].cursor = 1;

        for (int j = 0; j < arrlen; j++)
        {
            // printf("arr[%d] = %d\n", j, arr[j]);
            m_staticLinkedList[j+1].data = arr[j];
            // printf("m_staticLinkedList[%d] = %d\n", j+1, m_staticLinkedList[j+1].data);
            
        }
        m_staticLinkedList[0].cursor = arrlen+1;
        m_staticLinkedList[arrlen].cursor = 0;
        
        m_length = arrlen;
        m_maxLength = MAXLISTLENGTH;
    }    

    StaticLinkedList::~StaticLinkedList()
    {

    }

    void StaticLinkedList::traverseList()
    {
        if(isEmpty())
        {
            printf("List is empty!\n");
        }
        else
        {
            int temp = getFirstElementPos();
            for (int i = 1; i <= m_length; i++)
            {  
                printf("The no.%d element(%d) is at %d\n", i, m_staticLinkedList[temp].data, temp);
                temp = m_staticLinkedList[temp].cursor;
                
            }
        }
        
    }

    int StaticLinkedList::getFirstElementPos()
    {
        m_firstElementCur = m_staticLinkedList[MAXLISTLENGTH-1].cursor;
        return m_firstElementCur;
    }

    int StaticLinkedList::getFirstEmptyPos()
    {
        m_firstEmptyEleCur = m_staticLinkedList[0].cursor;
        return m_firstEmptyEleCur;
    }

    bool StaticLinkedList::isEmpty()
    {
        if(m_length)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }

    int StaticLinkedList::getLength()
    {
        return m_length;
    }

    bool StaticLinkedList::insertElement(int pos, int val)
    {
        if(pos > m_maxLength-1 || pos <= 0)
        {
            printf("insert error!\n");
            return false;
        }

        if(pos == 1)
        {
            printf("pos == 1\n");
            //插入在pos，pos位置的data要变成val,连接后面一个节点
            m_staticLinkedList[m_length+1].data = val;
            m_staticLinkedList[m_length+1].cursor = pos;

            //前一个节点与新节点连接
            // 不需要

            //改变第一个节点的游标
            m_staticLinkedList[0].cursor = m_length+1+1;

            //改变最后一个节点的游标
            m_staticLinkedList[MAXLISTLENGTH-1].cursor = m_length+1;

            m_length++;

            return true;
        }

        if(pos == m_length+1)
        {
            printf("pos == m_length+1\n");
            //插入在pos，pos位置的data要变成val,连接后面一个节点
            m_staticLinkedList[m_length+1].data = val;
            m_staticLinkedList[m_length+1].cursor = 0;

            //前一个节点与新节点连接
            m_staticLinkedList[pos-1].cursor = m_length+1;

            //改变第一个节点的游标
            m_staticLinkedList[0].cursor = m_length+1+1;

            //改变最后一个节点的游标
            

            m_length++;
            return true;

        }
        
        //插入在pos，pos位置的data要变成val,连接后面一个节点
        m_staticLinkedList[m_length+1].data = val;
        m_staticLinkedList[m_length+1].cursor = pos;

        //前一个节点与新节点连接
        m_staticLinkedList[pos-1].cursor = m_length+1;

        //改变第一个节点的游标
        m_staticLinkedList[0].cursor = m_length+1+1;

        //改变最后一个节点的游标
               
        m_length++;

        return true;

    }

    bool StaticLinkedList::deleteElement(int pos)
    {
        if(pos > m_maxLength-1 || pos <= 0)
        {
            printf("delete error!\n");
            return false;
        }

        if(pos == 1)
        {
            printf("pos == 1\n");
            //删除pos节点，,连接后面一个节点
            m_staticLinkedList[pos].data = 0;
            m_staticLinkedList[pos].cursor = 0;

            //前一个节点与新节点连接
            // 不需要

            //改变第一个节点的游标
            m_staticLinkedList[0].cursor = pos;

            //改变最后一个节点的游标
            while(m_staticLinkedList[pos].cursor == 0)
            {
                pos++;
            }
            m_staticLinkedList[MAXLISTLENGTH-1].cursor = pos;

            m_length--;

            return true;
        }

        if(pos == m_length+1)
        {
            printf("pos == m_length+1\n");
            //删除最后一个，pos位置的data要变成val,连接后面一个节点
            m_staticLinkedList[m_length+1].data = 0;
            m_staticLinkedList[m_length+1].cursor = 0;

            //前一个节点与新节点连接
            m_staticLinkedList[pos-1].cursor = 0;

            //改变第一个节点的游标
            m_staticLinkedList[0].cursor = m_length-1;

            //改变最后一个节点的游标
            

            m_length--;
            return true;

        }
            
        //前一个节点与新节点连接
        m_staticLinkedList[pos-1].cursor = m_staticLinkedList[pos].cursor;

        //插入在pos，pos位置的data要变成val,连接后面一个节点
        m_staticLinkedList[pos].data = 0;
        m_staticLinkedList[pos].cursor = 0;

        //改变第一个节点的游标
        m_staticLinkedList[0].cursor = pos;

        //改变最后一个节点的游标
               
        m_length--;

        return true;
        
    }






}