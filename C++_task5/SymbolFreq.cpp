#include "stdafx.h"
#include "SymbolFreq.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

//Constructor.
symbolFreq::symbolFreq(string file)
{
	symbolContainer = new vector<pair<char, int>>;
	//Open the file and retrieve the symbols. 
	symbols;
	ifstream infile;
	infile.open(file);
	getline(infile, symbols);
	infile.close();

	countAllSymbols(symbols);
}

//Destructor.
symbolFreq::~symbolFreq()
{
	delete symbolContainer;
}

//Count the how many times a given symbol occours.
pair<char, int> symbolFreq::countSymbol(char symbol)
{	
	int freq = 0;
	
	//cout << "symbol is:" << symbol<<endl;

	for (size_t i = 0; i < symbols.size(); i++)
	{
		if (symbols[i] == symbol)
		{
			freq++;
		}
	}

	pair<char, int> symbolWithFreq;
	symbolWithFreq = make_pair(symbol, freq);

	sortSymbols();

	return symbolWithFreq;
}

void symbolFreq::countAllSymbols(string symbols)
{
	char symbol = 0;

	//Count symbols in the string. 
	for (size_t i = 0; i < symbols.size(); i++)
	{
		symbol = symbols[i];

		//First symbol, cant be duplicate.
		if (symbolContainer -> empty())
		{
			symbolContainer -> push_back(countSymbol(symbol));
		}
		//Has at least one member
		else
		{
			bool dup = false;
			//Search container for dublicate.
			for (size_t d = 0; d < symbolContainer->size(); d++)
			{
				if (symbol == (*symbolContainer)[d].first)
				{
					dup = true;
					break;
				}
			}

			if (dup == false)
			{
				symbolContainer ->push_back(countSymbol(symbol));
			}
			
		}
		
	}
}


//Print Contents of container to the screen.
void symbolFreq::printContainer()
{
	for (size_t i = 0; i < symbolContainer -> size(); i++)
	{
		cout << (*symbolContainer)[i].first << ": "<< (*symbolContainer)[i].second<<endl;
	}
}

vector<pair<char, int>>* symbolFreq::getSymbolContainer()
{
	return symbolContainer;
}


//Sort the counted symbols into most common first.
void symbolFreq::sortSymbols()
{
	//Force the sort function to use the seccond element in pair to sort by.
	sort(begin((*symbolContainer)), end((*symbolContainer)), [](const pair<char, int> &a, const pair<char, int> &b) {return a.second > b.second; });
}