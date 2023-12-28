/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#pragma once

#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Node
{
public:

	//constructor
	Node(string& newData);

	//virtual destructor
	virtual ~Node();

	//setters
	void setData(string &newData);

	void setLeft(Node* &newLeft);

	void setRight(Node* &newRight);

	//getters
	string getData();

	Node*& getLeft();

	Node*& getRight();

	//pure virtual print
	virtual void printData() = 0;

protected:

	string mData;

	Node* mpLeft;

	Node* mpRight;

};