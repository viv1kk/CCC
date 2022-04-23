#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node* prev;
  int info;
  struct node* next;
}link;

link* insertNode(link*, int);
link* deleteNode(link*, link*, int);
void display(link*, link*);

int main()
{
  int ch, info;
  link *head = NULL, *tail = NULL, *delNode = NULL;

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

        tail = insertNode(tail, info);
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

          delNode = deleteNode(head, tail, info);

          if(delNode != NULL)
          {
            if(delNode == head)
            {
              if(delNode->next != NULL)
              {
                head = head->next;
                head->prev = NULL;
              }
              else
              {
                head = NULL;
                tail = NULL;
              }
              free(delNode);
            }
            else if(delNode == tail)
            {
              tail = tail->prev;
              tail->next = NULL;
              free(delNode);
            }
            else if(delNode != head && delNode != tail)
            {
              delNode->next->prev = delNode->prev;
              delNode->prev->next = delNode->next;
              free(delNode);
            }
          }
          else
            printf("\nElement not found!\n");
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

link* insertNode(link* tl, int info)
{
  link* newNode = (link*) malloc(sizeof(link));

  if(newNode != NULL)
  {
    newNode->info = info;
    newNode->next = NULL;

    if(tl == NULL)
      newNode->prev = NULL;
    else
    {
      tl->next = newNode;
      newNode->prev = tl;
    }
    printf("Successfully Inserted!\n");
    tl = newNode;
  }
  else
  {
    printf("\nMemory Allocation Failed!\n");
  }
  return tl;
}

link* deleteNode(link* hd, link* tl, int info)
{
  link* temp = hd;

  while (temp != tl->next)
  {
    if(temp->info == info)
    {
      printf("infoooo %d", temp->info);
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void display(link* hd, link* tl)
{
  while(hd != NULL)
  {
    printf("%d, ", hd->info);
    hd = hd->next;
  }
}
