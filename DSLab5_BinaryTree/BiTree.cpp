#include "BiTree.h"

BiTree::BiTree()
{
	pRoot = NULL;
}

void BiTree::Add(ItemType iNewItem)
{
	if (IsFull() == false)
		Insert(pRoot, iNewItem);
}

//Helper function to BiTree::Add()
void BiTree::Insert(TreeNode*& pRoot, ItemType iNewItem)
{
	if (pRoot == NULL)
		CreateNode(pRoot, iNewItem);
	else if (iNewItem.ComparedTo(pRoot->iData) == LESS)
		Insert(pRoot->pLeft, iNewItem);
	else if (iNewItem.ComparedTo(pRoot->iData) == GREATER)
		Insert(pRoot->pRight, iNewItem);
}

//Helper function to BiTree::Add()
void BiTree::CreateNode(TreeNode*& pRoot, ItemType iNewItem)
{
	pRoot = new TreeNode;
	pRoot->iData = iNewItem;
	pRoot->pLeft = pRoot->pRight = NULL;
}

void BiTree::Remove(ItemType iDeletedItem)
{
	if (IsEmpty() == false)
		FindDeletionPoint(pRoot, iDeletedItem);
}

//Helper function to BiTree::Remove()
void BiTree::FindDeletionPoint(TreeNode*& pRoot, ItemType iDeletedItem)
{
	if (iDeletedItem.ComparedTo(pRoot->iData) == EQUAL)
		Delete(pRoot, iDeletedItem);
	else if (iDeletedItem.ComparedTo(pRoot->iData) == LESS)
		Delete(pRoot->pLeft, iDeletedItem);
	else if (iDeletedItem.ComparedTo(pRoot->iData) == GREATER)
		Delete(pRoot->pRight, iDeletedItem);
}

//Helper function to BiTree::Remove()
void BiTree::Delete(TreeNode*& pRoot, ItemType iDeletedItem)
{
	TreeNode* pTemp = pRoot;

	if (pRoot->pLeft == NULL)
	{
		pRoot = pRoot->pRight; //Link made to right subtree.
		delete pTemp;
	} else if (pRoot->pRight == NULL) {
		pRoot = pRoot->pLeft; //Link made to left subtree.
		delete pTemp;
	} else { //If there are two child nodes.
		GetInOrderPredecessor(pRoot->pLeft, iDeletedItem); //Gets data from inorder predecessor
		pRoot->iData = iDeletedItem; //Replaces data with inorder predecessor data to preserve links to child nodes.
		FindDeletionPoint(pRoot->pLeft, iDeletedItem); //Deletes inorder predecessor node.
	}
}

//Helper function to BiTree::Remove()
void BiTree::GetInOrderPredecessor(TreeNode* pRoot, ItemType& iDeleteItem)
{
	while (pRoot->pRight != NULL)
		pRoot = pRoot->pRight;

	iDeleteItem = pRoot->iData;
}

bool BiTree::IsEmpty()
{
	return (pRoot == NULL);
}

bool BiTree::IsFull()
{
	try
	{
		TreeNode* pTest = new TreeNode;
		delete pTest;
		return false;
	} catch (std::bad_alloc exception) {
		return true;
	}
}

void BiTree::Print()
{
	InOrderTraversal(pRoot);
}

//Helper function to BiTree::Print()
void BiTree::InOrderTraversal(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		InOrderTraversal(pRoot->pLeft);
		std::cout << pRoot->iData.Get() << " ";
		InOrderTraversal(pRoot->pRight);
	}
}

void BiTree::TPrint()
{
	PrintGraph(pRoot, 0, 1);
}

/*	PrintGraph is a recursive function that takes two integer parameters along with a pointer to a tree object.
*	These two integers, nSpacingValue and nLevelValue, are used to space nodes in the binary tree in the console.
*	nSpacingValue counts how many tabs to output, and nLevelValue represents the level of the tree.
*	The recursive design of the function allows for nodes at the same level in the tree to have activation records that -
*	have the same nSpacingValue parameter, thereby giving the perception that those two nodes are in the same level in the -
*	console representation of the tree.*/

//Helper function to BiTree::TPrint()
void BiTree::PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue)
{
	//Base case and end of recursive calls to PrintGraph()
	if (pRoot == NULL)
		return;

	//Every level lower in the tree adds 1 to nSpacingValue which determines the number of tab characters to print
	//The number of tab characters is the same for items at the same level, and this achieved through the recursive -
	//structure of this function.
	nSpacingValue += nLevelValue;

	//Recursive call to travel to the bottom of the right subtree and work back up.
	PrintGraph(pRoot->pRight, nSpacingValue, nLevelValue);

	std::cout << std::endl;
	for (int i = nLevelValue; i < nSpacingValue; i++) //For loop prints out tab characters one less than nSpacingValue
		std::cout << '\t';
	std::cout << pRoot->iData.Get() << "\n";

	//Recursive call to travel to the bottom of the left subtree and work back up.
	PrintGraph(pRoot->pLeft, nSpacingValue, nLevelValue);
}

void BiTree::RPrint()
{
	ReverseInOrder(pRoot);
}

//Helper function to BiTree::RPrint()
void BiTree::ReverseInOrder(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		ReverseInOrder(pRoot->pRight);
		std::cout << pRoot->iData.Get() << " ";
		ReverseInOrder(pRoot->pLeft);
	}
}

BiTree::~BiTree()
{
	Destroy(pRoot);
}

//Helper function to BiTree::~BiTree()
void BiTree::Destroy(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		//A post order traversal is used because deleting leaf nodes is faster than rearranging nodes.
		Destroy(pRoot->pLeft);
		Destroy(pRoot->pRight);
		delete pRoot;
	}
}