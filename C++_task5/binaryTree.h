#ifndef BINARYTREE_H
#define BINARYTREE_H

//Structure definition of huffman tree, its position in the tree is defined by its frequency.
struct node
{
	char symbol;
	int freq;
	node* left;
	node* right;

};


class binaryTree
{
public:
	//Constructor
	binaryTree();

	//Destructor
	//~binaryTree();

	
	//Public starting point for destory tree method.
	void destoryTree(void);
	
	//Combine two nodes together, and creating a new node holding them as children.
	node *mergeNodes(node *left, node *right);

	//Makes a single "leaf" node.
	node *makeNode(char, int);

	//Public starting point for print tree method.
	void printTree(void);

private:
	//Print tree, recursivly scanning through all nodes.
	void printTree(node*, int);

	//Recursivly go through the tree and destory each node freeing the memory.
	void destoryTree(node*);

	node * root;
};
#endif // !BINARYTREE_H