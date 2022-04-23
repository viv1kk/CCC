#include <stdio.h>
#include <stdlib.h>

typedef struct LL
{
  int data;
  struct LL* next;
}link;

void enq(link**, link**, int);
void deq(link**, link**);
void displ(link*, link*);

int main()
{
  int ch, num;
  link* front = NULL;
  link* rear = NULL;

  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Display\n");
  printf("4. Delete\n\n");

  while(1)
  {
    printf("\nYour Choice ?");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
      {
        printf("Enter the data : ");
        scanf("%d", &num);
        enq(&rear, &front, num);
      }
      break;
      case 2:
      {
        deq(&front, &rear);
      }
      break;
      case 3:
      {
        if(front == NULL)
          printf("\nEmpty\n");
        else
          displ(front, rear);
      }
      break;
      case 4:
      {
        if(front == NULL)
          printf("\nEmpty\n");
        else
          printf("%d", front->data);
      }
      break;
      default: printf("Exiting..");
      return 0;
    }
  }
}

void enq(link** rr, link** fr, int n)
{
  link* newNode = (link*) malloc(sizeof(link));

  if(newNode != NULL)
  {
    newNode->data = n;
    if(*rr != NULL)
    {
      newNode->next = (*rr)->next;
      (*rr)->next = newNode;
    }
    else
      (*fr) = newNode;
    (*rr) = newNode;
  }
  else
    printf("\nCannot create node\n");
}

void deq(link** fr, link** rr)
{
  link* temp = (*fr);
  if((*fr) == NULL)
    printf("\nEmpty\n");
  else
  {
    printf("%d", (*fr)->data);
    if((*fr) == (*rr))
      (*fr) = (*rr) = NULL;
    else
    {
      (*fr) = (*fr)->next;
      (*rr)->next = (*fr);
    }
    free(temp);
  }
}

void displ(link* fr, link*rr)
{
  link* temp = fr;
  do
  {
    printf("%d, ", temp->data);
    temp = temp->next;
  }
  while(temp != rr->next);
}
