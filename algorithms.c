#include <stdio.h>
#include <stdbool.h>

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

void bubbleSort(int array[], int n){
  bool swapped;

  for (int i = 0; i < n; i++) {
    bool swapped = false;
    for (int j = 0; j < n; j++){
      if (array[j] > array[j+1]) {
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;

        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }

}

// INSERTION //
void insertionSort(int array[], int size){
  for (int i = 1; i < size; i++){ // Loop 1
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key){ // Loop 2
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
}

void selectionSort(int arr){

}

int binarySearch(int array[], int n, int value){

}

int main(){
  // Unsorted array
  int arr[20] = {12, 78, 1, 45, 19, 3, 90, 27, 64, 83, 5, 16, 2, 8, 40, 72, 31, 56, 9, 14};
  printArray(arr, 20);
  // insertionSort(arr, 20);
  bubbleSort(arr, 20);
  printArray(arr, 20);

  return 0;
}

