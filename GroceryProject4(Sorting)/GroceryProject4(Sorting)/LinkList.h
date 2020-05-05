#pragma once

#include "LinkNode.h"
#include "Item.h"

class linkList
{
private:
	linkNode* head;		//Points to the head node in the list
	linkNode* tail;		//Points to the tail node in the lsit
	linkNode* current;	//points to the current node in the list
	linkNode* middle;
	int itemCount;

public:
	//Constructor
	linkList();

	//Parameterized Constructor
	linkList(int inItemCount);

	//Copy Constructor
	linkList(const linkList& linkListToCopy);

	//Destructor
	~linkList();

	//Reporters
	bool isEmpty() const;
	bool inList() const;
	bool operator<(const linkList& otherList) const;
	bool operator>(const linkList& otherList) const;
	item getCurrentData() const;

	//Mutators
	bool prefixNode(const item& newData);
	bool insert(const item& newData);
	bool advance();
	void addNode(groceryInfo tempItem);
	void goToHead();
	void goToTail();
	bool deleteCurrentNode();
	bool setCurrentData(const item& newData);
	void invLoad(ifstream& inFile);
	void printGroceryData(ofstream& outFile);
	void updateInventories(ifstream& inFile, string searchObj);
	void invAdd(ifstream& inFile, int& k, int& currentMax);
	void invDelete(ifstream& inFile);
	void bubbleSort(ifstream& inFile);
	bool binarySearch(string searchObj);
};