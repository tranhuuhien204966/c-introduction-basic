#include <stdio.h>
#include <string.h>
#define maxNum 100
#define NameLength 16 
#define PhoneLength 15 
#define EmailLength 23 
typedef struct Address {
   char phone[maxNum][PhoneLength];
   char name[maxNum][NameLength];
   char email[maxNum][EmailLength];
} Ad;


void readAndPrint() {
   FILE *fp = fopen("data.dat", "rb");
   Ad list;
   fread(&list, sizeof(Ad), 1, fp);
   if (fp == NULL) {
      printf("Error reading file!");
   } else {
      int i = 0;
      while (strcmp(list.name[i], "\0")) {
         printf("%d. %s - %s - %s\n", i + 1, list.name[i], list.phone[i], list.email[i]);
         i++;
      }
   }
   fclose(fp);
}

void sort(Ad *list, int n) {
   for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
         if (strcmp(list->name[i], list->name[j]) > 0) {
            char tmp[NameLength];
            strcpy(tmp, list->name[i]);
            strcpy(list->name[i], list->name[j]);
            strcpy(list->name[j], tmp);

            char tmp1[EmailLength];
            strcpy(tmp1, list->email[i]);
            strcpy(list->email[i], list->email[j]);
            strcpy(list->email[j], tmp1);

            char tmp2[PhoneLength];
            strcpy(tmp2, list->phone[i]);
            strcpy(list->phone[i], list->phone[j]);
            strcpy(list->phone[j], tmp2);
         }
      }
   }
}
void insert() {
   FILE *fp = fopen("data.dat", "wb");
   if (fp == NULL)
      printf("Error Writing file");
   else {
      int n;
      Ad list;
      printf("Insert Number of Address you want to insert: ");
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
         printf("Enter name (%d): ", i + 1);
         scanf("%s", list.name[i]);
         printf("Enter phone number (%d): ", i + 1);
         scanf("%s", list.phone[i]);
         printf("Enter email (%d): ", i + 1);
         scanf("%s", list.email[i]);
      }
      fwrite(&list, sizeof(Ad), 1, fp);
   }
   fclose(fp);
}
void readAndSearch() {
   FILE *fp = fopen("data.dat", "rb");
   Ad list;
   fread(&list, sizeof(Ad), 1, fp);
   if (fp == NULL) {
      printf("Error reading file!");
   } else {
      int n = 0;
      while (strcmp(list.name[n], "\0")) {
         n++;
      }
      sort(&list, n);
      for (int i = 0; i < n; i++) {
         printf("%d. %s - %s - %s\n", i + 1, list.name[i], list.phone[i], list.email[i]);
      }
      printf("Numbers of query: ");
      int count;
      scanf("%d", &count);
      while (count--) {
         char name[NameLength];
         printf("\nEnter name:");
         scanf("%s", name);
         binarySearch(&list, name, n);
      }
   }
   fclose(fp);
}; 


void binarySearch(Ad *list, char name[], int size) {
   int l = 0;
   int r = size - 1;
   while (l <= r) {
      int m = (l + r) / 2;
      int k = strcmp(name, list->name[m]);
      if (k == 0) {
         printf("Found! %d. %s - %s - %s\n", m + 1, list->name[m], list->phone[m], list->email[m]);
         return;
      }
      if (k > 0) {
         l = m + 1;
      }
      if (k < 0) {
         r = m - 1;
      }
   }
   printf("Not Found!");
}

int main() {
   Ad List;
   while (1) {
      printf("Menu:\n1. Make a address List\n2. Read address list from file and print out\n3. Search Address\n4. Exit\nSelect options:");
      int k;
      scanf("%d", &k);
      switch (k) {
      case 1:
         insert();
         break;
      case 2:
         readAndPrint();
         break;
      case 3:
         readAndSearch();
         break;
      case 4:
         return 0;
         break;
      }
   }
}
