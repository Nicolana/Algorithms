#include <stdio.h>
// 二叉树链表存储

typedef int ElemType
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,rchild;
} BiTNode, *BiTree;

void visit(BiTNode *node){
  printf("%d", *node);
}

/**
  递归实现
*/

// 前序遍历
void PreOrder(BiTree T){
  if (T!=NULL){
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}

// 中序遍历
void InOrder(BiTree T){
  if (T != NULL){
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
  }
}

// 后序遍历
void PostOrder(BiTree T){
  if (T != NULL){
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
  }
}

/*
  非递归实现
*/
void InOrder2(BiTree T){
  // 二叉树采用中序遍历的非递归算法，需要借助一个栈
  InitStack(S); BiTree p=T;
  while (p || !IsEmpty(S)){
    if (p){
      Push(S, p);
      p = p->lchild;
    }
    else {
      Pop(S, p);visit(p);
      p = p->rchild;
    }
  }
}

/*层序遍历*/
void LevelOrder(BiTree T){
  InitQueue(Q);
  BiTree p;
  EnQueue(Q, T);
  while (!IsEmpty(Q)){
    DeQueue(Q, p);
    visit(p);
    if (p->lchild!=NULL)
      EnQueue(Q, p->lchild);
    if (p->rchild!=NULL)
      EnQueue(Q, p->rchild);
  }
}

int main(int argc, char const *argv[]) {

  return 0;
}
