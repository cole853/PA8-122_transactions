/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#pragma once

#include "Node.h"

class TransactionNode : public Node
{
public:

	//constructor
	TransactionNode(string& newData, int& newUnits);

	//destructor
	~TransactionNode();

	//setter
	void setUnits(int &newUnits);

	//getter
	int getUnits();

	//print data 
	void printData();

private:

	int mUnits;

};