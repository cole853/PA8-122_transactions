/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#pragma once

#include "TransactionNode.h"

class BST
{
public:

	//constructor
	BST();

	//destructor
	~BST();

	//setter
	void setRoot(Node*& newRoot);

	//getter
	Node* getRoot();

	//insert
	void insert(string newData, int newUnits);

	//traversal
	void inOrderTraversal();

	//find smallest
	TransactionNode& findSmallest();

	//find Largest
	TransactionNode& findLargest();


private:

	Node* mpRoot;

	void destroyTree(Node* tree);

	void insert(Node*& pT, string newData, int newUnits);

	void inOrderTraversal(Node* tree);

};