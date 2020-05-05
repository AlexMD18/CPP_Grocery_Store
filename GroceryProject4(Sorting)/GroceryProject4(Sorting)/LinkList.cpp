#include "LinkList.h"
#include "LinkNode.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

//Default Constructor
linkList::linkList()
{
	itemCount = 0;
	head = tail = current = NULL;
}

//Parameterized Constructor
linkList::linkList(int inItemCount)
{
	itemCount = inItemCount;
}

//Copy Constructor
linkList::linkList(const linkList& linkListToCopy)
{
	itemCount = linkListToCopy.itemCount;
}

//Destructor
linkList::~linkList()
{
	linkNode* toDelete = head;

	while (toDelete != NULL)
	{
		head = head->getNext();
		delete toDelete;
		toDelete = head;
	}

	head = tail = current = NULL;
}

//Checks whether or not the list is empty
bool linkList::isEmpty() const
{
	return(head == NULL);
}

//Checks whether the current pointer for the linkList object has a target
bool linkList::inList() const
{
	return(current != NULL);
}

//Inserts a new node at the head of the list
bool linkList::prefixNode(const item& newData)
{
	linkNode* newNode = new(nothrow) linkNode(newData);

	if (newNode == NULL)
	{
		return false;
	}

	if (isEmpty())
	{
		newNode->setNext(NULL);
		head = tail = current = newNode;
		return true;
	}

	newNode->setNext(head);
	head = newNode;

	return true;
}

bool linkList::insert(const item& newData)
{
	if (!inList())
	{
		return false;
	}

	linkNode* newNode = new(nothrow) linkNode(newData);

	if (newNode == NULL)
	{
		return false;
	}

	if (isEmpty())
	{
		newNode->setNext(NULL);
		head = tail = current = newNode;
		return true;
	}

	newNode->setNext(current->getNext());
	current->setNext(newNode);

	return true;
}

//Moves the current pointer to the head of the list
void linkList::goToHead()
{
	current = head;
}

//Moves the current pointer to the tail of the list
void linkList::goToTail()
{
	current = tail;
}

//Deletes the node at the current position…if possible
bool linkList::deleteCurrentNode()
{
	linkNode* deleteNode;

	itemCount--;

	if (current == NULL)
	{
		return false;
	}

	if (current == head)
	{
		deleteNode = current;
		head = head->getNext();
		current = head;

		if (tail == deleteNode)
		{
			tail = current;
		}

		delete deleteNode;
		return true;
	}

	//Locate Curr’s previous node
	linkNode* previousNode = head;

	while (previousNode->getNext() != current)
	{
		linkNode* temp = previousNode->getNext();
		previousNode = temp;
	}

	while ((previousNode != NULL) && (previousNode->getNext() == current))
	{
		//check for valid Curr pointer
		if (previousNode == NULL)
		{
			return false;
		}

		//previous node found…bypass and delete Curr
		deleteNode = current;
		previousNode->setNext(current->getNext());
		current->setNext(NULL);
		current = previousNode->getNext();

		if (tail == deleteNode)	//Check to see if we are deleteing the tail
		{
			tail = previousNode;
		}

		delete deleteNode;
		deleteNode = NULL;
		return true;
	}
	return false;
}

//Advances the current position to the nect node in the list
bool linkList::advance()
{
	if (inList())
	{
		current = current->getNext();
		return true;
	}
	else
	{
		return false;
	}
}

//Replaces the data element in the current node
bool linkList::setCurrentData(const item& newData)
{
	if (inList())
	{
		current->setData(newData);
		return true;
	}
	else
	{
		return false;
	}
}

//Return the data elementof the current node
item linkList::getCurrentData() const
{
	if (inList())
	{
		return current->getData();
	}
	else
	{
		item emptyItem;
		return emptyItem;
	}
}

void linkList::addNode(groceryInfo tempItem)
{
	linkNode *newNode;
	newNode = new linkNode;
	newNode->setData(tempItem);
	newNode->setNext(NULL);

	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
		itemCount++;
	}
	else
	{
		tail->setNext(newNode);
		tail = newNode;
		itemCount++;
	}
}

//Overload less than operator
bool linkList::operator<(const linkList& otherList) const
{
	return (head == otherList.head && current == otherList.current && tail == otherList.tail && itemCount == otherList.itemCount);
}

//Overload greater than operator
bool linkList::operator>(const linkList& otherList) const
{
	return (head == otherList.head && current == otherList.current && tail == otherList.tail && itemCount == otherList.itemCount);
}

