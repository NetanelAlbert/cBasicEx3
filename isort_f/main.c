#ifndef ARR_LEN
#define ARR_LEN 50
#endif

#ifndef PREV
#define PREV -1
#endif

#include "insertionSort.h"
#include <stdio.h>

int main(){
  int arr[ARR_LEN];
  for (size_t i = 0; i < ARR_LEN; i++) {
    printf("Enter an integer\n");

    while (scanf("%d", (arr+i)) == 0)
      getchar();
  }
  insertion_sort(arr, ARR_LEN);

  for (size_t i = 0; i < ARR_LEN PREV; i++) {
    printf("%d,", *(arr+i));
  }
  printf("%d\n", *(arr + ARR_LEN PREV));
  return 0;
}
