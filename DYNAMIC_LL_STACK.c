#include <stdio.h>
#include <stdlib.h>

/* SO THE APPROACH -
ADD THE NEW NODE TO THE LEFT OF THE CURRENT NODE AND EVERYTIME A NEW ELEMENT IS PUSHED THE TOP WILL ALSO UPDATE*/

typedef struct stackLL
{
  int stackElement;
  struct stackLL* addNext;
}link;

link* push(int, link*);
link* pop(link*);
void displayStack(link*);

int main()
{
  int ch, info;
  link* top = NULL;

  printf("\nChoose Operation : \n");
  printf("1. Push an Element.\n");
  printf("2. Pop an Element.\n");
  printf("3. Display Element.\n");
  printf("4. Exit.\n\n");
  
  while(1)
  {
    printf("Your Choice ? ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
      {
        printf("\nInput an Integer value : ");
        scanf("%d", &info);

        top = push(info, top);
      }
      break;

      case 2:
      {
        if(top == NULL)
        {
          printf("Stack is Empty");
        }
        else
        {
          top = pop(top);
        }
      }
      break;

      case 3:
      {
        if(top == NULL)
          printf("Stack is Empty!!\n");
        else
          displayStack(top);
      }
      break;

      case 4:
        return 0;
      break;
      default: printf("\nInvalid Input!!!!");
    }
  }
  return 0;
}

link* push(int data, link* top)
{
  link* newBlock = (link*) malloc(sizeof(link));

  newBlock->stackElement = data;
  newBlock->addNext = top;
  return newBlock;
}

link* pop(link* top)
{
  link* temp = top;

  printf("Element Poped is : %d", top->stackElement);
  top = top->addNext;
  free(temp);

  return top;
}

void displayStack(link* top)
{
  while(top != NULL)
  {
    printf("%d. ", top->stackElement);
    top = top->addNext;
  }
}
