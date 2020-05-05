#include "LinkNode.h"

//Default constructor
linkNode::linkNode()
{
	next = NULL;
}


//Parameterized Constructor
linkNode::linkNode(item& data)
{
	this->data = data;
}

//Copy Constructor
linkNode::linkNode(const item& newData)
{
	data = newData;
	next = NULL;
}

//Destructor
linkNode::~linkNode()
{
	next = NULL;
}

//Sets a new value for the data element object
void linkNode::setData(const item& newData)
{
	data = newData;
}

//Sets a new value for the next pointer
void linkNode::setNext(linkNode* const newNext)
{
	next = newNext;
}

//Returns the value of the data element object
item linkNode::getData() const
{
	return data;
}

//Returns the value of the next pointer
linkNode* linkNode::getNext() const
{
	return next;
}

string linkNode::getSKU()
{
	return data.getSKU();
}