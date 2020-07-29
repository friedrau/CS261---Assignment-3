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
   if (node == 0) {
      BSTnodeRemove(node->left);
      BSTnodeRemove(node->right);
      free(node);
   }
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
      nodeA = (struct *nodeA)malloc(sizeof(struct Node));
      nodeA->value = value;
      nodeA->left = 0;
      nodeA->right = 0;
      return nodeA;
   }
   if (compare(value, current->value) <= 0) {
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
	assert(myTree != 0); //Check if tree is null
	assert(value != 0); // Check if value is null
	struct Node* iterator = myTree->root; // type cast


	while (iterator != 0) {  //While Iterator is not null

		if (compare(value, iterator->value) == 0) { //Compare the value to current iterator value  and see if == 0 (Same)
			return 1;
		}
		else if (compare(value, iterator->value) < 0) { //Compare the value to current iterator value  and see if == 1 (less then)
			iterator = iterator->left;
		}
		else {
			iterator = iterator->right;
		}
	}
	return 0;
}

TYPE minBSTree(BSTree* myTree) {

}

TYPE maxBSTree(BSTree* myTree) {

}
struct Node* _removeNode(struct Node* cur, TYPE val)
{
	/*write this*/
	assert(cur != 0);
	assert(val != NULL);

	struct Node* temp;

	if (compare(cur->val, val) == 0) {
		if (cur->right == 0) {
			temp = cur->left;
			free(cur);
			return temp;
		}
		else {
			cur->val = _leftMost(cur->right);
			cur->right = _removeLeftMost(cur->right);
			return cur;
		}

	}
	else if (compare(val, cur->val) == 1) {
		cur->right = _removeNode(cur->right, val);
		return cur;

	}
	else {
		cur->left = _removeNode(cur->left, val);
		return cur;
	}
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(BSTree* tree, TYPE value)
{
	if (containsBSTree(tree, value)) {
		tree->root = _removeNode(tree->root, value);
		tree->count--;
	}
}

void printBSTree(BSTree* myTree) {

}

