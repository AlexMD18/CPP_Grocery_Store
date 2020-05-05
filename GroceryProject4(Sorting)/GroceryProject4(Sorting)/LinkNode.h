#pragma once

#include "Item.h"

class linkNode
{
private:
	item data;
	linkNode* next;		//pointer to the next linkNode

public:
	//Constructors
	linkNode();
	linkNode(item& data);

	//Copy Constructor
	linkNode(const item& newData);

	//Destructor
	~linkNode();

	//Mutators
	void setData(const item& newData);
	void setNext(linkNode* const newNext);

	//Reporters
	item getData() const;
	string getSKU();
	linkNode* getNext() const;
};