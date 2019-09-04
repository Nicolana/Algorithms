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
DLinkList DelDNodePrior(DLinkList q);

int main(){
  DLinkList L;
  L = CreateList(L);
  PrintDLink(L);
  return 0;
}

DLinkList CreateList(DLinkList L){
  // 閸掓稑缂撴径纾嬪Ν閻愶