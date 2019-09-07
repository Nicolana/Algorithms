#include <stdio.h>

typedef int ElemType
typedef struct ThreadNode{
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;


// 通过中序遍历对二叉树线索化
void InThread(ThreadTree &T, ThreadTree &pre){
  if (T != null){ // 节点不为空
    InThread(p->lchild, pre);
    if (T->lchild == NULL){
      T->lchild = pre;
      T->ltag = 1;
    }
    if (pre != NULL&&pre->rchild==NULL){
      pre->rchild = T;
      pre->rtag = 1;
    }
    pre = T; // 标记当前结点为刚刚访问过的节点
    InThread(T->rchild, pre);
  } // if (T != NULL)
}
void CreateInThread(ThreadTree T){
  ThreadTree pre = NULL;
  if (T != NULL){
    InThread(T, pre);
    pre->rchild = NULL;
    pre->rtag = 1;
  }
}

// 线索二叉树遍历(中序生成的线索二叉树)
ThreadNode *Firstnode(ThreadNode *p){
  while (p->ltag == 0) p = p->lchild;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
