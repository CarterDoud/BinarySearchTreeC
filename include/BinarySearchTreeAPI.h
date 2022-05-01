#ifndef BST_GUARD
#define BST_GUARD

/**************************************
Interface for a Binary Tree ADT
Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
Modified: Carter Doud (Nov 2017)
**************************************/

/**
 * Function pointer tyepdefs
 */
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

/*
 * Typedef the void* to make the API cleaner and more readable.
 */
typedef void* TreeDataPtr;

/*
 * A Single Binary Tree Node.
 * Left and Right branches
 * void* data
 */
typedef struct binTreeNode TreeNode;
struct binTreeNode{
	TreeDataPtr data;
	TreeNode * left;
	TreeNode * right;
	//TreeNode * parent; //Optional but useful
    //Tree* parentTree;  //Optional but gets you access to function pointers.
};

/**
 * This is the definition of the Binary Tree.
 *
 */
typedef struct binTree
{
	TreeNode *root;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;
	PrintFunc printFunc;
	// Additions must work with abstract data types.
	// Additional function pointers to generalize tree.
	// Additional properties can be added such as count.
}Tree;

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data);

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del,PrintFunc print);

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy);

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data);

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data);


/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data );

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree);

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData);

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTee);


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode);

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode);

/**
 * Helper funciton Get the height of a particular Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode );


/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */
 
/**
 * Helper funciton Recursively used by addToTree to insert data
 * @param  treeNode starting node for function
 * @param  data the data to be stored at the node
 * @param  compare compare function for data type being stored
 * @return 	new node or next node until correct location is found
 */
TreeNode* insert(TreeNode* node, TreeDataPtr data, CompareFunc compare);

/**
 * Helper funciton Recursively used by printInOrder
 * @param  treeNode starting node for function
 * @param  printData print function for data type in tree
 * @post   tree is printed in order
 */
void inOrderPrint(TreeNode* node, PrintFunc printData);

/**
 * Helper funciton Recursively used by printPostOrder
 * @param  treeNode starting node for function
 * @param  printData print function for data type in tree
 * @post   tree is printed in post order
 */
void postOrderPrint(TreeNode* node, PrintFunc printData);

/**
 * Helper funciton Recursively used by printPreOrder
 * @param  treeNode starting node for function
 * @param  printData print function for data type in tree
 * @post   tree is printed in preOrder
 */
void preOrderPrint(TreeNode* node, PrintFunc printData);

/**
 * Helper funciton Recursively used by findInTree
 * @param  treeNode starting node for function
 * @param  data the data to be stored at the node
 * @param  compare compare function for data type in tree
 * @return desired node or next node in search
 */
TreeNode* search(TreeNode* node, TreeDataPtr data, CompareFunc compare);

/**
 * Helper funciton Recursively used by removeFromTree
 * @param  treeNode starting node for function
 * @param  data the data to be stored at the node
 * @param  compare compare function for data type in tree
 * @param  del delete function for data type in tree
 * @return desired node or next node
 */
TreeNode* deleteFromTree(TreeNode* node, TreeDataPtr data, CompareFunc compare, DeleteFunc del);

/**
 * Helper funciton Recursively used by destroyTree, removes nodes with no attempt at sorting
 * @param  treeNode starting node for function
 * @param  del delete function for data type in tree
 * @post tree is destroyed
 */
void destroyNode(TreeNode* treeNode, DeleteFunc del);
#endif