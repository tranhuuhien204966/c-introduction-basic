#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BruteForceMatch(char T[], char P[], int n, int m) {
   for (int i = 0; i < n - m; i++) {
      int j = 0;
      while (j < m && T[i + j] == P[j]) {
         j++;
      }
      if (j == m)
         return i;
   }
   return -1;
}

int main() {
   char text[] = "bcadacaeeeffaadbfaabcdefcddedcedfbeccae";
   char pattern[] = "abcdef";
   int n = sizeof(text) / sizeof(char);
   int m = sizeof(pattern) / sizeof(char) - 1;
   printf("%d", BruteForceMatch(text, pattern, n, m));
   return 0;
}
