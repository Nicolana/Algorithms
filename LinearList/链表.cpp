#include <iostream>

typedef int Status;
typedef int ElemType;

#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0


typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LinkList CreatList(LinkList &L){
    // 从表尾到表头逆向建立单链表L，每次均在头节点之后插入元素
    LNode *s; int x;

    // 创建头节点
    L = (LinkList) malloc(sizeof(LNode));
    L->next=NULL; // 初始化为空链表
    scanf("%d", &x); // 输入节点的值
    while (x != 9999){
        s = (LNode*)malloc(sizeof(LNode)); // 创建新节点
        s->data = x;
        s->next = L->next; // 将上一个节点的next 赋值给要插入的节点，这里为空
        L->next = s;    // 将新节点插入表中
        scanf("%d", &x);
    }
    return L;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

