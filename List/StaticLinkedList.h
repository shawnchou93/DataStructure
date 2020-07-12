/*
 * @Author: Shawn-Bo Zhou
 * @Date: 2020-07-10 21:38:40
 * @Description: 
 */ 
#ifndef _STATICLINKEDLIST_H_
#define _STATICLINKEDLIST_H_

#include "ListDataType.h"
#include <stdio.h>
#include <iostream>


namespace List{

class StaticLinkedList // 静态链表
{
public:
    StaticLinkedList(); //构造链表
    StaticLinkedList(int*, int);
    ~StaticLinkedList();
    void traverseList(); //遍历链表
    bool isEmpty(); //判断链表是否为空
    int getLength(); //获取链表长度
    bool insertElement(int, int); //插入元素
    void sortList(); // 对链表进行排序,从大到小
    bool deleteElement(int); //删除元素
    bool clearList(); //清除整个链表
    int getFirstElementPos(); //获取第一个存放了值的元素在链表中的位置
    int getFirstEmptyPos(); //获取第一个没存放值的元素在链表中的位置


private:
    int m_length;
    int m_maxLength;
    SllNODE m_staticLinkedList[MAXLISTLENGTH];
    int m_firstElementCur;
    int m_firstEmptyEleCur;


protected:

};








} // namespace List









#endif //_STATICLINKEDLIST_H_
