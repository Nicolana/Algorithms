#include <stdio.h>

#define MaxSize 50
typedef int ElemType;

typedef struct {
  ElemType data[MaxSize];
  int tag;
  int front, rear;
} tagQueue;

// 基本操作
bool InitQueue(tagQueue *Q){
  Q->front = Q->rear = 0;
  Q->tag = 0; // 0 is empty, tag == MaxSize means queue is full
}

bool isEmpty(tagQueue Q){
  if (Q.tag == 0 && Q.front == Q.rear) return true;
  else return false;
}

bool EnQUeue(tagQueue *Q, ElemType x){
  if (Q->tag == 1 && Q->front == Q->rear) return false;
  Q->data[Q->rear] = x;
  Q->rear = (Q->rear + 1) % MaxSize;
  Q->tag = 1;
  return true;
}

bool DeQueue(tagQueue *Q, ElemType *x){
  if (isEmpty(Q)) return false;
  x = Q->data[Q->front];
  Q->front = (Q->front+1) % MaxSize;
  Q->data = 0;
  return true;
}

int int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
