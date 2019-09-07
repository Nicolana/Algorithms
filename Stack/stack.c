#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
typedef char ElemType;  // 定义数据类型
#define MaxSize 50 // 定义栈中元素的最大个数

// 栈的顺序存储结构
typedef struct ArrayStack {
  ElemType data[MaxSize];  // 存放栈中的元素
  int top;
} SqlStack;

// 顺序结构基本操作
void InitStack(SqlStack *S); // 初始化一个空栈的 S
bool StackEmpty(SqlStack S); // 判断一个栈是否为空，若栈S为空返回true, 否则返回false
bool Push(SqlStack *S, ElemType x); // 进栈， 若栈S未满，将x加入使之成为新的栈顶，并返回true, 否则返回false, 压栈失败
bool Pop(SqlStack *S, ElemType *x); // 出栈，若栈S非空，弹出栈顶元素，并用x返回。 成功返回true, 失败返回false
bool GetTop(SqlStack S, ElemType *x); // 读取栈顶元素，失败返回空元素
void ClearStack(SqlStack *S); // 销毁栈， 并释放栈S占用的存储空间。

int braceMatch(){
  // ElemType ret;
  //
  // SqlStack stack;
  // InitStack(&stack);
  // Push(&stack, 100);
  // if (StackEmpty(stack))
  //   printf("Stack is empty.\n");
  // else
  //   printf("Stack is not empty.\n");
  // GetTop(stack, &ret);
  // printf("stack top = %d\n", stack.top);
  // printf("stack top elem = %d\n", stack.data[stack.top]);
  // printf("ret = %d\n", ret);
  char braceSequence[] = "[([][])]";
  SqlStack checkStack;
  InitStack(&checkStack);

  int i;
  ElemType ret;

  for (i = 0; i < strlen(braceSequence); i++){
    char data = braceSequence[i];
    // if (data = '[' || data = '('){
    //   Push(*checkStack, data);
    //   continue;
    // }
    printf("handle %s\n", data);
    if (data == ']' || data == ')'){
      if (StackEmpty(checkStack)){
        printf("Stack is empty, brace do not compatible.");
        return 0;
      }
    }

    switch (data) {
      case '[': ;
      case '(':
        Push(&checkStack, data);
        break;
      case ']':
        Pop(&checkStack, &ret);
        if (ret != '['){
            ret = ' ';
            return 0;
        }
        printf("[ ] ");
        break;
      case ')':
        Pop(&checkStack, &ret);
        if (ret != '('){
          ret = ' ';
          return 0;
        }
        printf("( ) ");
        break;
    }
  }
  printf("brace is ok!");
  return 0;
}

int main(int argc, char const *argv[]) {
  SqlStack stack;
  InitStack(&stack);

  char consequence[30] = "a*(b+c)-d";
  int i;
  char ret;

  for (i = 0; i<len(consequence);i++){
    char character = consequence[i];
    switch (character) {
      case '(': Push(&stack, character); break;
      case ')':
        GetTop(&stack, &ret);
        while (ret != '(' || ret != ' '){
          Pop(&stack, &ret);
          printf("%s", ret);
          GetTop(&stack, &ret);
        }
        ret = ' ';
    }
  }
  return 0;
}

void InitStack(SqlStack *S){
  S->top = -1; // 初始化栈顶指针
}

bool StackEmpty(SqlStack S){
  if (S.top == -1)
    return true;
  else
    return false;
}

// 进栈
bool Push(SqlStack *S, ElemType x){
  if (S->top == MaxSize - 1){
    return false;
  }

  S->data[++S->top] = x; // 指针先加 1，再入栈
  return true;
}

// 出栈
bool Pop(SqlStack *S, ElemType *x){
  if (StackEmpty(*S))
    return false;

  x = S->data[S->top--]; // 先出栈，指针再减减
  return true;
}

bool GetTop(SqlStack S, ElemType *x){
  if (StackEmpty(S))
    return false;

  *x = S.data[S.top];
  return true;
}
