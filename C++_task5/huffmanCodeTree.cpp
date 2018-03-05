#include "stdafx.h"
#include "huffmanCodeTree.h"

using namespace std;

huffCodeTree::huffCodeTree()
{
	this->huffTree = new binaryTree;
	this->priorities = new PQ;
}

huffCodeTree::~huffCodeTree()
{
	delete this->huffTree;
	delete this->priorities;
}

void huffCodeTree::countAndQueue(std::string fn)
{
	//Symbol counter.
	symbolFreq *SymbolFreq = new symbolFreq(fn);

	vector<pair<char, int>> *symbolContainer = new vector<pair<char, int>>;
	symbolContainer = SymbolFreq->getSymbolContainer();
	cout << "---Symbol Frequencies---" << endl;
	SymbolFreq->printContainer();
	cout << "---End of Symbol Frequencies---" << endl;

	for (size_t i = 0; i < symbolContainer->size(); i++)
	{	
		//Get infomation from pairs.
		char symbol = 0;
		int freq = 0;
		symbol = (*symbolContainer)[i].first;
		freq = (*symbolContainer)[i].second;

		//Create a new node with data obtained and insert into queue.
		node *madeNode = huffTree->makeNode(symbol, freq);
		priorities->pushOnTop(madeNode);
		
	}
	cout << "---Priority Queue---" << endl;
	priorities->printQueue();
	cout << "---End of Priority Queue---" << endl;

	//Clean up memory.
	delete SymbolFreq;
}

void huffCodeTree::makeFromQueue()
{
	//Take the top two nodes (highest priority so they have the lowest freqency and merge them making a new node.
	while (priorities->getPQsize() > 0)
	{
		//Cant merge a single node.
		if (priorities->getPQsize() == 1)
		{
			break;
		}

		node* a = priorities->popTop();
		node* b = priorities->popTop();
		node* merged = huffTree->mergeNodes(a, b);
		priorities->pushOnTop(merged);
	}
	
	huffTree->printTree();
}
