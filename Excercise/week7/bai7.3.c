#include <stdio.h>
#define maxArray 100
typedef struct array {
   int data[maxArray];
} arr;



int binary_Search_nonrecursive(arr *a, int size, int value) {
   int l, m, r;
   l = 0;
   r = size - 1;
   while (l <= r) {
      printf("Search %d from %d to %d\n", value, l, r);
      m = (l + r) / 2;
      if (a->data[m] < value)
         l = m + 1;
      else if (a->data[m] > value)
         r = m - 1;
      else
         return m; /* Found */
   }
   return -1; // Not Found
}
int binary_Search_recursive(arr *a, int l, int r, int value) {
   printf("Search %d from %d to %d\n", value, l, r);
   if (l > r)
      return -1; // Not Found
   int m = (l + r) / 2;
   if (a->data[m] == value)
      return m;
   if (a->data[m] > value)
      return binary_Search_recursive(a, l, m - 1, value);
   else
      return binary_Search_recursive(a, m + 1, r, value);
}


int main() {
   arr b;
   int array[] = {1, 5, 9, 12, 17, 20, 35, 48, 59, 67, 101, 200};
   int arraylength = sizeof(array) / sizeof(int);
   for (int i = 0; i < arraylength; i++) {
      b.data[i] = array[i];
   }
   printf("Return index %d\n", binary_Search_recursive(&b, 0, arraylength - 1, 199));
   printf("Return index %d", binary_Search_nonrecursive(&b, arraylength, 199));
}
