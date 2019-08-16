#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int Status;
typedef int ElemType;

#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0

typedef struct DNode{
  ElemType data;
  struct DNode *prior, *next;
}DNode, *DLinkList;

// 閸樼喎鐎风€规矮绠�
DLinkList CreateList(DLinkList L);
void PrintDLink(DLinkList L);

int main(){
  DLinkList L;
  L = CreateList(L);
  PrintDLink(L);
  return 0;
}

DLinkList CreateList(DLinkList L){
  // 閸掓稑缂撴径纾嬪Ν閻愶拷
  L = (DLinkList) malloc(sizeof(DNode));
  L->next = NULL;
  L->prior = NULL;
  DNode *s, *p = L; // p 灏炬寚閽�

  int x;
  // 娴肩姴鍙嗛崗鍐
  scanf("%d", &x);
  while (x != 9999){
    s = (DLinkList)malloc(sizeof(DNode));
    s->data = x;
    s->prior = p;
    // s->prior->next = s;
    p->next = s;
    p = s; // 绉诲姩灏炬寚閽�
    scanf("%d", &x);
  }
  return L;
}

void PrintDLink(DLinkList L){
  DNode *s = L->next;
  printf("L = [");
  if (s != NULL){
    printf("%d", s->data);
    s = s->next;
  }
  while (s != NULL){
    printf(",%d", s->data);
    s = s->next;
  };
  printf("]\n");
}
