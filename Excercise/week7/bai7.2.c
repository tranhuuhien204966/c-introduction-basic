#include <stdio.h>

int binarySearch(int Array[], int length, int x) {
   int Lo = 0, Hi = length - 1;
   while (Lo <= Hi) {
      int mid = (Lo + Hi) / 2;
      if (Array[mid] == x)
         return x;
      if (Array[mid] < x)
         Lo = mid + 1;
      else
         Hi = mid - 1;
   }
   return -1;
}
int A[101];

int main() {
   for (int i = 0; i < 100; i++) {
      A[i] = i + 1;
   }
  
   printf("Search %d, return %d\n", 30, binarySearch(A, 100, 30));
    printf("Search %d, return %d\n", 20, binarySearch(A, 100, 20));
   printf("Search %d, return %d\n", 101, binarySearch(A, 100, 101));
    printf("Search %d, return %d\n", -50, binarySearch(A, 100, -50));
}
