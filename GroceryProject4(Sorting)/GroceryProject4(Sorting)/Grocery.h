#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class groceryInfo
{
public:
	//Constructors
	groceryInfo();
	groceryInfo(string inSKU, string inItem, float inRetail, float inCost, int inFloor, int inWarehouse);

	//Copy Constructor
	groceryInfo(const groceryInfo& groceryToCopy);

	//Overload Assignment Operator
	groceryInfo& operator=(const groceryInfo *rhs);

	//Reporters
	inline string getSKU() { return SKU; };
	inline string getItem() { return item; };
	inline float getRetail() { return retail; };
	inline float getCost() { return cost; };
	inline int getFloor() { return floor; };
	inline int getWarehouse() { return warehouse; };

	//Mutators
	inline void setSKU(string inSKU)
	{
		SKU = inSKU;
	};
	inline void setItem(string inItem)
	{
		item = inItem;
	};
	inline void setRetail(float inRetail)
	{
		retail = inRetail;
	};
	inline void setCost(float inCost)
	{
		cost = inCost;
	};
	inline void setFloor(int inFloor)
	{
		floor = inFloor;
	};
	inline void setWarehouse(int inWarehouse)
	{
		warehouse = inWarehouse;
	};

	//---------------------------------------------OverLoaded Mutators----------------------------------------------------
	inline void setSKU(ifstream& inFile)
	{
		getline(inFile, SKU, '\t');
	};

	inline void setItem(ifstream& inFile)
	{
		getline(inFile, item, '\t');
	};

	inline void setRetail(ifstream& inFile)
	{
		inFile >> retail;
	};

	inline void setCost(ifstream& inFile)
	{
		inFile >> cost;
	};

	inline void setFloor(ifstream& inFile)
	{
		inFile >> floor;
	};

	inline void setWarehouse(ifstream& inFile)
	{
		inFile >> warehouse;
	};


	friend ostream& operator<<(ostream& outFile, groceryInfo& tempPrint);


private:
	string SKU;
	string item;
	float retail;
	float cost;
	int floor;
	int warehouse;
};