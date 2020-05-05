#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Grocery.h"

using namespace std;

//Default Constructor
groceryInfo::groceryInfo()
{
	//default values
	SKU = "NO SKU";
	item = "NO ITEM";
	retail = -1.00;
	cost = -1.00;
	floor = -1;
	warehouse = -1;
}

//Parameterized Constructor
groceryInfo::groceryInfo(string inSKU, string inItem, float inRetail, float inCost, int inFloor, int inWarehouse)
{
	SKU = inSKU;
	item = inItem;
	retail = inRetail;
	cost = inCost;
	floor = inFloor;
	warehouse = inWarehouse;
}

//Copy Constructor
groceryInfo::groceryInfo(const groceryInfo& groceryToCopy)
{
	SKU = groceryToCopy.SKU;
	item = groceryToCopy.item;
	retail = groceryToCopy.retail;
	cost = groceryToCopy.cost;
	floor = groceryToCopy.floor;
	warehouse = groceryToCopy.warehouse;
}

groceryInfo& groceryInfo::operator=(const groceryInfo *rhs)
{
	if (this != rhs)
	{
		SKU = rhs->SKU;
		item = rhs->item;
		retail = rhs->retail;
		cost = rhs->cost;
		floor = rhs->floor;
		warehouse = rhs->warehouse;
	}
	return *this;
}



ostream& operator<<(ostream& outFile, groceryInfo& tempPrint)
{
	outFile << left << setw(10) << tempPrint.getSKU() << setw(40) << tempPrint.getItem() << setw(10) << tempPrint.getRetail() << setw(10) << tempPrint.getCost() << setw(10) << tempPrint.getFloor() << setw(10) << tempPrint.getWarehouse() << endl;

	return outFile;
}
