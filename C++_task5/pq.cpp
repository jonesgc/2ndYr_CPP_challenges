#include "stdafx.h"
#include "pq.h"



//Dynamically allocate a new queue.
PQ::PQ()
{
	this->priorities = new priority_queue<node*, vector<node *>, node>;
}

//Becuase the queue was dynamically allocated the memory must be freed.
PQ::~PQ()
{
	delete priorities;
}

//Iterates through the queue printing the members.
void PQ::printQueue()
{
	int i = 0;

	//maintain a copy of the size of the queue. 
	int size = priorities->size();
	vector<node*> popped;

	//Take the top off the queue and print it.
	while (i < size)
	{
		
		popped.push_back(popTop());

		cout << i << " / " << size << " "<< popped[i]->symbol << " Freq: " << popped[i]->freq << endl;
		i++;
	}

	//Add the popped elements back into the queue.
	while (popped.size())
	{
		pushOnTop(popped.back());
		popped.pop_back();
	}

}

//Comination of the pop and top functions.
node * PQ::popTop()
{
	node *popped = priorities->top();
	priorities->pop();
	return popped;
}


void PQ::pushOnTop(node *toPush)
{
	priorities->push(toPush);
}

int PQ::getPQsize()
{
	int size = this->priorities->size();
	return size;
}
