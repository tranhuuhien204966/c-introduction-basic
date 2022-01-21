#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct node {
   ElementType Element;
   struct node *Next;
} Node;
typedef Node *Position;
typedef struct {
   Position Front, Rear;
} Queue;

int EmptyQueue(Queue Q) { return (Q.Front == Q.Rear); }
void EnQueue(ElementType X, Queue *Q) {
   Q->Rear->Next = (Node *)malloc(sizeof(Node));
   Q->Rear = Q->Rear->Next;
   Q->Rear->Element = X;
   Q->Rear->Next = NULL;
}
void MakeNullQueue(Queue *Q) {
   Position Header;
   Header = (Node *)malloc(sizeof(Node));
   Header->Next = NULL;
   Q->Front = Header;
   Q->Rear = Header;
}
void DeQueue(Queue *Q) {
   if (!EmptyQueue(*Q)) {
      Position T;
      T = Q->Front;
      Q->Front = Q->Front->Next;
      free(T);
   } else
      printf("Error : Queue is empty.");
}
int main() {}
