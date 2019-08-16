#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Books {
  int Node;
} book, *pbook;

void line(char *msg){
  printf("------------------ %s -------------------\n", msg);
}

void line2(/* arguments */) {
  /* code */
  printf("----------------------------------------------\n");
}

void desc(char *msg){
  printf("%s\n\n", msg);
}

void ret(){
  printf("\n");
}

void swap(int *a, int *b){
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

// ����������ʹ�ýṹ��
void alter(book book2){
  printf("book2.Node = %d\n", book2.Node);
  book2.Node = 123566;
}

void p_alter(book *book2){
  // ָ����ʣ����� -> ����
  printf("pointer: book2.Node = %d\n", book2->Node);
  book2->Node = 1231231231;
}

void np_alter(pbook book3){
  // printf("pbook3->Node = %d\n", book3->Node);
  book3->Node = 12313089172391823;
}

void at_alter(book &book4){
  printf("book4->Node = %d\n", book4->Node);
}

int main(){
  line("Hello World");
  int A = 60;
  int B = 13;
  printf("Hello,World!!!\n");
  printf("A = %d, B = %d\n", A, B);
  swap(&A, &B);
  printf("A = %d, B = %d\n", A, B);

  line("�ṹ��");
  book book1;
  book1.Node = 10000;
  printf("book1.Node = %d", book1.Node);
  ret();
  desc("�ṹ�嶨��ֱ��ʹ��\nstruct struct_name {\n\tint id;\n\tchar[40] name; }");
  desc("Ȼ������typedef���Զ������������");

  line("������������ʹ�ýṹ��");
  alter(book1);
  printf("altered book1.Node = %d\n", book1.Node);
  desc("void alter(book book2); ����û�иı䴫���ֵ������������ָ��");
  p_alter(&book1);
  printf("pointer altered book1.Node = %d\n", book1.Node);
  ret();

  line("typedef ����Ϊָ����ʽ *pbook ��ʹ�÷���");
  // pbook pbook1;
  pbook pbook1;
  // ��������ڴ�
  pbook1 = (pbook)malloc(sizeof(book));
  pbook1->Node = 12000;
  printf("unalter: pbook->Node = %d\n", pbook1->Node);
  np_alter(pbook1);
  printf("altered: pbook->Node = %d\n", pbook1->Node);

  return 1;
}
