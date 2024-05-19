#include <stdio.h>

void printArray(int array[], int n){
  printf("[%d", array[0]);
  for (int i = 1; i < n; i++){
    printf(", %d", array[i]);
  }
  printf("]\n");
}

void quickSort(int array[]){

}

void mergeSort(int arr){

}

void bubbleSort(int arr){

}

void insertionSort(int arr){

}

void selectionSort(int arr){

}

void binarySearch(int arr){

}

int main(){
  // Unsorted array
  int arr[20] = {12, 78, 1, 45, 19, 3, 90, 27, 64, 83, 5, 16, 2, 8, 40, 72, 31, 56, 9, 14};
  printArray(arr, 20);

  return 0;
}

