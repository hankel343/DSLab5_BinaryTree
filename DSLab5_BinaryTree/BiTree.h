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

public:
	BiTree();
	~BiTree();
	void Add(ItemType iNewItem);
	void Remove(ItemType iDeletedItem);
	void Print();
	void TPrint();
	void RPrint();
};

#endif BITREE_H