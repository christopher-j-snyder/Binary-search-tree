#include "node.h"
#include <string.h>

/* Christopher Snyder 
   ICSI402 Programming Project 1
   CS146375
				*/

//Function to insert a node into our tree. Recursively calls insertNode until we find an open spot to place the leaf
void insertNode(NodePtr head, NodePtr leaf)
{
	//If pos, str2 precedes str1
	//If the node to be inserted a.k.a. leaf is alphabetically before the head, we look to insert it in the left subtree
	if(strcmp(head->string, leaf->string) > 0)
	{
		//If the head has no left child, put the leaf there
		if(head->left_child == NULL)
		{
			head->left_child = leaf;
		}
		//Else, recursively call insertNode on the heads left child and the leaf
		else
		{
			insertNode(head->left_child, leaf);
		}
	}

	//If neg, str1 precedes str2
	//If the leaf is alphabetically after the head, we look to insert it into the right subtree
	if(strcmp(head->string, leaf->string) < 0)
	{
		//if the head has no right child, put the leaf there
		if(head->right_child == NULL)
		{
			head->right_child = leaf;
		}
		//Else, recursively call insertNode on the heads right child and the leaf
		else
		{
			insertNode(head->right_child, leaf);
		}

	}
}//end insertNode function
