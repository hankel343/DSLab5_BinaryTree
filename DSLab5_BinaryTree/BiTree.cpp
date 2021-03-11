#include "BiTree.h"
/*Helper function prototypes*/
//Helper functions for BiTree::Add():
void Insert(TreeNode*& pRoot, ItemType iNewItem);
void CreateNode(TreeNode*& pRoot, ItemType iNewItem);
//Helper functions for BiTree::Remove():
void FindDeletionPoint(TreeNode*& pRoot, ItemType iDeletedItem);
void Delete(TreeNode*& pRoot, ItemType iDeletedItem);
void GetInOrderPredecessor(TreeNode* pRoot, ItemType& iDeletedItem);
//Helper function for BiTree::Print():
void InOrderTraversal(TreeNode* pRoot);
//Helper function for BiTree::TPrint():
void PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue);
//Helper function for BiTree::RPrint():
void ReverseInOrder(TreeNode* pRoot);
//Helper function for BiTree::~BiTree():
void Destroy(TreeNode* pRoot);

BiTree::BiTree()
{
	pRoot = NULL;
}

void BiTree::Add(ItemType iNewItem)
{
	Insert(pRoot, iNewItem);
}

//Helper function to BiTree::Add()
void Insert(TreeNode*& pRoot, ItemType iNewItem)
{
	if (pRoot == NULL)
		CreateNode(pRoot, iNewItem);
	else if (iNewItem.ComparedTo(pRoot->iData) == LESS)
		Insert(pRoot->pLeft, iNewItem);
	else if (iNewItem.ComparedTo(pRoot->iData) == GREATER)
		Insert(pRoot->pRight, iNewItem);
}

//Helper function to BiTree::Add()
void CreateNode(TreeNode*& pRoot, ItemType iNewItem)
{
	pRoot = new TreeNode;
	pRoot->iData = iNewItem;
	pRoot->pLeft = pRoot->pRight = NULL;
}

void BiTree::Remove(ItemType iDeletedItem)
{
	FindDeletionPoint(pRoot, iDeletedItem);
}

//Helper function to BiTree::Remove()
void FindDeletionPoint(TreeNode*& pRoot, ItemType iDeletedItem)
{
	if (iDeletedItem.ComparedTo(pRoot->iData) == EQUAL)
		Delete(pRoot, iDeletedItem);
	else if (iDeletedItem.ComparedTo(pRoot->iData) == LESS)
		Delete(pRoot->pLeft, iDeletedItem);
	else if (iDeletedItem.ComparedTo(pRoot->iData) == GREATER)
		Delete(pRoot->pRight, iDeletedItem);
}

//Helper function to BiTree::Remove()
void Delete(TreeNode*& pRoot, ItemType iDeletedItem)
{
	TreeNode* pTemp = pRoot;

	if (pRoot->pLeft == NULL)
	{
		pRoot = pRoot->pRight; //Link made to right subtree.
		delete pTemp;
	} else if (pRoot->pRight == NULL) {
		pRoot = pRoot->pLeft; //Link made to left subtree.
		delete pTemp;
	} else {
		GetInOrderPredecessor(pRoot->pLeft, iDeletedItem); //Gets data from inorder predecessor
		pRoot->iData = iDeletedItem; //Replaces data with inorder predecessor data to preserve links to child nodes.
		FindDeletionPoint(pRoot->pLeft, iDeletedItem); //Deletes inorder predecessor node.
	}
}

//Helper function to BiTree::Remove()
void GetInOrderPredecessor(TreeNode* pRoot, ItemType& iDeleteItem)
{
	while (pRoot->pRight != NULL)
		pRoot = pRoot->pRight;

	iDeleteItem = pRoot->iData;
}

void BiTree::Print()
{
	InOrderTraversal(pRoot);
}

//Helper function to BiTree::Print()
void InOrderTraversal(TreeNode* pRoot)
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

//Helper function to BiTree::TPrint()
void PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue)
{
	//Base case and end of recursive calls to PrintGraph
	if (pRoot == NULL)
		return;

	//Every level lower in the tree adds 1 to nSpacingValue which determines the number of tab characters to print
	//The number of tab characters is the same for items at the same level, and this achieved through the recursive -
	//structure of this function.
	nSpacingValue += nLevelValue;

	//Recursive call to travel to the root of the right subtree.
	PrintGraph(pRoot->pRight, nSpacingValue, nLevelValue);

	std::cout << std::endl;
	for (int i = nLevelValue; i < nSpacingValue; i++)
		std::cout << '\t';
	std::cout << pRoot->iData.Get() << "\n";

	//Recursive call to travel to the root of the left subtree.
	PrintGraph(pRoot->pLeft, nSpacingValue, nLevelValue);
}

void BiTree::RPrint()
{
	ReverseInOrder(pRoot);
}

//Helper function to BiTree::RPrint()
void ReverseInOrder(TreeNode* pRoot)
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
void Destroy(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		//A post order traversal is used because deleting leaf nodes is faster than rearranging nodes.
		Destroy(pRoot->pLeft);
		Destroy(pRoot->pRight);
		delete pRoot;
	}
}