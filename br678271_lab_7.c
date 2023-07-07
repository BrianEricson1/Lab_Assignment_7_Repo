#include <stdio.h>

void swap(int arr[], int a, int b){
  int temp = arr[b];
  arr[b] = arr[a];
  arr[a] = temp;
}

int numOfSwaps(int arr[], int size){
  int count = 0; //counts # of swaps
  for(int i = 0; i < size; i++){
    int temp = count;
    for(int j = 0; j < size-(i+1); j++){
      // size-(i+1) indicates the index at which the following elements in the list has been sorted
      //from size-1 (no elements sorted) to -1 (all elements sorted)
      if(arr[j] >= arr[j+1]){
        swap(arr, j, j+1);
        count ++;
      }
    }
    if((count-temp)==0){
      break;
      //if change in count is 0, then list is already sorted
    }
  }
  return count;
}

//recursive bubble sort
int numOfSwapsRec(int arr[], int size, int j, int count){
  if(j >= size-1){
    if(size==0){
      return count;
    }
    size--;
    j = 0;
  }
  if(arr[j] >= arr[j+1]){
    swap(arr, j, j+1);
    count++;
  }
  return numOfSwapsRec(arr, size, (j+1), count);
}

void main(void) {
  int arr[] = {97,16,45,63,13,22,7,58,72};
  /* #0:     97,16,45,63,13,22,7,58,72
     #1: 8 - 16,45,63,13,22,7,58,72,97
     #2: 4 - 16,45,13,22,7,58,63,72,97
     #3: 3 - 16,13,22,7,45,58,63,72,97
     #4: 2 - 13,16,7,22,45,58,63,72,97
     #5: 1 - 13,7,16,22,45,58,63,72,97
     #6: 1 - 7,13,16,22,45,58,63,72,97
  */
  printf("%d\n", numOfSwaps(arr,9));
  printf("\nList after bubble sort: ");
  for(int i = 0; i < 9; i++)
    printf("%d ", arr[i]);
}