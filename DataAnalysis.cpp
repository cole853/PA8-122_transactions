/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#include "DataAnalysis.h"

//constructor
DataAnalysis::DataAnalysis()
{
	bool check = openFile();

	if (check == false)
	{
		cout << "mCsvStream !good() in Constructor." << endl;
	}
}

//destructor
DataAnalysis::~DataAnalysis()
{
	mCsvStream.close();
}

//run analysis
void DataAnalysis::runAnalysis()
{
	readAll();
	printResults();
	system("pause");
}



//opens the CSV file
bool DataAnalysis::openFile()
{
	mCsvStream.open("Data.csv");

	if (mCsvStream.good())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//reads and splits one line
void DataAnalysis::readLine(int &units, string &type, string &transaction)
{
	char tempUnits[100] = "";
	char tempType[100] = "";
	char tempTransaction[100] = "";

	mCsvStream.getline(tempUnits, 100, ',');
	mCsvStream.getline(tempType, 100, ',');
	mCsvStream.getline(tempTransaction, 100);

	units = atoi(tempUnits);
	type = tempType;
	transaction = tempTransaction;
}

//reads sorts and displays the contents of the file
void DataAnalysis::readAll()
{
	if (mCsvStream.good())
	{
		int units;
		string type;
		string transaction;

		char dummy[100] = "";
		mCsvStream.getline(dummy, 100);

		while (mCsvStream.good())
		{
			readLine(units, type, transaction);
			insertInTree(units, type, transaction);
		}

		cout << "Sold" << endl << endl;
		mTreeSold.inOrderTraversal();
		cout << endl << endl << endl << "Purchased" << endl << endl;
		mTreePurchased.inOrderTraversal();
		cout << endl << endl;

	}
	else
	{
		cout << "mCsvStream !good() in readAll()" << endl;
	}
}

//inserts the line into the appropriate tree
void DataAnalysis::insertInTree(int& units, string& type, string& transaction)
{
	if (transaction == "Purchased")
	{
		mTreePurchased.insert(type, units);
	}
	else if (transaction == "Sold")
	{
		mTreeSold.insert(type, units);
	}
	else
	{
		cout << "Error in InsertInTree() transaction not Sold or Purchased." << endl;
	}
}

//prints the least and most purchased and sold
void DataAnalysis::printResults()
{
	cout << "Most sold: " << mTreeSold.findLargest().getData() << "\t\tUnits: " << mTreeSold.findLargest().getUnits() << endl
		<< "Least sold: " << mTreeSold.findSmallest().getData() << "\t\tUnits: " << mTreeSold.findSmallest().getUnits() << endl << endl
		<< "Most purchased: " << mTreePurchased.findLargest().getData() << "\tUnits: " << mTreePurchased.findLargest().getUnits() << endl
		<< "Least purchased: " << mTreePurchased.findSmallest().getData() << "\tUnits: " << mTreePurchased.findSmallest().getUnits() << endl << endl;
}