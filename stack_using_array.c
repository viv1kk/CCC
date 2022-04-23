#include <stdio.h>
#define MAX 5

int main()
{
  int arr[MAX], n, ch, arr_idx = 0;

  printf("Size of Array is 5\n");

  printf("Stack Operations :\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Display\n");
  printf("Else to delete\n\n");

  while(1)
  {
    printf("\nEnter operation : ");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1:
      if(arr_idx == 5)
      printf("\nStack is Full\n");
      else
      {
        printf("Enter Element : ");
        scanf("%d", &n);

        arr[arr_idx] = n;
        arr_idx++;
      }

      break;
      case 2:
      if(arr_idx == 0)
      printf("\nStack is Empty\n");
      else
      {
        arr_idx--;
      }
      break;
      case 3:
      if(arr_idx == 0)
      printf("\nStack is Empty\n");\
      else
      {
        printf("Contents of Stack :\n");
        for(int i = 0; i < arr_idx; i++)
        {
          printf("%d, ", arr[i]);
        }
        printf("\n");
      }
      break;
      default:
      printf("\nExiting...\n");
      return 0;
    }
  }
  return 0;
}
