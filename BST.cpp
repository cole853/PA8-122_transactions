/*
		Programmer: Cole Clark
		Date: 4/13/2021

			Description: trend analysis program for PA8
*/

#include "BST.h"


//constructor
BST::BST()
{
	mpRoot = nullptr;
}

//destructor
BST::~BST()
{
	cout << "Inside BST's destructor! Deleting all nodes." << endl;
	destroyTree(mpRoot);
}

void BST::destroyTree(Node* tree)
{
	if (tree != nullptr)
	{
		destroyTree(tree->getLeft());
		destroyTree(tree->getRight());
		delete tree;
	}
}

//setter
void BST::setRoot(Node*& newRoot)
{
	mpRoot = newRoot;
}

//getter
Node* BST::getRoot()
{
	return mpRoot;
}

//insert
void BST::insert(string newData, int newUnits)
{
	insert(mpRoot, newData, newUnits);
}

void BST::insert(Node*& pT, string newData, int newUnits)
{
	TransactionNode* newNode = nullptr;

	if (pT == nullptr)
	{
		pT = new TransactionNode(newData, newUnits);
	}
	else if (newUnits < ((TransactionNode*)pT)->getUnits() && pT->getLeft() == nullptr)
	{
		newNode = new TransactionNode(newData, newUnits);

		pT->setLeft((Node*&) newNode);
	}
	else if (newUnits > ((TransactionNode*)pT)->getUnits() && pT->getRight() == nullptr)
	{
		newNode = new TransactionNode(newData, newUnits);

		pT->setRight((Node*&) newNode);
	}
	else if (newUnits < ((TransactionNode*)pT)->getUnits())
	{
		insert(pT->getLeft(), newData, newUnits);
	}
	else if (newUnits > ((TransactionNode*)pT)->getUnits())
	{
		insert(pT->getRight(), newData, newUnits);
	}
}

//traversal
void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::inOrderTraversal(Node* tree)
{
	if (tree != nullptr)
	{
		inOrderTraversal(tree->getLeft());
		tree->printData();
		inOrderTraversal(tree->getRight());
	}
}

//find smallest
TransactionNode& BST::findSmallest()
{
	TransactionNode* current = (TransactionNode*) mpRoot;

	while (current->getLeft() != nullptr)
	{
		current = (TransactionNode*)current->getLeft();
	}

	return *current;
}

//find Largest
TransactionNode& BST::findLargest()
{
	TransactionNode* current = (TransactionNode *) mpRoot;

	while (current->getRight() != nullptr)
	{
		current = (TransactionNode*)current->getRight();
	}

	return *current;
}