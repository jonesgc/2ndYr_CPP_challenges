#pragma once
#ifndef PQ_H
#define PQ_H
#include "binaryTree.h"
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class PQ
{
public:
	PQ();
	~PQ();

	//print queue
	void printQueue();

	//pop
	node * popTop();

	//push
	void pushOnTop(node*);

	//Get size of queue
	int getPQsize();

private:
	priority_queue<node*, vector<node *>,node> *priorities;
};



#endif // !PQ_H
