/* Christopher Snyder 
   ICSI402 Programming Project 1
   CS146375
				*/


#define MAXLEN 15

//Structure definition for our node "class" containing two node pointer subchildren and a string member or "key"
struct node 
{
	char string[MAXLEN + 1];
	struct node *left_child, *right_child;
};

//Aliasing node and node* for readability
typedef struct node Node;
typedef struct node* NodePtr;

//Function prototypes to be used, which are all defined in and commented in nodefunctions.c
NodePtr createNode(char str[]);
void insertNode(NodePtr head, NodePtr leaf);
void printTree(NodePtr n);
int treeHeight(NodePtr n);
int countLeaves(NodePtr n);
int stringCount(NodePtr n);
int max(int a, int b);
