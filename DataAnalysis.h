/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#pragma once

#include "BST.h"
#include <fstream>

using std::ifstream;


class DataAnalysis
{
public:

	//constructor
	DataAnalysis();

	//destructor
	~DataAnalysis();

	//run analysis
	void runAnalysis();

private:

	//data members
	BST mTreeSold;

	BST mTreePurchased;

	ifstream mCsvStream;

	//private functions

	//opens the CSV file
	bool openFile();

	//reads and splits one line
	void readLine(int& units, string& type, string& transaction);

	//reads sorts and displays the contents of the file
	void readAll();

	//inserts the line into the appropriate tree
	void insertInTree(int& units, string& type, string& transaction);

	//prints the least and most purchased and sold
	void printResults();


};