# PA8-122_transactions
This BST project takes sales and purchase data from a csv file and finds high and low for both transaction types. Completed on 4/13/2021.

Results are printed to the terminal.

# Ten Files Are Required:

Node.h: contains the Node class which is a binary search tree node.

Node.cpp: contains the definitions for Node class functions.

TransactionNode.h: contains the TransactionNode class which inherits from the Node class. Transaction nodes have a number of units that nodes don't. 

TransactionNode.cpp: contains definitions for TransactionNode class functions.

BST.h: contains the BST class which has a binary search tree of Node objects and functions to modify it.

BST.cpp: contains definitions for BST class functions.

DataAnalysis.h: contains the DataAnalysis class where information from the Data.csv file is loaded as a purchase BST and sales BST.

DataAnalysis.cpp: contains definitions for DataAnalysis class functions.

main.cpp: contains the main function where DataAnalysis.runAnalysis() is called.

Data.csv: contains purchased and sold data for different items.
