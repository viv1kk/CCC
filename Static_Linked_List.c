#include <stdio.h>

struct LinkedList
{
  int info;
  struct LinkedList *memAddrofNxtEle;
};

int main()
{
  struct LinkedList A, B, C, D;
  struct LinkedList* memFirst = NULL;

  A.info = 10;
  B.info = 20;
  C.info = 30;
  D.info = 40;

  memFirst = &A;

  A.memAddrofNxtEle = &B;
  B.memAddrofNxtEle = &C;
  C.memAddrofNxtEle = &D;
  D.memAddrofNxtEle = NULL;

  while(memFirst != NULL)
  {
    printf("%d, ", memFirst -> info);
    memFirst = memFirst -> memAddrofNxtEle;
  }
  return 0;
}
