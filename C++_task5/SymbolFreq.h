#pragma once
#ifndef SYMBOL_FREQ_H
#define SYMBOL_FREQ_H

#include <string>
#include <vector>
#include <utility>

using namespace std;

class symbolFreq
{
public:
	//Constructor.
	//Input string name of the file, which the symbols will be counted and sorted.
	symbolFreq(string);

	//Destructor.
	~symbolFreq();

	//Print Container of symbols.
	void printContainer();

	//Output contents of symbolContainer.
	vector<pair<char, int>>* getSymbolContainer();
	
private:
	string symbols;

	vector<pair<char, int>>* symbolContainer;

	//Count the frequency of a symbol in given string.
	pair<char, int>countSymbol(char);

	//Count the frequency of all the symbols in a string.
	void countAllSymbols(string);

	//Sort the counted symbols into most common first.
	void sortSymbols();
};


#endif // !SYMBOL_FREQ.h
