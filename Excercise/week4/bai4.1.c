#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numLengthMax 120
 
typedef struct Node {
   char num;
   struct Node *next;
} node;

typedef node *Stack;


int pop(Stack *st) {
   node *tmp = *st;
   if (*st == NULL) {
      printf("Stack is empty.");
      exit(0);
   }
   *st = (*st)->next;
   char value = tmp->num;
   tmp->next = NULL;
   free(tmp);
   return value;
}
int Empty(Stack st) { return (st == NULL); }
void add() {
   Stack a = NULL, b = NULL;
   char str1[numLengthMax], str2[numLengthMax];
   printf("Enter first number:");
   scanf("%s", str1);
   printf("Enter second number:");
   scanf("%s", str2);
   int number0 = strlen(str1) - strlen(str2);
   for (int i = number0; i < 0; i++) {
      push(&a, '0');
   }
   for (int i = number0; i > 0; i--) {
      push(&b, '0');
   }
   for (int i = 0; i < strlen(str1); i++) {
      push(&a, str1[i]);
   }
   for (int i = 0; i < strlen(str2); i++) {
      push(&b, str2[i]);
   }
   int add1 = 0;
   Stack result = NULL;
   while (!Empty(a) && !Empty(b)) {
      int num = pop(&a) + pop(&b) + add1 - '0' * 2;
      add1 = num / 10;
      num = num % 10;
      push(&result, num);
   }
   while (!Empty(result)) {
      printf("%d", pop(&result));
   }
   Stack push(Stack *st, char c) {
   node *tmp;
   tmp = (node *)malloc(sizeof(node));
   if (tmp == NULL) {
      printf("Memory Allocated Error.");
      exit(0);
   }
   tmp->num = c;
   tmp->next = *st;
   *st = tmp;
   return *st;
}
}
int main() { add(); }
