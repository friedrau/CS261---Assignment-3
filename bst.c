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

void deleteBSTree(BSTree* myTree) {

}
   
int isEmptyBSTree(BSTree* myTree) {
   return (myTree->count) == 0;
}

int sizeBBSTree(BSTree* myTree) {
   return myTree->left;
}

void addBSTree(BSTree* myTree, TYPE value) {
/*
   struct Node *node;
//   struct Node *current;
   if (myTree == NULL) {
      node = malloc(sizeof(struct BSTree));
      node->value = value;
      node->left = 0;
      node->right = 0;
   }
   if (value < current->value) {
//      myTree->count = addBSTree(current->left, value);
   }
   else {
//      myTree->count = addBSTree(current->right, value);
   }
   */
//   myTree->root = addBSTree(myTree->root, value);
//   myTree->count++;
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

