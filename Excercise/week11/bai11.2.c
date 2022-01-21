#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

void insertionSort(int array[], int size, int *count) {
   for (int step = 1; step < size; step++) {
      int key = array[step];
      int j = step - 1;
      while (key < array[j] && j >= 0) {
         array[j + 1] = array[j];
         --j;
         *(count) += 3;
      }
      array[j + 1] = key;
      *(count) += 1;
   }
}

int partition(int array[], int low, int high, int *count) {
   int pivot = array[high];
   int i = (low - 1);
   for (int j = low; j < high; j++) {
      if (array[j] <= pivot) {
         i++;

         swap(&array[i], &array[j]);
         *(count) += 4;
      }
   }

   swap(&array[i + 1], &array[high]);
   *(count) += 3;
   return (i + 1);
}

void quickSort(int array[], int low, int high, int *count) {
   if (low < high) {
      int pi = partition(array, low, high, count);
      quickSort(array, low, pi - 1, count);
      quickSort(array, pi + 1, high, count);
   }
}

int main() {
   int a[1000], b[1000];
   int n;
   printf("Enter n:");
   scanf("%d", &n);
   printf("Array: \n");
   for (int i = 0; i < n; i++) {
      a[i] = b[i] = rand() % 10000;
      printf("%d ", a[i]);
   }

   int count = 0;
   printf("\n\nInsertion Sort:\n");
   insertionSort(a, n, &count);
   for (int i = 0; i < n; i++) {
      printf("%d ", a[i]);
   }
   printf("\nCount = %d", count);

   count = 0;
   printf("\n\n\nQuicksort:\n");
   quickSort(b, 0, n - 1, &count);
   for (int i = 0; i < n; i++)
      printf("%d ", b[i]);
   printf("\nCount = %d", count);
}
