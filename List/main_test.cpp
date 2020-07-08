#include "LinkedList.h"
#include "ListDataType.h"

int main(void)
{
    //测试创建单链表
    int a[5] = {1, 2, 3, 4, 5};
    List::LinkedList testList(5, a);

    // 测试遍历
    testList.traverseList();

    //测试判断为空
    bool ret = testList.isEmpty();
    printf("ret(%d)\n", ret);

    //测试获取长度
    int len = testList.getLength();
    printf("length(%d)\n", len);

    //测试插入元素
    testList.insertElement(3, 10);
    testList.traverseList();
    printf("length(%d)\n", testList.getLength());

    //测试删除元素
    testList.deleteElement(4);
    testList.traverseList();
    printf("length(%d)\n", testList.getLength());

    //测试排序
    testList.sortList();
    testList.traverseList();


    return 0;


    
}


