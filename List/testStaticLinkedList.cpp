/*
 * @Author: Shawn-Bo Zhou
 * @Date: 2020-07-11 22:09:52
 * @Description: test static linked list
 */ 

#include "StaticLinkedList.h"
#include "ListDataType.h"

int main(void)
{
    //测试构造
    List::StaticLinkedList testList;
    testList.traverseList();

    int a[5] = {1, 2, 3, 4, 5};
    List::StaticLinkedList testList2(a, 5);
    testList2.traverseList();
    printf("--------------\n");
    
    // 测试插入元素
    // (void)testList2.insertElement(3, 10);
    // testList2.traverseList();
    // printf("--------------\n");

    // (void)testList2.insertElement(6, 11);
    // testList2.traverseList();
    // printf("--------------\n");

    // (void)testList2.insertElement(1, 100);
    // testList2.traverseList();
    // printf("--------------\n");

    // (void)testList2.insertElement(0, 100);
    // testList2.traverseList();
    // printf("--------------\n");

    // (void)testList2.insertElement(-1, 100);
    // testList2.traverseList();
    // printf("--------------\n");

    // (void)testList2.insertElement(1000, 100);
    // testList2.traverseList();
    // printf("--------------\n");


    //测试删除节点
    printf("**********\n");
    testList2.deleteElement(2);
    testList2.traverseList();
    printf("--------------\n");

    testList2.deleteElement(5);
    testList2.traverseList();
    printf("--------------\n");

    testList2.deleteElement(1);
    testList2.traverseList();
    printf("--------------\n");




    





    return 0;
}


