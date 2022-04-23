#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node* prev;
  int info;
  struct node* next;
}link;

void insertNode(link**, link**, int);
void display(link*, link*);

int main()
{
  int ch, info;
  link *head = NULL, *tail = NULL;

  printf("Doubly Linked-List Operations :\n");
  printf("#1 Insert\n");
  printf("#2 Display\n");
  printf("Else to Exit.\n\n");

  while(1)
  {
    printf("\nEnter Choice : ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
        printf("\nEnter an Integer : ");
        scanf("%d", &info);

        insertNode(&head, &tail, info);

      break;

      case 2:
      if(head == NULL)
        printf("\nLinked-List is empty.\n");
      else
        display(head, tail);
      break;

      default:
      printf("\nExiting...\n");
      return 0;
    }
  }
  return 0;
}

void insertNode(link** hd, link** tl, int info)
{
  link* newNode = (link*) malloc(sizeof(link));

  if(newNode != NULL)
  {
    newNode->info = info;

    if(*hd == NULL)
    {
      newNode->prev = newNode->next = NULL;
      *hd = newNode;
      *tl = newNode;
    }
    else
    {
      if((*tl)->info < info)
      {
        newNode->next = NULL;
        newNode->prev = *tl;
        (*tl)->next = newNode;
        *tl = newNode;
      }
      else if((*hd)->info > info)
      {
        newNode->next = *hd;
        newNode->prev = NULL;
        (*hd)->prev = newNode;
        *hd = newNode;
      }
      else
      {
        link* temp = *hd;
        do
        {
          temp = temp->next;
        }
        while(temp->info <= info && temp != (*tl)->next);
        newNode->prev = temp->prev;
        temp->prev = newNode;
        newNode->next = temp;
        newNode->prev->next = newNode;
      }
    }
  }
  else
    printf("\nMemory Allocation Failed!\n");
}

void display(link* hd, link* tl)
{
  while(hd != NULL)
  {
    printf("%d, ", hd->info);
    hd = hd->next;
  }
}
