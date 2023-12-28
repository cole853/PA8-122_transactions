/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#include "TransactionNode.h"

//constructor
TransactionNode::TransactionNode(string & newData, int& newUnits)
:	Node(newData)
{
	mUnits = newUnits;
}

//destructor
TransactionNode::~TransactionNode()
{
	cout << "Inside TransactionNode's destructor!" << endl;
}

//setter
void TransactionNode::setUnits(int& newUnits)
{
	mUnits = newUnits;
}

//getter
int TransactionNode::getUnits()
{
	return mUnits;
}

//print data 
void TransactionNode::printData()
{
	if (mData != "WiiMini")
	{
		cout << mData << "\t" << mUnits << endl;
	}
	else
	{
		cout << mData << "\t\t" << mUnits << endl;
	}
}