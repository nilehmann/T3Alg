#include "Graph.h"

void exchange(Edge **numbers,int i, int j) { 
	Edge *temp = numbers[i]; 
	numbers[i] = numbers[j]; 
	numbers[j] = temp; 
}

void quicksort(Edge *numbers[], int low, int high) { 
    int i = low, j = high; 
    // Get the pivot element from the middle of the list 
    Edge *pivot = numbers[low + (high-low)/2]; 
  
    // Divide into two lists 
    while (i <= j) { 
      // If the current value from the left list is smaller then the pivot 
      // element then get the next element from the left list 
      while (numbers[i]->weight < pivot->weight) { 
        i++; 
      } 
      // If the current value from the right list is larger then the pivot 
      // element then get the next element from the right list 
      while (numbers[j]->weight > pivot->weight) { 
        j--; 
      } 
  
      // If we have found a values in the left list which is larger then 
      // the pivot element and if we have found a value in the right list 
      // which is smaller then the pivot element then we exchange the 
      // values. 
      // As we are done we can increase i and j 
      if (i <= j) { 
        exchange(numbers, i, j); 
        i++; 
        j--; 
      } 
    } 
    // Recursion 
    if (low < j) 
      quicksort(numbers,low, j); 
    if (i < high) 
      quicksort(numbers,i, high); 
  } 
  
