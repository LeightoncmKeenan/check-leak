// Copyright 2026 lckeenan
#include"p4functions.h"
// implement the SortHeights function (whose prototype is in p4functions.h)
// in this file

// -------- SORT HEIGHTS - SELECTION SORT ------------
void SortHeights(Height * ptr, int num) {
  // sort the array - starting at second element
  for (int i = 0; i < num -1; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < num; ++j) {
        if (ptr[j] <= ptr[minIndex]) {
          minIndex = j;
         }
       }
        // swap the smallest height into position i
       if (minIndex != i) {
         Height temp = ptr[i];
         ptr[i] = ptr[minIndex];
         ptr[minIndex] = temp;
       }
    }
}
