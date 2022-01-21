#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PHONE_LENGTH 12
#define NAME_LENGTH 20
#define EMAIL_LENGTH 20
struct phoneAddress {
   struct phoneAddress *next;
   char number[PHONE_LENGTH];
   char name[NAME_LENGTH];
   char email[EMAIL_LENGTH];
};
struct phoneAddress *NUL;
struct phoneAddress *createNewPhoneAddress(struct phoneAddress *current) {
   struct phoneAddress *new;
   new = (struct phoneAddress *)malloc(sizeof(struct phoneAddress));
   new->next = NUL;
   (*current).next = new;
   return new;
}
void removeAllPhoneAddress(struct phoneAddress *root) { (*root).next = NUL; }
void insertPhoneAddress(struct phoneAddress *root) {
   printf("How many phone numbers you want to insert? \n");
   int n;
   scanf("%d", &n);
   struct phoneAddress *temp = root;
   while ((*temp).next != NUL) {
      temp = (*temp).next;
   }
   while (n--) {
      temp = createNewPhoneAddress(temp);
      printf("%x: ", temp);
      char num[PHONE_LENGTH], name[NAME_LENGTH], email[EMAIL_LENGTH];
      printf("Enter phone number: ");
      scanf("%s", num);
      strcpy((*temp).number, num);
      printf("Enter Name: ");
      scanf("%s", name);
      strcpy((*temp).name, name);
      printf("Enter Email Address: ");
      scanf("%s", email);
      strcpy((*temp).email, email);
   }
}
void showAllPhoneAddress(struct phoneAddress *root) {
   struct phoneAddress *temp = (*root).next;
   while (temp != NUL) {
      printf("%x: ", temp);
      printf("%s  | %s | %s\n", (*temp).name, (*temp).number, (*temp).email);
      temp = (*temp).next;
   }
}

int main() {
   struct phoneAddress root;
   root.next = NUL;
   int n;
   while (1) {
      printf("\nSelect Options:\n1. Insert Phone Address.\n2. Show all phone address\n");
      printf("3. Remove all phone numbers\n");
      int option;
      scanf("%d", &option);
      switch (option) {
      case 1:
         insertPhoneAddress(&root);
         break;
      case 2:
         showAllPhoneAddress(&root);
         break;
      case 3:
         removeAllPhoneAddress(&root);
         break;
      }
   }
}
