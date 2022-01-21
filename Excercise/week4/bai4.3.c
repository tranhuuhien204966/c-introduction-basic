#include <stdio.h>
#define maxSize 30
char stack[maxSize];
int size = 0;
void push(char operator) {
   if (size == maxSize - 1) {
      printf("Stack overflow");
      return;
   }
   stack[size] = operator;
   size++;
}
char pop() {
   if (size == 0) {
      printf("Stack empty");
      return '?';
   }
   return stack[--size];
}
char getTop() { return stack[size - 1]; }
int getOrder(char c) {
   if (c == '+' || c == '-')
      return 0;
   else
      return 1;
}
int main() {
   char c = getchar();
   int x;
   do {
      if ('0' <= c && c <= '9') {
         putchar(c);
         putchar(' ');
      } else {
         int order = getOrder(c);
         while (size > 0 && getOrder(getTop()) >= order) {
            putchar(pop());
            putchar(' ');
         }
         push(c);
      }
      c = getchar();
   } while (c != '\n');
   while (size > 0) {
      putchar(pop());
      putchar(' ');
   }
}
