#pragma once
#ifndef HUFFCODETREE_H
#define HUFFCODETREE_H

#include "pq.h"
#include "binaryTree.h"
#include "SymbolFreq.h"
#include <string>


class huffCodeTree
{
public:
	//Constructor
	huffCodeTree();

	//Destructor
	~huffCodeTree();

	//Get frequency of symbols in given file and create a proirty queue of nodes.
	void countAndQueue(std::string);

	//Create a binary tree and display it using data in the priority queue.
	void makeFromQueue();

	//Traverse through the three creating huffman codes for each symbol.
	void gethuffCodes();
private:
	//Priority queue.
	PQ *priorities;
	
	//Huffman tree tools.
	binaryTree *huffTree;


};
#endif // !HUFFCODETREE_H
