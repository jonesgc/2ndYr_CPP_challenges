#include "stdafx.h"
#include "binaryTree.h"
#include <iostream>

using namespace std;

//Constructor.
binaryTree::binaryTree()
{
	this->root = NULL;
}

//Public method of destory tree to acess root.
void binaryTree::destoryTree(void)
{
	this->destoryTree(this->root);
}

//Recurse through the tree freeing memory occupied by nodes.
void binaryTree::destoryTree(node *node)
{
	if (node != NULL)
	{
		destoryTree(node->left);
		destoryTree(node->right);
		delete node;
	}
}



//Takes two existing nodes and creates a new one with the input as its leaves.
node * binaryTree::mergeNodes(node * left, node * right)
{
	node *merged = new node;
	merged->symbol = NULL;
	merged->freq = left->freq + right->freq;
	merged->left = left;
	merged->right = right;
	root = merged;
	return merged;
}

//Public method of print tree to acess root.
void binaryTree::printTree(void)
{
	this->printTree(this->root, 0);
}

//Recurses through the tree printing the character stored in the node and its frequency.
void binaryTree::printTree(node *node, int tab)
{
	int tabCount = tab;
	

	//First check if leaf is null, if it is we have reached the end of the branch.
	if (node->left == NULL)
	{
		for (size_t i = 0; i <= tabCount; i++)
		{
			cout << "\t";
		}
		cout << node->symbol << " freq:" << node->freq << "\n";
		return;
	}
	else 
	{
		printTree(node->left,tab+1);
	}
	
	//Check if we are in a branch.
	if (node->symbol == NULL)
	{
		for (size_t i = 0; i <= tabCount; i++)
		{
			cout << "\t";
		}
		cout << "- Branch -" << "Weight: " << node->freq << "\n";
	}

	if (node->right == NULL)
	{
		for (size_t i = 0; i <= tabCount; i++)
		{
			cout << "\t";
		}
		cout << node->symbol << " freq:" << node->freq << "\n";
		return;
	}
	else
	{
		printTree(node->right,tab+1);
	}

}

//Makes a new node, the leaves are null to prevent dangling pointers.
node * binaryTree::makeNode(char symbol, int freq)
{
	node *newNode = new node;
	newNode->symbol = symbol;
	newNode->freq = freq;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

