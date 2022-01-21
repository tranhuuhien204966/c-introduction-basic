#include <stdio.h>
#include <stdlib.h>
#define element int
void insertion_sort(element list[], int n) {
   int i, j;
   element next;
   for (i = 1; i < n; i++) {
      next = list[i];
      for (j = i - 1; j >= 0 && next < list[j]; j--)
         list[j + 1] = list[j];
      list[j + 1] = next;
   }
}
int main() {
   element a[] = {1, 15, 2, 36, 15, -45, -24, 147, -6, 152, 369};
   insertion_sort(a, 11);
   for (int i = 0; i < 11; i++) {
      printf("%d ", a[i]);
   }
}
