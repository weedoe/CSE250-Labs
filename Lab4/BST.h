/****************************************************************************\
 * BST.h
 *
 *  Created on: Mar 7 2024
 *      Author: OCdt Paterson
 *
 *
 *  Implementation details: see BST.cpp
 *
\***************************************************************************/

#ifndef BST_H_
#define BST_H_

/** Binary Search Tree node */
struct BSTNode {
	/** Pointer to the parent node. */
	BSTNode* parent;
	/** Pointer to the left child node. */
	BSTNode* left;
	/** Reference to the right child node. */
	BSTNode* right;
	/** Key used to search an element. */
	int key;
	/** Data associated to the element. */
	const char* data;

};


/** Binary Search Tree
 * In a Binary search tree:
 * 		Every node y in the left subtree of x  must have y.key < x.key
 *  	Every node y in the right subtree of x  must have y.key > x.key
 *  	The root node has root.parent = null
 *  	Here no keys can be duplicated
 */
class BST {
	private:
		/** Pointer to the root node of the tree, or NULL if empty */
		BSTNode* m_root;
		/** Minimum: Finds and returns the node with the smallest key */
		BSTNode* _min(BSTNode* x);
		/** Successor: Returns the node following node x in key order in the whole tree */
		BSTNode* _successor(BSTNode* x);

		/** Computes and returns the height of the node x. */
		int _height(BSTNode* x);
	public:
		/** Construct an empty binary search tree. */
		BST();
		/** Destroy and free up the memory allocated by the binary search tree. */
		virtual ~BST();
		/** Prints all the data from the tree in key order (using _min and _successor). */
		void printTree();

		/** Finds a node with (key) from the tree and returns the associated (data) or NULL if not found. */
        BSTNode * search(int key);
		/** Inserts a new node in the tree with given (key, data). */
		void insert(int key, const char* data);
		/** Deletes a the node with (key) from the tree and returns the associated (data) or NULL if not found. */
		const char* remove(int key);
		/** Computes and returns the height of the tree. */
		int height();

		/** Prints the keys (comma separated) of the tree using an preorder traversal. */
		void preOrder();
		/** Prints the keys (comma separated) of the tree using an inorder traversal. */
		void inOrder();
		/** Prints the keys (comma separated) of the tree using an postorder traversal. */
		void postOrder();
        /** Transplants the subtree rooted at node v to replace the subtree rooted at node u. */
        void transplant(BSTNode* u, BSTNode* v);

};

#endif /* BST_H_ */
