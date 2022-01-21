#include <stdio.h>
#include <stdlib.h>
typedef struct nodeType {
   int element;
   struct nodeType *left, *right;
} node;
typedef struct nodeType *treetype;

treetype LeftChild(treetype n) {
   if (n != NULL)
      return n->left;
   else
      return NULL;
}
treetype RightChild(treetype n) {
   if (n != NULL)
      return n->right;
   else
      return NULL;
}

node *create_node(int NewData) {
   node *N = (node *)malloc(sizeof(node));
   if (N != NULL) {
      N->left = NULL;
      N->right = NULL;
      N->element = NewData;
   }
   return N;
}

int IsLeaf(treetype n) {
   if (n != NULL)
      return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
   else
      return -1;
}

int EmptyTree(treetype T) { return T == NULL; }

int nb_nodes(treetype T) {
   if (EmptyTree(T))
      return 0;
   else
      return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}

int max(int a, int b) { return a > b ? a : b; }
int treeHeight(treetype T, int height) {
   if (EmptyTree(T))
      return height;
   else
      return max(treeHeight(T->left, height + 1), treeHeight(T->right, height + 1))
}

int countLeaves(treetype T) {
   if (IsLeaf(T))
      return 1;
   else
      return countLeaves(T->left) + countLeaves(T->right);
}
int countRightChild(treetype T) { return nb_nodes(T->right); }
int main() {}
