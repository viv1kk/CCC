#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node* prev;
  int info;
  struct node* next;
}link;

void insertNode(link**, int);
void deleteNode(link**, link**, int);
void display(link*, link*);

int main()
{
  int ch, info;
  link *head = NULL, *tail = NULL, *delNode;

  printf("Doubly Linked-List Operations :\n");
  printf("#1 Insert\n");
  printf("#2 Delete\n");
  printf("#3 Display\n");
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

        insertNode(&tail, info);
        if(head == NULL)
        {
          head = tail;
        }
      break;

      case 2:

        if(head == NULL)
        {
          printf("\nLinked-List is Empty!\n");
        }
        else
        {
          printf("\nEnter the Integer element : ");
          scanf("%d", &info);

          deleteNode(&head, &tail, info);
        }
      break;

      case 3:

      if(head == NULL)
      {
        printf("\nLinked-List is empty.\n");
      }
      else
      {
        display(head, tail);
      }

      break;

      default:
      printf("\nExiting...\n");
      return 0;
    }
  }
  return 0;
}

void insertNode(link** tl, int info)
{
  link* newNode = (link*) malloc(sizeof(link));

  if(newNode != NULL)
  {
    newNode->info = info;
    newNode->next = NULL;

    if(*tl == NULL)
      newNode->prev = NULL;
    else
    {
      (*tl)->next = newNode;
      newNode->prev = *tl;
    }
    printf("Successfully Inserted!\n");
    *tl = newNode;
  }
  else
  {
    printf("\nMemory Allocation Failed!\n");
  }
}

void deleteNode(link** hd, link** tl, int info)
{
  link* temp;

    // if(*hd == *tl && (*hd)->info == info)
    // {
    //   *hd = *tl = NULL;
    //   return;
    // }
    // else
    // {
      if((*hd)->info == info)
      {
        temp = *hd;
        (*hd)->next->prev = NULL;
        *hd = (*hd)->next;
        free(temp);
      }
      else if((*tl)->info == info)
      {
        temp = *tl;
        (*tl)->prev->next = NULL;
        *tl = (*tl)->prev;
        free(temp);
      }
      else
      {
        temp = (*hd)->next;
        while(temp != *tl)
        {
          if(temp->info == info)
          {
            (temp->next)->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
            return;
          }
          temp = temp->next;
        }
        printf("\nElement Not Found!\n");
      }

}




void display(link* hd, link* tl)
{
  while(hd != NULL)
  {
    printf("%d, ", hd->info);
    hd = hd->next;
  }
}
