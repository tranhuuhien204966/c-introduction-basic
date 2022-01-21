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
void push(ad *address, int i, char name[], char phone[], char email[]) {
   strcpy((address + i)->name, name);
   strcpy((address + i)->phone, phone);
   strcpy((address + i)->email, email);
}
void find(ad *address, char tmp[], int n, int option) {
   for (int i = 0; i < n; i++) {
      if (option == 1 && strcmp((address + i)->name, tmp) == 0) {
         printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
      if (option == 2 && strcmp((address + i)->email, tmp) == 0) {
         printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
      if (option == 3 && strcmp((address + i)->phone, tmp) == 0) {
         printf("Found!\n%s %s %s\n", (address + i)->name, (address + i)->phone, (address + i)->email);
         return;
      }
   }
   printf("NOT FOUND!");
}
int main() {
   int n;
   FILE *input = fopen("input1.txt", "r");
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
   int c;
   do {
      printf("\n\nOptions: \n0. Exit\n1. Search by name\n2. Search by email\n3. Search by phone number\n");
      scanf("%d", &c);
      char tmp[emailLength];
      switch (c) {
      case 1:
         printf("Enter name: ");
         scanf("%s", tmp);
         find(AddressList, tmp, n, 1);
         break;

      case 2:
         printf("Enter email: ");
         scanf("%s", tmp);
         find(AddressList, tmp, n, 2);
         break;

      case 3:
         printf("Enter phone numbers: ");
         scanf("%s", tmp);
         find(AddressList, tmp, n, 3);
         break;
      default:
         break;
      }
   } while (c != 0);
   fclose(input);
}
