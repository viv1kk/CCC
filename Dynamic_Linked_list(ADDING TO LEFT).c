#include <stdio.h>
#include <stdlib.h>


// 1-Oct-2021, 3:32:42 AM


// IMPEMENTING DYNAMIC LINKED LIST (ADDING ELEMENT FROM RIGHT TO LEFT)


typedef struct LL
{
  int data;
  struct LL* nextNode;
}link;

link* insertNode(int , link*);
void displayLL(link*);

int main()
{
  int ch, info;

  link* node = NULL;

  while(1)
  {
    printf("\n\nChoose Operation : \n");
    printf("1. Insert a node\n");
    printf("2. Disply data in linked list\n");
    printf("3. Exit.\n");

    printf("Your Choice ? ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
      {
        printf("Input an Integer value : ");
        scanf("%d", &info);

        node = insertNode(info, node);
      }
        break;
      case 2:
      {
        displayLL(node);
      }
        break;
      case 3:
          return 0;
        break;
      default: printf("\nInvalid Input!!!!");
    }
  }
  return 0;
}



link* insertNode(int dt, link* nxt)
{

  link* newBlock = (link*) malloc(sizeof(link));

  newBlock->data = dt;
  newBlock->nextNode = nxt;

  return newBlock;
}

void displayLL(link* node)
{
  if(node == NULL)
  {
    printf("Linked List is Empty!!");
  }
  else
  {
    while(node != NULL)
    {
      printf("%d, ", node->data);
      node = node->nextNode;
    }
    printf("\n");
  }
}
