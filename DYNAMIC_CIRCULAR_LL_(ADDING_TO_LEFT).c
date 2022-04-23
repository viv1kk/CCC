#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int info;
  struct node* next;
}link;

link* insertNode(link*, link*, int);
void deleteNode(link**, link**, int);
link* search(link*, int);
void displayLL(link*);

int main()
{
  int ch, info;
  link *last = NULL, *start = NULL;

  printf("\nLinked-list Operations :\n\n");
  printf("1. Create a Node\n");
  printf("2. Delete a Node\n");
  printf("3. Display\n");
  printf("Else to Exit.\n\n");

  while(1)
  {
    printf("\nChoose Operation : ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
        printf("Enter an Integer : ");
        scanf("%d", &info);
        if(last == NULL)
        {
          last = insertNode(start, last, info);
          start = last;
        }
        else
          last = insertNode(start, last, info);
      break;
      case 2:
        if(last == NULL)
          printf("\nLinked-List is empty!\n");
        else
        {
          printf("Enter an Integer to search and delete : ");
          scanf("%d", &info);
          deleteNode(&start, &last, info);
        }
      break;
      case 3:
        if(last == NULL)
          printf("\nLinked-list is empty!\n");
        else
          displayLL(start);
      break;
      default:  printf("\nExiting...\n");
      return 0;
    }
  }
}

link* insertNode(link* start, link* last, int info)
{
  link* newNode = (link*) malloc(sizeof(link));
  if(newNode != NULL)
  {
    newNode->info = info;
    if(last == NULL)
      newNode->next = newNode;
    else
    {
      newNode->next = last;
      start->next = newNode;
    }
    return newNode;
  }
  else
  {
    printf("\nMemory Allocation Failed!\n");
  }
}


void deleteNode(link** start, link** last, int info)
{
  link* ser = search(*start, info), *temp = NULL;

  if(ser != NULL)
  {

    printf("%d\n", ser->info);

    if(*last == *start && *last == ser)  // IF LL has only one node
    {
      temp = ser;
      printf("Successfully removed : %d", ser->info);
      *start = NULL;
      *last = NULL;
    }
    else
    { // for multiple nodes

      if(ser == *last && ser->info == info)
      {
        temp = *last;
        printf("Successfully removed : %d", (*last)->info);
        *last = (*last)->next;
        (*start)->next = *last;
        free(temp);
      }
      else if((ser->next)->info == info && ser->next == *start)
      {
        temp = *start;
        printf("Successfully removed : %d", (*start)->info);
        ser->next = (*start)->next;
        *start = ser;
        free(temp);
      }
      else
      {
        temp = ser->next;
        ser->next = (ser->next)->next;
        printf("Successfully removed : %d", temp->info);
        free(temp);
      }
    }
  }
  else
    printf("\nCan't find the Matching Integer in LL\n");
}

link* search(link* start, int info)
{
  link* temp = start->next, *prev = NULL;
  do
  {
    if(temp == start->next && info == temp->info)
      return temp;
    else if(temp->info == info)
    {
      return prev;
      printf("%d, ", prev->info);
    }
    prev = temp;
    temp = temp->next;
  }
  while(temp != start->next);
  return NULL;
}

void displayLL(link* start)
{
  link* temp = start->next;
  do
  {
    printf("%d, ", temp->info);
    temp = temp->next;
  }
  while(temp != start->next);
}
