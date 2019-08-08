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
    L->next=NULL;                               // 初始化为空链表
    scanf("%d", &x);                            // 输入节点的值
    while (x != 9999){
        s = (LNode*)malloc(sizeof(LNode));      // 创建新节点
        s->data = x;
        s->next = L->next;                      // 将上一个节点的next 赋值给要插入的节点，这里为空
        L->next = s;                            // 将新节点插入表中
        scanf("%d", &x);
    }
    return L;
}

LinkList CreateList2(LinkList &L){
    // 从表头到表尾正向建立单链表L，每次均在表尾插入元素
    int x;

    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;       // s 为头节点，r为表尾节点
    scanf("%d", &x);
    while (x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; // r 指向s
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, int i){
    int cont=1; // 计数， 初始化为1
    LNode *p=L->next; // 头结点赋值给p
    if (i==0) // i== 0 即第一个元素
        return L;
    if (i<1)
        return NULL;
    while (p && j<i){
        p=p->next;
        j++
    }
    return p;
}

LNode *LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    while (p != NULL && p->data != e){
        p = p->next;
    }
    return p;
}

Status ListInsert(LinkList &L, int i, ElemType e){
    LNode *p = GetElem(L, i-1);
    LNode *s;
    s->next = p->next;
    s->data = e;
    p->next = s;

}


int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

