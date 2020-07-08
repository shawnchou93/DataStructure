#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include "ListDataType.h"

using namespace std;

namespace List{

class LinkedList // 单链表
{
public:
    LinkedList(int, int*); //构造链表
    ~LinkedList();
    void traverseList(); //遍历链表
    bool isEmpty(); //判断链表是否为空
    int getLength(); //获取链表长度
    bool insertElement(int, int); //插入元素
    void sortList(); // 对链表进行排序,从大到小
    bool deleteElement(int); //删除元素
    bool clearList(); //清除整个链表


private:
    PNODE m_headNode;
    int m_length;


protected:

};

} // namespace List



#endif // _LINKEDLIST_H_
