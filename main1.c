#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

/* Christopher Snyder
   ICSI402 Programming Project 1
   CS146375
				*/
int main(int argc, char * argv[]){

char str[MAXLEN + 1];
int strCount = 0;
char * failCheck = (char *) malloc(sizeof(char) * MAXLEN);

//Check to make sure malloc is working and can allocate memory
if(failCheck == NULL)
{
	fprintf(stderr, "Out of memory. Exiting...\n");
	exit(1);
}

//Quit program if user enters incorrect number of arguments
if(argc != 3)
{
	fprintf(stderr, "Incorrect number of arguments. Exiting...\n");
	exit(1);
}

//Declaring file pointers to be used in the program
FILE *inputFile;
FILE *outputFile;

//Declaring our input file to be the users first file and output file to be the users second file
inputFile = fopen(argv[1], "r");
outputFile = fopen(argv[2], "w");

//Error checking to make sure user enters valid input file
if(inputFile == NULL)
{
	fprintf(stderr, "Could not open input file. Exiting...\n");
	exit(1);
}

//Error checking to make sure user enters valid output file
if(outputFile == NULL)
{
	fprintf(stderr, "Could not open output file. Exiting...\n");
	exit(1);
}

//Create the head for our tree
NodePtr head = NULL;

//While the input file contains strings, create a node for each one and insert it into our tree
while(fscanf(inputFile, "%s", str) != EOF)
{
	//Increment a count for strings inserted into the binary tree
	strCount++;
	//Create a node
	NodePtr node = createNode(str);
	//If there is no head for our tree, make the next node our head. Otherwise, insert it into the tree.
	if(head == NULL)
		head = node;
	else
		insertNode(head, node);
}	

//Write various statistics to the output file about the binary search tree.
fprintf(outputFile,"Total number of strings in the input file: %d\n", strCount);
fprintf(outputFile, "Height of the binary search tree: %d\n", treeHeight(head));
fprintf(outputFile, "No. of leaves in the binary search tree is: %d\n", countLeaves(head));
fprintf(outputFile, "Height of the left subtree of the root: %d\n", treeHeight(head->left_child));
fprintf(outputFile, "No. of strings in the left subtree of the root: %d\n", stringCount(head->left_child));
fprintf(outputFile, "Height of the right subtree of the root: %d\n", treeHeight(head->right_child));
fprintf(outputFile, "No. of strings in the right subtree of the root: %d\n", stringCount(head->right_child));

//Close the input and output file
fclose(inputFile);
fclose(outputFile);

//Print to console a success message so the user knows the program ran
puts("Tree sucessfully processed!");

return 0;
}//end main
