#include <stdio.h>
#include <stdlib.h>

typedef struct LL
{
  int data;
  struct LL* nextNode;
}link;


link* insertNode(int, link*);
void displayLL(link*);


int main()
{
  int ch, info;

  link *startNode = NULL, *node = NULL;

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

        if(startNode == NULL)
        {
          startNode = node;
        }

      }
      break;

      case 2:
      {
        displayLL(startNode);
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

link* insertNode(int data, link* node)
{
  link* newBlock = (link*) malloc(sizeof(link));

  if(node != NULL)
  {
    node->nextNode = newBlock;
  }
  newBlock->data = data;
  newBlock->nextNode = NULL;

  return newBlock;
}

void displayLL(link* startNode)
{
  if(startNode == NULL)
  {
    printf("\nLinked List is Empty!!");
  }
  else
  {
    while(startNode != NULL)
    {
      printf("%d, ", startNode->data);
      startNode = startNode->nextNode;
    }
  }
}
