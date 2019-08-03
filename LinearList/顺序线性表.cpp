#include <iostream>

// 基本定义
#define LIST_INIT_SIZE 79
typedef int ElemType;
typedef int Status;
/*
 * 静态顺序存储
#define MaxSize 50

typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;
*/

/*
 *动态分配
 * */
typedef struct {
    ElemType *data;
    int MaxSize, length;
}SqList;

// 基本操作
InitList(SqList &L);                        // 初始化表，构造一个空的线性表
Length(SqList L);                           // 求表长，返回线性表L的长度，即L中数据元素的个数
LocateElem(SqList L, ElemType e);           // 按值查找操作。在表L中查找具有给定关键字值的元素
GetElem(SqList L, int i);                   // 按位查找操作。获取表L中第i个位置的元素的值
ListInsert(SqList &L, int i, ElemType e);   // 插入操作。在表L中第i个位置上插入指定元素e。
ListDelete(SqList &L, int i, ElemType e);   // 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
PrintList(SqList L);                        // 输出操作。按前后顺序输出线性表L的所有元素值。
Empty(SqList L);                            // 判空操作。 若L为空表，则返回true， 否则返回 false 
DestoryList(SqList &L);                     // 销毁操作。 销毁线性表，并释放线性表L所占用的内存空间

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


Status InitList(SqList &L){

}
