/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#include "Node.h"

//constructor
Node::Node(string& newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

//virtual destructor
Node::~Node()
{
	cout << "Inside Node's destructor!" << endl;
}

//setters
void Node::setData(string& newData)
{
	mData = newData;
}

void Node::setLeft(Node*& newLeft)
{
	mpLeft = newLeft;
}

void Node::setRight(Node*& newRight)
{
	mpRight = newRight;
}

//getters
string Node::getData()
{
	return mData;
}

Node*& Node::getLeft()
{
	return mpLeft;
}

Node*& Node::getRight()
{
	return mpRight;
}