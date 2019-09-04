#include <stdio.h>
#include <stdlib.h>
// 队列得链式存储

typedef int ElemType;

typedef struct {
  ElemType data;
  struct LinkNode *next;
} LinkNode;

typedef struct {
  LinkNode *front, *rear;
} LinkQueue;

// 基本操作
void InitQueue(LinkQueue *Q){
  Q.front = Q.rear = (LinkNode*) malloc(sizeof(LinkNode)); // 建立头节点
  Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q){
  if (Q.front == Q.rear) return true;
  else return false;
}

void EnQueue(LinkQueue *Q, ElemType x){
  s = (LinkNode *)malloc(sizeof(LinkNode)); // 创建一个新得节点
  s->data = x; s->next = NULL;
  Q.rear->next = s;
  Q.rear = s;
}

bool DeQueue(LinkNode *Q, ElemType *x){
  if (isEmpty()) return false;
  LinkNode *p;
  p = Q.front->next;
  x = p->data;
  Q.front->next=p->next;
  if (Q.rear == p) Q.rear = Q.front; // 如果 队尾
  free(p);
  return true;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
