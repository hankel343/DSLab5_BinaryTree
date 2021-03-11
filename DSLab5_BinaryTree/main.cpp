#include <iostream>
#include "BiTree.h"

using namespace std;

void ProcessInput(char cInput, BiTree& Tree);
void AddCase(BiTree& Tree);
void DeleteCase(BiTree& Tree);

int main()
{
	BiTree Tree;
	char cInput = -1;

	cout << "This program allows you to perform operations on a binary tree.\n";
	do
	{
		cout << "##################################################################\n";
		cout << "Your input for this program should be a website name as a string.\n";
		cout << "##################################################################\n";

		cout << "\n\nMake your selection from the menu of options below: \n";
		cout << "1 - Add a website to the tree.\n";
		cout << "2 - Delete a website from the tree.\n";
		cout << "3 - Print the tree in sorted order.\n";
		cout << "4 - Print the tree in reversed order.\n";
		cout << "5 - Print a graphical representation of the tree.\n";
		cout << "Q - Quit.\n";
		cout << "Input: ";
		cin >> cInput;

		system("cls");
		ProcessInput(cInput, Tree);
	} while (toupper(cInput) != 'Q');

	cout << "Goodbye...\n";

	return 0;
}

void ProcessInput(char cInput, BiTree& Tree)
{
	switch (toupper(cInput))
	{
	case '1':	AddCase(Tree);
				break;

	case '2':	DeleteCase(Tree);
				break;

	case '3':	Tree.Print();
				break;

	case '4':	Tree.RPrint();
				break;

	case '5':	Tree.TPrint();
				break;

	case 'Q':	break;

	default:	cout << "Unrecognized input - try again.\n";
				break;
	}
}

void AddCase(BiTree& Tree)
{
	ItemType iNewItem;
	string sNewData = " ";
	cout << "Enter the string you want to add to the tree: ";
	cin >> sNewData;
	iNewItem.Set(sNewData);
	Tree.Add(iNewItem);
}

void DeleteCase(BiTree& Tree)
{
	ItemType iDeletedItem;
	string sDeletedData = " ";
	cout << "Enter the string you want to delete from the tree: ";
	cin >> sDeletedData;
	iDeletedItem.Set(sDeletedData);
	Tree.Remove(iDeletedItem);
}