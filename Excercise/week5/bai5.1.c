#include <stdio.h>
#include <stdlib.h>
#define MaxLength 120
 
typedef int ElementType;
typedef struct {
   ElementType Elements[MaxLength];
   int Front, Rear;
} Queue;

int Empty_Queue(Queue Q) { return Q.Front == -1; }
int Full_Queue(Queue Q) { return (Q.Rear - Q.Front + 1) == MaxLength; }
void EnQueue(ElementType X, Queue *Q) {
   if (!Full_Queue(*Q)) {
      if (Empty_Queue(*Q))
         Q->Front = 0;
      Q->Rear = Q->Rear + 1;
      Q->Elements[Q->Rear] = X;
   } else
      printf("Queue is full!");
}
void MakeNull_Queue(Queue *Q) {
   Q->Front = -1;
   Q->Rear = -1;
}
void DeQueue(Queue *Q) {
   if (!Empty_Queue(*Q)) {
      Q->Front = Q->Front + 1;
      if (Q->Front > Q->Rear)
         MakeNull_Queue(Q);
   } else
      printf("Queue is empty!");
}
int main() {}
