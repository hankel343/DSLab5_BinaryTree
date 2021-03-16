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
	//Pre: A tree and ItemType object have been initialized.
	//Post: The ItemType object is added as a node to the tree object.

	void CreateNode(TreeNode*& pRoot, ItemType iNewItem);
	//Pre: A tree and ItemType object have been initialized.
	//Post: Memory has been allocated for a new ItemType object and linked to its parent node in the tree.

	/*Helper methods for BiTree::Remove()*/
	void FindDeletionPoint(TreeNode*& pRoot, ItemType iDeletedItem);
	//Pre: A tree and ItemType object exist and have been initialized.
	//Post: The function will either have found a matching node and called Delete() or return having done nothing -
	//	if the searched for node is not found.

	void Delete(TreeNode*& pRoot, ItemType iDeletedItem);
	//Pre: A tree and ItemType object have been initialized.
	//Post: Memory has been deallocated for the node with the searched for ItemType data.

	void GetInOrderPredecessor(TreeNode* pRoot, ItemType& iDeletedItem);
	//Pre: A tree and ItemType object have been initialized.
	//Post: The data value of the inorder predecessor of a given node is stored in iDeletedItem.

	/*Helper methods for BiTree::Print()*/
	void InOrderTraversal(TreeNode* pRoot);
	//Pre: A tree object has been initialized.
	//Post: An inorder traversal of the tree is performed and data values are output. This is also sorted order.

	/*Helper methods for BiTree::TPrint()*/
	void PrintGraph(TreeNode* pRoot, int nSpacingValue, int nLevelValue);
	//Pre: A tree object has been initialized.
	//Post: A horizontal graphical representation of the binary tree is printed to the console.

	/*Helper methods for BiTree::RPrint()*/
	void ReverseInOrder(TreeNode* pRoot);
	//Pre: A tree object has been initialized.
	//Post: A postorder traversal of the binary tree is performed and data values of nodes are output to the console.
	//		This gives the reverse of the sorted order.

	/*Helper methods for BiTree::~BiTree()*/
	void Destroy(TreeNode* pRoot);
	//Pre:	A tree object has been initialized.
	//Post:	Memory for all nodes in the tree has been deallocated.

public:
	BiTree();
	//Pre: none
	//Post: The pRoot attribute has been set to NULL.

	~BiTree();
	//Pre: none. 
	//Post: Memory for all nodes in the tree has been deallocated.

	void Add(ItemType iNewItem);
	//Pre: An ItemType object has been initialized.
	//Post: A new ItemType object is inserted into the tree.

	void Remove(ItemType iDeletedItem);
	//Pre: An ItemType object has been initialized.
	//Post: The node with the matching ItemType data has been removed from the tree.

	bool IsEmpty();
	//Pre: none.
	//Post: A boolean value is returned based on whether the pRoot node contains NULL.

	bool IsFull();
	//Pre: None.
	//Post: A boolean value is returned based on whether a new node can be allocated or not.
	//***Can throw exceptions, but will catch its own exceptions within the function definition.***

	void Print();
	//Pre: None.
	//Post: The contents of the binary tree are printed in sorted order.

	void TPrint();
	//Pre: None.
	//Post: A graphical representation of the binary tree is output to the console.

	void RPrint();
	//Pre: None.
	//Post: The contents of the binary tree are printed in reverse order.
};

#endif BITREE_H