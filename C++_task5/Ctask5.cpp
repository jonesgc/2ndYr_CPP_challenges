// Ctask5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "huffmanCodeTree.h"


int main()
{
	huffCodeTree *huffCTree = new huffCodeTree;
	//Create queue.
	huffCTree->countAndQueue("ToCompress.txt");
	//Create tree.
	huffCTree->makeFromQueue();

	//Clean up memory.
	delete huffCTree;

    return 0;
}

