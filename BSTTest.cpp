//============================================================================
// Name        : BSTTest.cpp
// Author      : Khadeja Khalid and Tiffany Tran
// Version     : CIS 22C Lab 6
//============================================================================

#include <iostream>
#include <cstddef>
#include <string>
#include "BST.h"

using namespace std;

int main()
{
	BST<int> iB;
	BST<int> ieB; //empty int
	BST<string> sB;
	BST<string> seB; //empty string

	cout << "\n*************** Testing insert ************************\n";

	cout << " Testing int:\n";

	cout << "Insert: 12 10 14 9 11 15 10" << endl;
	iB.insert(12);
	iB.insert(10);
	iB.insert(14);
	iB.insert(9);
	iB.insert(11);
	iB.insert(15);
	iB.insert(10); //Should not actually be inserted, duplicate

	cout << "\n Testing string: \n";

	cout << "Insert: banana apple orange grape juice" << endl;
	sB.insert("banana");
	sB.insert("apple");
	sB.insert("orange");
	sB.insert("grape");
	sB.insert("juice");

	cout << "\n*************** Testing print ************************\n\n";

	cout << " Testing int:\n";

	cout << "Should print out in order: ";
	iB.inOrderPrint(cout);
	ieB.inOrderPrint(cout); //Should not print anything
	cout << endl;

	cout << "Should print out in peorder: ";
	iB.preOrderPrint(cout);
	ieB.preOrderPrint(cout); //Should not print anything
	cout << endl;

	cout << "Should print out in postorder: ";
	iB.postOrderPrint(cout);
	ieB.postOrderPrint(cout); //Should not print anything
	cout << endl;

	cout << "\n Testing string: \n";
	cout << "Should print out in order: ";
	sB.inOrderPrint(cout);
	seB.inOrderPrint(cout); //Should not print anything
	cout << endl;

	cout << "Should print out in peorder: ";
	sB.preOrderPrint(cout);
	seB.preOrderPrint(cout); //Should not print anything
	cout << endl;

	cout << "Should print out in postorder: ";
	sB.postOrderPrint(cout);
	seB.postOrderPrint(cout); //Should not print anything
	cout << endl;

	cout << "\n*************** Testing Copy Constructor **************\n";

	cout << " Testing int:\n";
	BST<int> iBcopy(iB);
	cout << "Orig: ";
	iB.inOrderPrint(cout);
	cout << "\nCopy: ";
	iBcopy.inOrderPrint(cout);

	cout << endl;

	cout << "\n Testing string: \n";
	BST<string> sBcopy = sB;
	cout << "Orig: ";
	sB.inOrderPrint(cout);
	cout << "\nCopy: ";
	sBcopy.inOrderPrint(cout);

	cout << endl;

	cout << "\n*************** Testing minimum ***********************\n";

	cout << " Testing int:\n";
	cout << "Should print out 9: " << iB.minimum() << endl;

	//ieB.minimum(); //Testing assert

	cout << "\n Testing string: \n";
	cout << "Should print out apple: " << sB.minimum() << endl;

	//seB.minimum(); //Testing assert

	//Testing edge case
	BST<int> B1; //BST with 1 value, leaf node
	B1.insert(7);

	cout << "\n Testing BST of 1: \n";
	cout << "Should print out 7: " << B1.minimum() << endl;

	cout << "\n*************** Testing maximum ***********************\n";

	cout << " Testing int:\n";
	cout << "Should print out 15: " << iB.maximum() << endl;

	cout << "\n Testing string: \n";
	cout << "Should print out orange: " << sB.maximum() << endl;

	cout << "\n Testing BST of 1: \n";
	cout << "Should print out 7: " << B1.maximum() << endl;

	cout << "\n*************** Testing isEmpty ***********************\n";

	cout << "BST should not be empty: ";
	if (iB.isEmpty())
		cout << "BST is empty!" << endl;
	else
		cout << "BST is not empty!" << endl;

	cout << endl;

	cout << "BST should be empty: ";
	if (ieB.isEmpty())
		cout << "BST is empty!" << endl;
	else
		cout << "BST is not empty!" << endl;

	cout << "\n*************** Testing getSize ***********************\n";

	cout << " Testing int:\n";
	cout << "Should print out 6: " << iB.getSize();

	cout << endl;

	cout << "Should print out 0: " << ieB.getSize();

	cout << endl;

	cout << "\n Testing string: \n";
	cout << "Should print out 5: " << sB.getSize();

	cout << "\n*************** Testing getRoot ***********************\n";

	cout << " Testing int:\n";
	cout << "Should print out 12: " << iB.getRoot() << endl;

	cout << "\n Testing string: \n";
	cout << "Should print out banana: " << sB.getRoot() << endl;

	//ieB.getRoot(); //Testing assert
	//seB.getRoot(); //Testing assert

	cout << "\n*************** Testing getHeight *********************\n";

	cout << " Testing int:\n";
	cout << "Should print out 2: " << iB.getHeight() << endl;

	cout << "Should print out 0: " << B1.getHeight() << endl;

	cout << "Should print out -1: " << ieB.getHeight() << endl;

	cout << "\n Testing string: \n";
	cout << "Should print out 3: " << sB.getHeight() << endl;


	cout << "\n*************** Testing search ************************\n";

	cout << " Testing int:\n";
	cout << "Searching for 11: "; //Should exist
	if (iB.search(11))
		cout << "It exists!!" << endl;
	else
		cout << "Nope :(" << endl;

	cout << "Searching for 16: "; //Should not exist
	if (iB.search(16))
		cout << "It exists!!" << endl;
	else
		cout << "Nope :(" << endl;

	//ieB.search(18); //Testing assert

	cout << "\n Testing string: \n";
	cout << "Searching for grape: "; //Should exist
	if (sB.search("grape"))
		cout << "It exists!!" << endl;
	else
		cout << "Nope :(" << endl;

	cout << "Searching for mango: "; //Should not exist
	if (sB.search("mango"))
		cout << "It exists!!" << endl;
	else
		cout << "Nope :(" << endl;

	//seB.search("pinapple"); //Testing assert

	cout << "\n*************** Testing remove ************************\n";

	cout << " Testing int:\n";
	cout << "Removing 15: ";
	//Removing from far right
	cout << "\nBefore: ";
	iB.inOrderPrint(cout);
	iB.remove(15);
	cout << "\nAfter:  ";
	iB.inOrderPrint(cout);
	cout << endl;

	//Removing a leaf node
	cout << "Removing 7 (should print nothing): ";
	cout << "\nBefore: ";
	B1.inOrderPrint(cout);
	B1.remove(7);
	cout << "\nAfter:  ";
	B1.inOrderPrint(cout);

	cout << endl;

	//Removing a root with only a left child
	BST<int> iLB;
	iLB.insert(8);
	iLB.insert(6);
	cout << "Remove root with only left child: ";
	cout << "\nBefore: ";
	iLB.preOrderPrint(cout);
	iLB.remove(8);
	cout << "\nAfter:  ";
	iLB.preOrderPrint(cout);

	cout << endl;

	//Removing a root with only a right child
	BST<int> iRB;
	iRB.insert(8);
	iRB.insert(9);
	cout << "Remove root with only right child: ";
	cout << "\nBefore: ";
	iRB.preOrderPrint(cout);
	iRB.remove(8);
	cout << "\nAfter:  ";
	iRB.preOrderPrint(cout);

	cout << endl;

	cout << "\n Testing string: \n";
	cout << "Removing apple: ";
	//Removing from far left
	cout << "\nBefore: ";
	sB.inOrderPrint(cout);
	sB.remove("apple");
	cout << "\nAfter:  ";
	sB.inOrderPrint(cout);

	cout << endl;

	cout << "Removing grape: ";
	//Removing from middle
	cout << "\nBefore: ";
	sB.inOrderPrint(cout);
	sB.remove("grape");
	cout << "\nAfter:  ";
	sB.inOrderPrint(cout);

	//iB.remove(16); //Testing assert empty
	//seB.remove("mango"); //Testing assert search

	cout << endl;

	cout << "\n*************** Testing Destructor ********************\n";

	cout << " Testing int:\n";
	iB.~BST();
	cout << "Should print out nothing: ";
	iB.inOrderPrint(cout);

	cout << endl;

	cout << "\n Testing string: \n";
	sB.~BST();
	cout << "Should print out nothing: ";
	sB.inOrderPrint(cout);

	cout << "\n\n================================================================\n";
	cout << "Midterm 2 Review" << endl;
	BST<int> BB;

	BB.insert(50);
	BB.insert(17);
	BB.insert(9);
	BB.insert(14);
	BB.insert(12);
	BB.insert(23);
	BB.insert(19);
	BB.insert(76);
	BB.insert(54);
	BB.insert(72);
	BB.insert(67);

	cout << endl;
	BB.inOrderPrint(cout);
	cout << endl;
	BB.preOrderPrint(cout);
	cout << endl;
	BB.postOrderPrint(cout);

	return 0;
}
/*
*************** Testing insert ************************
 Testing int:
Insert: 12 10 14 9 11 15 10

 Testing string:
Insert: banana apple orange grape juice

*************** Testing print ************************

 Testing int:
Should print out in order: 9 10 11 12 14 15
Should print out in peorder: 12 10 9 11 14 15
Should print out in postorder: 9 11 10 15 14 12

 Testing string:
Should print out in order: apple banana grape juice orange
Should print out in peorder: banana apple orange grape juice
Should print out in postorder: apple juice grape orange banana

*************** Testing Copy Constructor **************
 Testing int:
Orig: 9 10 11 12 14 15
Copy: 9 10 11 12 14 15

 Testing string:
Orig: apple banana grape juice orange
Copy: apple banana grape juice orange

*************** Testing minimum ***********************
 Testing int:
Should print out 9: 9

 Testing string:
Should print out apple: apple

 Testing BST of 1:
Should print out 7: 7

*************** Testing maximum ***********************
 Testing int:
Should print out 15: 15

 Testing string:
Should print out orange: orange

 Testing BST of 1:
Should print out 7: 7

*************** Testing isEmpty ***********************
BST should not be empty: BST is not empty!

BST should be empty: BST is empty!

*************** Testing getSize ***********************
 Testing int:
Should print out 6: 6
Should print out 0: 0

 Testing string:
Should print out 5: 5
*************** Testing getRoot ***********************
 Testing int:
Should print out 12: 12

 Testing string:
Should print out banana: banana

*************** Testing getHeight *********************
 Testing int:
Should print out 2: 2
Should print out 0: 0
Should print out -1: -1

 Testing string:
Should print out 3: 3

*************** Testing search ************************
 Testing int:
Searching for 11: It exists!!
Searching for 16: Nope :(

 Testing string:
Searching for grape: It exists!!
Searching for mango: Nope :(

*************** Testing remove ************************
 Testing int:
Removing 15:
Before: 9 10 11 12 14 15
After:  9 10 11 12 14
Removing 7 (should print nothing):
Before: 7
After:
Remove root with only left child:
Before: 8 6
After:  6
Remove root with only right child:
Before: 8 9
After:  9

 Testing string:
Removing apple:
Before: apple banana grape juice orange
After:  banana grape juice orange
Removing grape:
Before: banana grape juice orange
After:  banana juice orange

*************** Testing Destructor ********************
 Testing int:
Should print out nothing:

 Testing string:
Should print out nothing: */
