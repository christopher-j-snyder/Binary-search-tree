#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

/* Christopher Snyder 
   ICSI402 Programming Project 1
   CS146375
				*/

/*File to include all our statistical node functions*/

//Function to create a node, or a "constructor" function. The char array parameter is assigned to the nodes string member
NodePtr createNode(char str[])
	{
		//Allocate memory for the node to point to
		NodePtr n = (NodePtr) malloc(sizeof(struct node));
		//Set the left and right children to be null so we can later on test to be sure they are empty
		n->left_child = NULL;
		n->right_child = NULL;
		//Assign the str parameter to the nodes string member
		strcpy(n->string, str);
		//Return a pointer to our new initialized node
		return n;
	}

//Function to print the entire tree. The function moves through the tree to the leftmost node recursively, then prints them upwards in an in-order fashion. Recursively prints left child, then head, then right child. Not actually used in the program output but it was useful for testing that my tree inserted nodes correctly. Also, many of the below functions are based off of this one.
void printTree(NodePtr head)
	{
		if(head != NULL)
		{
		printTree(head->left_child);
		printf("%s\n",head->string);
		printTree(head->right_child);
		}
	}

//Function to calculate max of two numbers to be used in recursive tree height function
int max(int a, int b)
	{
		if(a > b)
			return a;
		else
			return b;
	}

//Function to calculate tree height. If a tree has height 1 or 0, it's height is 0. Otherwise, increment the height and recursively call treeHeight on the L and R subtrees
int treeHeight(NodePtr head)
	{
		if(head == NULL)
			return 0;
		if(head->left_child == NULL && head->right_child == NULL)
			return 0;
		else
			return 1 + max(treeHeight(head->left_child), treeHeight(head->right_child));
	}

//Function to recursively calculate number of leaves in a tree. If a node has no left or right child, it is a leaf, and the recursive counter is incremented. 
int countLeaves(NodePtr head)
	{	
		if(head == NULL)
			return 0;
		if(head->left_child == NULL && head->right_child == NULL)
			return 1;
		else 
			return countLeaves(head->left_child) + countLeaves(head->right_child);
	}

//Function to recursively calculate the number of strings or "nodes" in our tree. If a node is null, it returns 0. Otherwise, we increment the recursive counter by 1 and call stringCount on the nodes left and right child.
int stringCount(NodePtr head)
	{	
		if(head == NULL)
			return 0;
		else
			return 1 + (stringCount(head->left_child) + stringCount(head->right_child));
	}
