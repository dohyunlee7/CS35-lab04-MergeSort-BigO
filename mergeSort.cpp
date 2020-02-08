/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  Distributed as course material for Spring 2019
  CPSC 035: Data Structures and Algorithms
*/

#include "mergeSort.h"

// Change to pass in arr1, arr2, size1, size2
// (Optional) Also pass in array and copy arr1 / arr2 into array
void merge(int* array, int* arr1, int* arr2, int size1, int size2){
  //merge the temp subarrays arrays into the main array
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < size1 && j < size2) {
     if (arr1[i] <= arr2[j]) {
       array[k] = arr1[i];
       i++;
     } else {
       array[k] = arr2[j];
       j++;
     }
     k++;
  }
  //merge in any leftover elements
  while (i < size1) {
    array[k] = arr1[i];
    i++;
    k++;
  }
  while (j < size2) {
    array[k] = arr2[j];
    j++;
    k++;
  }
}

void mergeSort(int* array, int length) {
  // TODO: implement this algorithm!
  //insert elements to array
  int lbound = 0;
  int rbound = length;
  if (lbound + 1 < rbound) {
    int mid = (lbound + rbound)/2;
    int size1 = mid - lbound; //acount for even and odd array
    int size2 = rbound - mid;
    //split array in half
    // Must use pointers and dynamically allocate arrays
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    //adding in values from main array into subarray 1
    for (int i = 0; i < size1; i++) {
      arr1[i] = array[lbound+i];
    }
    //adding in values from main array into subarray 2
    for (int j = 0; j < size2; j++) {
      arr2[j] = array[mid+j];
    }
    mergeSort(arr1, size1);
    mergeSort(arr2, size2);
    merge(array, arr1, arr2, size1, size2); // change parameters
  
    delete[] arr1;
    delete[] arr2;
  }
}