//Binary search function
bool linkList::binarySearch(string searchObj)
{	

	/*if (tail->getSKU() < head->getSKU())			//I was unable to get the binary search working
	{												but I understand that the search needs to cut the
		return -1;									data in half first. Then it looks at the data member
	}												and decides which side it should be on (smaller or larger data)
	else											and replaces data. I just can't seem to get it to work with a 
	{												linked list. I just didn't have the time with the finals of my 
		middle = (start + end) / 2;					other classes in order to get this running properly.
		if (itemCount > searchObj)					I just reimplemented the old one so it would work.
		{
			return binarySearch(searchObj, start, middle - 1);
		}
		else if (itemCount < searchObj)
		{
			return binarySearch(searchObj, start, middle + 1);
		}
		else
		{
			return middle;
		}
	}*/

	linkNode* current = head;						//This is an example that i found in the book and tried to make it into a linked list function.
	while (current != NULL)
	{
		if(searchObj == current->getSKU())
		{
		break;
		}
		current = current->getNext();
	}
	return current;
}

void linkList::invLoad(ifstream& inFile)
{
	groceryInfo tempGroceryItem;
	int inputOrder[6];
	string loadList[6];
	for (int i = 0; i < 6; i++) {
		inFile >> loadList[i];

		if (loadList[i] == "SKU") {							//reads through and orders data
			inputOrder[i] = 0;
		}
		else if (loadList[i] == "Item") {
			inputOrder[i] = 1;
		}
		else if (loadList[i] == "Retail") {
			inputOrder[i] = 2;
		}
		else if (loadList[i] == "Cost") {
			inputOrder[i] = 3;
		}
		else if (loadList[i] == "Floor") {
			inputOrder[i] = 4;
		}
		else if (loadList[i] == "Warehouse") {
			inputOrder[i] = 5;
		}
	}

	inFile.ignore(255, '\n');

	while (!inFile.eof())
	{
		for (int j = 0; j < 6; j++) {											//data tokenizer
			if (inputOrder[j] == 0) {
				tempGroceryItem.setSKU(inFile);
			}
			else if (inputOrder[j] == 1) {
				tempGroceryItem.setItem(inFile);
			}
			else if (inputOrder[j] == 2) {
				tempGroceryItem.setRetail(inFile);
			}
			else if (inputOrder[j] == 3) {
				tempGroceryItem.setCost(inFile);
			}
			else if (inputOrder[j] == 4) {
				tempGroceryItem.setFloor(inFile);
			}
			else if (inputOrder[j] == 5)
				tempGroceryItem.setWarehouse(inFile);
		}
		inFile.ignore(255, '\n');
		addNode(tempGroceryItem);
		if (inFile.peek() == EOF)
		{
			break;
		}
	}
}

void linkList::printGroceryData(ofstream& outFile)
{
	groceryInfo tempGroceryObj;
	string line;
	current = head;
	string SKUHolder = "SKU";
	string itemHolder = "Item";
	string retailHolder = "Retail";
	string costHolder = "Cost";
	string floorHolder = "Floor";
	string warehouseHolder = "Warehouse";
	outFile << fixed << setprecision(2);
	outFile << "Simple Inventory Management System (SIMS) " << endl;						//  \/\/Puts the data into the correct order, and formats to be printed\/\/
	outFile << "-----------------------------------------------------" << endl;
	outFile << left << setw(10) << SKUHolder << setw(40) << itemHolder << setw(10) << retailHolder << setw(10) << costHolder << setw(10) << floorHolder << setw(10) << warehouseHolder << endl;
	outFile << "-------------------------------------------------------------------------------------------" << endl;


	for (int i = 0; i < itemCount; i++)
	{
		tempGroceryObj = current->getData();
		outFile << tempGroceryObj;
		advance();
	}
	outFile << "-------------------------------------------------------------------------------------------" << endl;
	outFile << "Total Items: " << itemCount << endl;
}

void linkList::updateInventories(ifstream &inFile, string searchObj)
{
	groceryInfo tempGroceryArray[100];
	groceryInfo groceryObj;
	int st = 0;
	int inputOrder[4];
	string updateList[4];
	for (int i = 0; i < 4; i++) {
		inFile >> updateList[i];

		if (updateList[i] == "SKU")
		{										//reads through and orders data
			inputOrder[i] = 0;
		}
		else if (updateList[i] == "Item")
		{
			inputOrder[i] = 1;
		}
		else if (updateList[i] == "Retail")
		{
			inputOrder[i] = 2;
		}
		else if (updateList[i] == "Cost")
		{
			inputOrder[i] = 3;
		}
	}
	inFile.ignore(255, '\n');

	while (!inFile.eof())
	{
		for (int j = 0; j < 4; j++) {

			switch (inputOrder[j])
			{											//data tokenizer
			case 0:
				tempGroceryArray[st].setSKU(inFile);
				break;
			case 1:
				tempGroceryArray[st].setItem(inFile);
				break;
			case 2:
				tempGroceryArray[st].setRetail(inFile);
				break;
			case 3:
				tempGroceryArray[st].setCost(inFile);
				break;
			}
		}
		st++;
		inFile.ignore(255, '\n');
		if (inFile.peek() == EOF)
		{
			break;
		}
	}

	binarySearch(searchObj);

	for (int tempCounter = 0; tempCounter < st; tempCounter++)
	{
		current = head;

		for (int groceryCounter = 0; groceryCounter < itemCount; groceryCounter++)
		{																							//Reads through data infiles and replaces the old records with the updated versions
			groceryObj = current->getData();
			if (groceryObj.getSKU() == tempGroceryArray[tempCounter].getSKU())
			{
				groceryObj.setRetail(tempGroceryArray[tempCounter].getRetail());
				groceryObj.setCost(tempGroceryArray[tempCounter].getCost());
				setCurrentData(groceryObj);
			}
			advance();
		}
	}
}

