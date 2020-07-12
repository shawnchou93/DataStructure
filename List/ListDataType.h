/*
 * @Author: Shawn-Bo Zhou
 * @Date: 2020-07-05 18:12:35
 * @Description: 
 */ 
#ifndef _LISTDATATYPE_H_
#define _LISTDATATYPE_H_

#include <iostream>

// for linked list 
typedef struct node  //创建结构体变量
{
    int data; // 数据域
    struct node * pNext; // 指针域
}NODE, * PNODE; // typedef定义，NODE表示struct node，PNODE表示struct node*


// for static linked list
#define MAXLISTLENGTH 100
typedef struct SllNode
{
    int data;
    int cursor; //游标
}SllNODE;

// SllNODE StaticLinkedList[MAXLISTLENGTH];


#endif // _LISTDATATYPE_H_
