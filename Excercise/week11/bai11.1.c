#include <stdio.h>
#include <string.h>
#define nameLength 15
#define emailLength 25
#define phoneLength 11
typedef struct Address {
   char name[nameLength];
   char phone[phoneLength];
   char email[emailLength];
} ad;
ad AddressList[100];

void swap(ad *a, ad *b) {
   ad t = *a;
   *a = *b;
   *b = t;
}

int partition(ad array[], int low, int high) {
   char pivot[nameLength];
   strcpy(pivot, array[high].name);
   int i = (low - 1);
   for (int j = low; j < high; j++) {
      if (strcmp(array[j].name, pivot) < 0) {
         i++;
         swap(&array[i], &array[j]);
      }
   }

   swap(&array[i + 1], &array[high]);
   return (i + 1);
}

void quickSort(ad array[], int low, int high) {
   if (low < high) {
      int pi = partition(array, low, high);
      quickSort(array, low, pi - 1);
      quickSort(array, pi + 1, high);
   }
}

void push(ad *address, int i, char name[], char phone[], char email[]) {
   strcpy((address + i)->name, name);
   strcpy((address + i)->phone, phone);
   strcpy((address + i)->email, email);
}

int main() {
   int n;
   FILE *input = fopen("input.txt", "r");
   fscanf(input, "%d", &n);
   for (int i = 0; i < n; i++) {
      char name[nameLength], email[emailLength], phone[phoneLength];
      fscanf(input, "%s", name);
      fscanf(input, "%s", phone);
      fscanf(input, "%s", email);
      push(AddressList, i, name, phone, email);
   }
   printf("Read Successfully! The List is:\n");
   for (int i = 0; i < n; i++) {
      printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
   }

   printf("\n\nThe list after sort is:\n");
   quickSort(AddressList, 0, n - 1);
   for (int i = 0; i < n; i++) {
      printf("%s %s %s\n", AddressList[i].name, AddressList[i].phone, AddressList[i].email);
   }
}
