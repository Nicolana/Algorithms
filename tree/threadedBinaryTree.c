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
  // 是以p为起点的，中序序列中的第一个节点
  while (p->ltag == 0) p = p->lchild;
  return p;
}

ThreadNode *Nextnode(ThreadNode *p){
  // 中序的后继节点一定再该节点的右边，而且一定是他子树最左下的一个
  if (p->rtag ==0) return Firstnode(p->rchild);
  else return p->rchild; // rtag = 1 直接返回后继线索
}

// 不含头节点的中序线索二叉树的中序遍历的算法
void Inorder(ThreadNode *T){
  for (ThreadNode *p=Firstnode(T);p!=NULL; p = Nextnode(p))
    visit(p);
}


int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
