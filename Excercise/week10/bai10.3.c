#include <stdio.h>
#include <stdlib.h>
#define element int
void selection(element a[], int n) {
   int i, j, min, tmp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j <= n - 1; j++)
         if (a[j] < a[min])
            min = j;
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
   }
}
int main() {
   element a[] = {1, 15, 2, 36, 15, -45, -24, 147, -6, 152, 369};
   selection(a, 11);
   for (int i = 0; i < 11; i++) {
      printf("%d ", a[i]);
   }
}
