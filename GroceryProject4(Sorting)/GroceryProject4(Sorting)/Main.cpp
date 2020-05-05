#include <iostream>
#include <fstream>
#include <string>
#include "Grocery.h"
#include "LinkList.h"
#include "Item.h"

using namespace std;

int main() {
	int kCounter = 0;
	int choice;
	int counter = 0;
	int currentMax = 25;
	string searchObj;
	string command1;
	string fName;
	string updateName;
	string addName;
	string deleteName;
	ifstream inFile;
	ifstream inFileUpdate;
	ifstream inFileAdd;
	ifstream inFileDelete;
	ifstream inFileSort;
	ofstream outFile;
	linkList groceryList;

	//Create the linkList object
	linkList* linkedList = new linkList;

	outFile.open("inventoryReport.txt");

	while (cin) {
		cout << "Please select one of the opitions below" << endl;			//User menu
		cout << "1 - Load Inventory" << endl;
		cout << "2 - Print Data" << endl;
		cout << "3 - Price Update" << endl;
		cout << "4 - Item Add" << endl;
		cout << "5 - Item Delete" << endl;
		cout << "6 - Inventory Sort" << endl;
		cout << "7 - Info about opening the file and update file" << endl;
		cout << "0 - Exit" << endl;
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			cout << "Please enter file name: ";				//command to enter file 
			cin >> fName;
			inFile.open(fName.c_str());
			if (!inFile) {
				cout << "Unsuppored File: Please enter correct file name. " << endl;
			}
			groceryList.invLoad(inFile);
			inFile.close();
			break;
		case 2:
			groceryList.printGroceryData(outFile);			//command to print data
			break;
		case 3:
			cout << "Please enter update file name: ";				//command to enter update file name
			cin >> updateName;
			inFileUpdate.open(updateName.c_str());
			if (!inFileUpdate) {
				cout << "Unsuppored File: Please enter correct file name. " << endl;
			}
			groceryList.updateInventories(inFileUpdate, searchObj);
			break;
		case 4:
			cout << "Please enter inventory add file name: ";			//command to enter add file name
			cin >> addName;
			inFileAdd.open(addName.c_str());
			if (!inFileAdd) {
				cout << "Unsupported File: Please enter correct file name. " << endl;
			}
			groceryList.invAdd(inFileAdd, counter, currentMax);
			break;
		case 5:
			cout << "Please enter inventory delete file name: ";			//command to enter delete file name
			cin >> deleteName;
			inFileDelete.open(deleteName.c_str());
			if (!inFileDelete) {
				cout << "Unsupported File: Please enter correct file name. " << endl;
			}
			groceryList.invDelete(inFileDelete);
			break;
		case 6:														//command to sort file
			groceryList.bubbleSort(inFileSort);
			break;
		case 7:														//command to find out what each file is
			cout << "Enter command followed by ?: ";
			cin >> command1;
			if (command1 == "inventory1.txt ?" || "inventory2.txt ?") {
				cout << "Inventory reports that is read into programs to be processed. " << endl;
			}
			else if (command1 == "priceUpdate1.txt ?" || "priceUpdate2.txt ?") {
				cout << "Update files that are used to update existing inventory report. " << endl;
			}
			else if (command1 == "inventoryAdd1.txt ?" || "inventoryAdd2.txt ?") {
				cout << "Adds items to the end of the report." << endl;
			}
			else if (command1 == "inventoryDelete1.txt ?" || "inventoryDelete2.txt ?") {
				cout << "Deletes certain items from report." << endl;
			}
			else {
			}
			system("pause");
			system("CLS");
		case 0:												//command to close program
			groceryList.bubbleSort(inFileSort);				//will sort program at the when close
			groceryList.printGroceryData(outFile);			//prints final report when the user closes program as stated in the specifications
			return 0;
			break;
		default:
			cout << "Unsupported Command. " << endl;
			break;
		}
	}

	inFileUpdate.close();
	outFile.close();

	system("pause");
	return 0;
}