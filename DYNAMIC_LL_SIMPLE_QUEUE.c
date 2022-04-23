#include <stdio.h>
#include <stdlib.h>

typedef struct simpleQueueLL
{
  int qEle;
  struct simpleQueueLL* addrNext;
}link;

link* enQ(int, link*);
link* deQ(link*);
void displayQueue(link*);

int main()
{
  int ch, info;

  link* front = NULL, *rear = NULL;

  while(1)
  {
    printf("\nChoose Operation : \n");
    printf("1. Enqueue an Element.\n");
    printf("2. Dequeue an Element.\n");
    printf("3. Display Element.\n");
    printf("4. Exit.\n\n");

    printf("Your Choice ? ");
    scanf("%d", &ch);

    switch(ch)
    {
      case 1:
      {
        printf("\nInput an Integer value : ");
        scanf("%d", &info);

        rear = enQ(info, rear);

        if(front == NULL)
          front = rear;
      }
      break;

      case 2:
      {
        if(front == NULL)
          printf("Queue is Empty!!");
        else
          front = deQ(front);
          if(front==NULL)
            rear=front;
      }
      break;

      case 3:
      {
        if(front == NULL)
        {
          printf("\nQueue is empty!!\n");
        }
        else
        {
          displayQueue(front);
        }
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

link* enQ(int data, link* rear)
{
  link* newBlock = (link*) malloc(sizeof(link));

  newBlock->qEle = data;
  newBlock->addrNext = NULL;
  if(rear != NULL)
  {
    rear->addrNext = newBlock;
  }
  return newBlock;
}

link* deQ(link* front)
{
  link* temp = front;

  printf("\nElement Dequeued : %d", front->qEle);
  front = front->addrNext;

  free(temp);
  return front;
}

void displayQueue(link* front)
{
  while(front != NULL)
  {
    printf("%d, ", front->qEle);
    front = front->addrNext;
  }
}
