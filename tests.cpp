/*
  Copyright (c) 2019
  Swarthmore College Computer Science Department, Swarthmore PA
  Distributed as course material for Spring 2019
  CPSC 035: Data Structures and Algorithms
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "mergeSort.h"

using namespace std;

TEST(threeElements) {
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  mergeSort(array, 3);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted) {
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = size - 1 - i;
  }
  mergeSort(array, size);
  for (int i = 0; i < size; i++) {
    CHECK_EQUAL(i, array[i]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

// TODO: put your other tests here

TEST(singleElement) {
  //create single element array to test properties
  int array[1] = {5};
  mergeSort(array, 1);
  CHECK_EQUAL(5, array[0]);
}

TEST(orderedArray) {
  //create a sorted array to test merge sort
  int array[10] = {1,2,3,4,5,6,7,8,12,15};
  mergeSort(array, 10);
  CHECK_EQUAL(1, array[0]);
  CHECK_EQUAL(2, array[1]);
  CHECK_EQUAL(3, array[2]);
  CHECK_EQUAL(5, array[4]);
  CHECK_EQUAL(15, array[9]);
}

TEST(largeMid) {
  //create an array of alternating values closing to a min
  int array[19] = {10,29,11,28,12,26,13,25,14,24,15,23,16,22,17,21,19,20,19};
  mergeSort(array, 19);
  CHECK_EQUAL(10, array[0]);
  CHECK_EQUAL(12, array[2]);
  CHECK_EQUAL(14, array[4]);
  CHECK_EQUAL(17, array[7]);
  CHECK_EQUAL(15, array[5]);
}

TEST(reverseOrder) {
  //create an array in reverse order
  int array[10] = {23,22,21,20,19,18,17,16,15,14};
  mergeSort(array, 10);
  CHECK_EQUAL(14, array[0]);
  CHECK_EQUAL(16, array[2]);
  CHECK_EQUAL(19, array[5]);
  CHECK_EQUAL(21, array[7]);
  CHECK_EQUAL(23, array[9]);
}

TEST(duplicates) {
  //create an array with duplicates to ensure splitting is good
  int array[12] = {2,2,3,5,5,7,8,9,9,10,13,13};
  mergeSort(array, 12);
  CHECK_EQUAL(2, array[0]);
  CHECK_EQUAL(2, array[1]);
  CHECK_EQUAL(5, array[3]);
  CHECK_EQUAL(5, array[4]);
  CHECK_EQUAL(13, array[10]);
  CHECK_EQUAL(13, array[11]);
}

/* no need to modify main */
int main() {
  return UnitTest::RunAllTests();
}
