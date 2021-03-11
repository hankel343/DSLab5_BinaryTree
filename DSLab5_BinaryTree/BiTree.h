#ifndef BITREE_H
#define BITREE_H
#include "ItemType.h"
#include <cstdlib>
#include <iostream>

struct TreeNode
{
	ItemType iData;
	TreeNode* pLeft;
	TreeNode* pRight;
};

class BiTree
{
private:
	TreeNode* pRoot;
	/*Helper methods for BiTree::Add()*/
	void Insert(TreeNode*& pRoot, ItemType iNewItem);
	void CreateNode(TreeNode*& pRoot, ItemType iNewItem);
	/*Helper methods for BiTree::Remove()*/
	void FindDeletionPoint(TreeNode*& pRoot, ItemType iDeletedItem);
	void Delete(TreeNode*& pRoot, ItemType iDeletedItem);
	void GetInOrderPredecessor(TreeNode* pRoot, ItemType& iDeletedItem);
	/*Helper methods for BiTree::Print()*/
	void InOrderTraversal(TreeNode* pRoot);
	/*Helper methods for BiTree::TPrint()*/
	void PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue);
	/*Helper methods for BiTree::RPrint()*/
	void ReverseInOrder(TreeNode* pRoot);
	/*Helper methods for BiTree::~BiTree()*/
	void Destroy(TreeNode* pRoot);

public:
	BiTree();
	~BiTree();
	void Add(ItemType iNewItem);
	void Remove(ItemType iDeletedItem);
	bool IsEmpty();
	bool IsFull();
	void Print();
	void TPrint();
	void RPrint();
};

#endif BITREE_H