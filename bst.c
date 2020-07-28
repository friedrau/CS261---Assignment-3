/***********************************************************
* Author:
* Email: 
* Date Created: 
* Filename: bst.c
*
* Solution description: Implementation of a Binary Search Tree 
* that can store any arbitrary struct in its nodes.
************************************************************/
 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bst.h"
#include "structs.h"

/* ************************************************************************
	Struct Node & BSTree
************************************************************************ */

struct Node
{
	TYPE         value;
	struct Node* left;
	struct Node* right;
};

struct BSTree
{
	struct Node* root;
	int          count;
};


/* ************************************************************************
	BST Functions
************************************************************************ */


struct BSTree* newBSTree() {
   struct BSTree *tree = malloc(sizeof(struct BSTree));
   tree->count = 0;
   tree->root = 0;
   return tree;
}

void BSTnodeRemove(struct Node *node) {
   BSTnodeRemove(node->left);
   BSTnodeRemove(node->right);
   free(node);
}
 
void BSTnodeClear(BSTree *myTree) {
   BSTnodeRemove(myTree->root);
   myTree->root = 0;
   myTree->count = 0;
} 
 
void deleteBSTree(BSTree* myTree) {
  BSTnodeClear(myTree);
  free(myTree);
}

int isEmptyBSTree(BSTree* myTree) {
   return (myTree->count) == 0;
}

int sizeBBSTree(BSTree* myTree) {
   return myTree->left;
}

struct Node* BSTnodeAdd(struct Node* current, TYPE value) {
   struct Node *nodeA;
   if (current == 0) {
      nodeA = malloc(sizeof(struct Node));
      nodeA->value = value;
      nodeA->left = 0;
      nodeA->right = 0;
      return nodeA;
   }
   if (value < current->value) {
      current->left = BSTnodeAdd(current->left,value);
   }
   else {
      current->right = BSTnodeAdd(current->right,value);
   }
   return current;
 }

 void addBSTree(BSTree* myTree, TYPE value) {
    myTree->root = BSTnodeAdd(myTree->root, value);
    myTree->count++;
 }
 

int containsBSTree(BSTree* myTree, TYPE value) {
   struct Node *node; // = myTree->root;
   while (node != NULL) {
      if (node->value == 0) {
	 return 1;
      }
      else if (value < node->value) {
	 node = node->left;
      }
      else {
	 node = node->right;
      }
   }
   return 0;
}

TYPE minBSTree(BSTree* myTree) {
   struct Node *node;
   while (myTree->root != NULL) {
      if (node->left != NULL) {
	 node = node->left;
      }
   }
   return (node->left);
}

TYPE maxBSTree(BSTree* myTree) {
   struct Node *node;
   while (myTree->root != NULL) {
      if (node->right != NULL) {
	 node = node->right;
      }
   }
   return (node->right);
}

void removeBSTree(BSTree *tree, TYPE value) {
   
}  

void printBSTree(BSTree* myTree) {
//   struct Node *node;
   printf("(");
//   printBSTree(myTree->root);

}

