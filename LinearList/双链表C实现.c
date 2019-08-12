#include <stdio.h>
#include <malloc.h>

typedef int Status;
typedef int ElemType;

#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0

type struct DNode{
  ElemType data;
  struct DNode *prior, *next;
}DNode, *DLinkList;

// 原型定义
DLinkList CreateList();

Status PrintDLink(DLinkList L);

int main(){
  DNode L;
  CreatList(&L);
  return 0;
}

DLinkList CreatList(){
  DLinkList L;
  DNode *s; int x;

  // 创建头节点
  L = (LinkList) malloc(sizeof(DNode));
  L->next = NULL;
  L->prior = NULL;

  // 传入元素
  scanf("%d", &x);
  while (x != 9999){
    s = (DNode*)malloc(sizeof(DNode));
    s->data = x;
    s->next = L->next;
    s->prior = L;
    L->next = s;
    scanf("%d", &x);
  }
  return L;
}

Status PrintDLink(DLinkList L){
  if (L == NULL){
    return FALSE;
  }

  printf("list = [");

  while (L->next != NULL){
    L = L->next;
    printf("%d", L->data);
  }

  printf("]\n")
}
