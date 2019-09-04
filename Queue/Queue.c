#include <stdio.h>
// 循环队列实现
#define MaxSize 50
typedef int ElemType;

typedef struct{
  ElemType data[MaxSize];
  int front, rear;
} SqQueue;

// 基本操作
void InitQueue(*Q){
  Q.rear = Q.front = 0;
}

bool isEmpty(Q){
   if (Q.rear == Q.front) return true;
   else return false;
}

bool EnQueue(SqQueue *Q, ElemType x){
  if ((Q.rear + 1)%MaxSize==Q.front) return false;
  Q.data[Q.rear] = x;
  Q.rear = (Q.rear + 1)%MaxSize;
  return true;
}

bool DeQueue(SqQueue *Q, ElemType *x){
  if (isEmpty(Q)) return false;
  x = Q.data[Q.front];
  Q.front = (Q.front+1)%MaxSize;
  return true;
}

int int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
