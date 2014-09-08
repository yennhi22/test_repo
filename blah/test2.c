#include<stdio.h>
#include<stdlib.h>

int menu();
void *sort(int *a, int n);
void swap(int *a, int *b);
void displayList(int *a, int n);

//--------------------------------------------------------------------
int main() {
  int ch, n, i;
  int *list;
  int flag = 0;

  while(1) {
    ch = menu();
    switch(ch) {
    case 1:
      printf("\nYou choose %d\n", ch);
      printf("Set the size of the list: ");
      while(scanf("%d", &n) != 1) {
	printf("Invalid input! Please retry: ");
	while(getchar() != '\n');
      }
  
      if(n < 1) {
	printf("There is no element in this array\nExit...\n");
	return 1;
      }

      list = (int*) malloc((n+1) * sizeof(int));
      printf("Please enter the elements of your list\n");
      for(i=0; i<n; i++) {
	printf("\tA[%d]: ", i);
	while(scanf("%d", &list[i]) != 1) {
	  printf("Invalid input! Please retry: ");
	  while(getchar() != '\n');
	}
      }
      continue;

    case 2:
      printf("\nYou choose %d\n", ch);
      if(list != NULL) {
	printf("BEFORE SORTING\n");
	displayList(list, n);
	sort(list, n);
	printf("AFTER SORTING\n");
	displayList(list, n);
      }
      else
	printf("You must choose the first option before using this function.\n");
      continue;

    case 3:
      printf("\nYou choose %d\n", ch);
      if(list != NULL) { 
	sort(list, n);
	for(i=0; i<n; i++) {
	  if(list[i] > list[0]){
	    printf("The min-2nd is %d\n", list[i]);
	    flag = 1;
	    break;
	  }
	}
	if(!flag)
	  printf("There are no min-2nd.\n");
      }
      else
	printf("You must choose the first option before using this function.\n");

      flag = 0;
      continue;

    case 4:
      printf("\nYou choose %d\n", ch);
      printf("Free the list...\n");
      if(list != NULL)
	free(list);
      printf("Done\n");
      printf("C U later!\n");
      break;

    default:
      printf("Your choice is not available. Please retry.\n");
      continue;
    }
    break;
  }

  return 0;
}

//--------------------------------------------------------------------
int menu() {
  int ch;

  printf("\n\t\tMENU\n");
  printf("1. First choice\n");
  printf("2. Second choice\n");
  printf("3. Third choice\n");
  printf("4. Exit\n");
  printf("\nYour choice?\n");
  while(scanf("%d", &ch) != 1) {
    printf("Invalid input! Please take another choice!\n");
    while(getchar() != '\n');
  }

  return ch;
}

//--------------------------------------------------------------------
// a: the array
// n: the size of array
void* sort(int *a, int n) {
  int i, j;
  int min;

  for(j=0; j<n-1; j++) {
    min = j;
    for(i=j+1; i<n; i++) {
      if(a[i] < a[min]) {
	min = i;
      }
    }

    if(min != j) {
      swap(&a[j], &a[min]);
    }
  }
}
//--------------------------------------------------------------------
// a, b: 2 elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

//--------------------------------------------------------------------
// a: array
// n: the size of array
void displayList(int *a, int n) {
  int i;
  if(a != NULL) {
    printf("The elements in current list:\n");
    for(i=0; i<n; i++) {
      printf("\tA[%d] = %d\n", i, a[i]);
    }
    printf("\n");
  }
  else
    printf("The current list is empty.\n");
}