void linkList::invAdd(ifstream& inFile, int& k, int& currentMax)
{
	groceryInfo tempGroceryListInfo;
	int count = 0;
	int inputOrder[6];
	string addArray[6];
	for (int i = 0; i < 6; i++) {
		inFile >> addArray[i];

		if (addArray[i] == "SKU") {								//reads through and orders data
			inputOrder[i] = 0;
		}
		else if (addArray[i] == "Item") {
			inputOrder[i] = 1;
		}
		else if (addArray[i] == "Retail") {
			inputOrder[i] = 2;
		}
		else if (addArray[i] == "Cost") {
			inputOrder[i] = 3;
		}
		else if (addArray[i] == "Floor") {
			inputOrder[i] = 4;
		}
		else if (addArray[i] == "Warehouse") {
			inputOrder[i] = 5;
		}	//end if
	}//end for

	inFile.ignore(255, '\n');

	while (!inFile.eof()) {
		for (int j = 0; j < 6; j++) {											//data tokenizer
			if (inputOrder[j] == 0) {
				tempGroceryListInfo.setSKU(inFile);
			}
			else if (inputOrder[j] == 1) {
				tempGroceryListInfo.setItem(inFile);
			}
			else if (inputOrder[j] == 2) {
				tempGroceryListInfo.setRetail(inFile);
			}
			else if (inputOrder[j] == 3) {
				tempGroceryListInfo.setCost(inFile);
			}
			else if (inputOrder[j] == 4) {
				tempGroceryListInfo.setFloor(inFile);
			}
			else if (inputOrder[j] == 5)
				tempGroceryListInfo.setWarehouse(inFile);
		}
		inFile.ignore(255, '\n');
		addNode(tempGroceryListInfo);
		if (inFile.peek() == EOF)
		{
			break;
		}
	}
}

void linkList::invDelete(ifstream& inFile)
{
	groceryInfo tempDeleteObj;
	int st = 0;
	string deleteArray[100];
	inFile.ignore(255, '\n');
	while (!inFile.eof())
	{
		inFile >> deleteArray[st];
		st++;
		if (inFile.peek() == EOF)
		{
			break;
		}
	}

	for (int tempCounter = 0; tempCounter < st; tempCounter++)
	{
		current = head;
		tempDeleteObj.setSKU(deleteArray[tempCounter]);

		for (int groceryCounter = 0; groceryCounter < itemCount; groceryCounter++)
		{
			if (tempDeleteObj.getSKU() == current->getSKU())				//finds and matches SKUs
			{
				deleteCurrentNode();
				break;
			}
			advance();
		}
	}
}

//Bubble sort function
//Reads through and compares items to put them in ascending order
void linkList::bubbleSort(ifstream& inFile)
{
	int counter = 0;
	linkNode* tempNext = nullptr;				
	linkNode* previousNode = nullptr;
	linkNode* temp = nullptr;

	for (int k = 0; k < itemCount; k++)
	{
		current = head;
		counter = 0;
		tempNext = current->getNext();
		for (int i = 1; i < itemCount; i++, advance())
		{
			if (i > 1)										
			{
				previousNode = head;
				while (previousNode->getNext() != current)
				{
					temp = previousNode->getNext();			//Advancer
					previousNode = temp;
				}
			}
			if (current->getSKU() > tempNext->getSKU())		//If the current data object is greater than the next one
			{
				if (current == head)						//If the current data object is at the head of the list
				{
					head = tempNext;
					current->setNext(tempNext->getNext());
					tempNext->setNext(current);				//Begin to swich items
					tempNext = current;
					current = head;
				}
				else if (tempNext == tail)					//If the current data object is at the tail of the list
				{
					tail = current;
					current->setNext(nullptr);				//Set end to null
					previousNode->setNext(tempNext);		
					tempNext->setNext(current);
					current = tempNext;
					tempNext = tempNext->getNext();
				}
				else
				{
					current->setNext(tempNext->getNext());	//If the current data object is in the middle
					tempNext->setNext(current);
					previousNode->setNext(tempNext);
					current = tempNext;
					tempNext = tempNext->getNext();
				}
				counter++;
			}
			tempNext = tempNext->getNext();					//Advancer
			if (i > 1)
			{
				previousNode = previousNode->getNext();
			}
		}
	}
}