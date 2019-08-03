#include <iostream>
using namespace std;

// 基本定义
#define LIST_INIT_SIZE 79
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0

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
ListDelete(SqList &L, int i, ElemType &e);   // 删除操作。删除表L中第i个位置的元素，并用e返回删除元素的值
PrintList(SqList L);                        // 输出操作。按前后顺序输出线性表L的所有元素值。
Empty(SqList L);                            // 判空操作。 若L为空表，则返回true， 否则返回 false 
DestoryList(SqList &L);                     // 销毁操作。 销毁线性表，并释放线性表L所占用的内存空间

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}


Status InitList(SqList &L){
    // 构造一个空的线性表L
    // L.data = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));  // C语言动态分配语句
    L.data = new ElemType[LIST_INIT_SIZE]; // C++ 动态分配语句
    if (!L.data){
        cout << "分配失败" << endl;
        return ERROR;
    }
    L.length = 0;
    L.MaxSize = LIST_INIT_SIZE;
    return OK;
}

Status Length(SqList L){
    if (L.data)
        return L.length;
    return ERROR;
}
int LocateElem(SqList L, ElemType e){
    // 查找到则返回函数位置，否则返回0
    int i;
    for (i=0; i<L.length;i++){
        if (L.data[i]==e)
            return i+1;
    }
    return 0;
}

ElemType GetElem(SqList L, int i){
    // 根据下标返回线性表中的元素，若该小标不存在则返回一个空的元素
    ElemType e;
    if (L.data && i >= 1 && i<=L.length){
        e = L.data[i];
    }
    return e;
}

Status ListInsert(SqList &L, int i, ElemType e){
    // 判断操作是否有效
    if (i <=0 || i > L.length)
        return ERROE;
    if (L.length > L.MaxSize){
        return ERROR;
    }
    // 第i个元素及之后的元素向后移动
    for (int j=L.length; j>=i;j--)
        L.data[j+1] = L.data[j];
    L.data[i-1] = e;
    L.length++;
    return OK;
}



