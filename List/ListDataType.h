#ifndef _LISTDATATYPE_H_
#define _LISTDATATYPE_H_

#include <iostream>

typedef struct node  //创建结构体变量
{
    int data; // 数据域
    struct node * pNext; // 指针域
}NODE, * PNODE; // typedef定义，NODE表示struct node，PNODE表示struct node*




#endif // _LISTDATATYPE_H_
