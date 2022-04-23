#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int info;
  struct node* next;
}link;

link* addNode(link*, link*, int);
void deleteNode(link**, link**, int);
link* search(link*, int);
void displayLL(link*);

int main()
{
  int ch, info;
  link *start = NULL, *last = NULL;

  printf("\nOperation on Circular LL :\n");
  printf("1. Adding a node\n");
  printf("2. Deleting a node\n");
  printf("3. Display LL\n");
  printf("Else to Exit\n\n");

  while(1)
  {
    printf("\nChoose operation : ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
        printf("\nEnter an Integer : ");
        scanf("%d", &info);

        if(last == NULL)
        {
          start = addNode(start, last, info);
          last = start;
        }
        else
        {
          start = addNode(start, last, info);
        }

      break;
      case 2:
      if(last == NULL)
        printf("\nLinked-List is empty!\n");
      else
      {
        printf("\nEnter an Integer to search and delete : ");
        scanf("%d", &info);
        deleteNode(&start, &last, info);
      }
      break;
      case 3:
        if(last == NULL)
        {
          printf("\nLinked-List is Empty!\n");
        }
        else
        {
          displayLL(start);
        }
      break;
      default: printf("\nExiting...\n");
      return 0;
    }
  }
  return 0;
}

link* addNode(link* start, link* last, int info)
{
  link* newNode = (link*) malloc(sizeof(link));

  if(newNode != NULL)
  {
    newNode->info = info;

    if(last == NULL)
    {
      newNode->next = newNode;
    }
    else
    {
      newNode->next = start->next;
      start->next = newNode;
    }
    start = newNode;
  }
  else
    printf("Failed to Allocate Memory!");
  return start;
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
