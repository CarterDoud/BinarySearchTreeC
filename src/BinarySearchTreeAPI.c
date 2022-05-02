/**
 * @file BinarySearchTreeAPI.c
 * @brief File containing the function definitions for a binary search tree
 */
#include "BinarySearchTreeAPI.h"
#include <stdio.h>
#include <stdlib.h>
Tree * createBinTree(CompareFunc compare, DeleteFunc del, PrintFunc print)
{
	Tree* tmp; 
	tmp=( Tree *)malloc(sizeof(Tree));
	if(tmp!=NULL)
	{
		tmp->root = NULL;
		tmp->compareFunc = compare;
		tmp->deleteFunc = del;
		tmp->printFunc = print;
		return tmp;
	}
	else
	{
		return NULL;
	}
}
TreeNode* createTreeNode(TreeDataPtr data)
{
	TreeNode* tmp = malloc(sizeof (TreeNode));
	if(tmp!=NULL)
	{
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->data=data;
		return tmp;
	}
	else
	{
	return NULL;
	}
}

void addToTree(Tree * theTree, TreeDataPtr data)
{
	//insert recursively attempts to insert the data at the correct location
	theTree->root = insert(theTree->root,data,theTree->compareFunc);
}
TreeNode* insert(TreeNode* node, TreeDataPtr data, CompareFunc compare)
{
	//if location is empty, create new node
    if (node == NULL)
	{
		return createTreeNode(data);
	}
	//if value is less than starting node, take left branch
	if(compare(data,node->data)<0)
	{
        node->left = insert(node->left, data,compare);
	}
	//if value is greater than starting node, take right branch
	else if(compare(data,node->data)>0)
	{
        node->right = insert(node->right,data,compare);   
	}
    return node;
}
void printPreOrder(Tree * theTree, PrintFunc printData)
{
	preOrderPrint(theTree->root,printData);
}
void printPostOrder(Tree * theTree, PrintFunc printData)
{
	postOrderPrint(theTree->root,printData);
}
void printInOrder(Tree * theTree, PrintFunc printData)
{
	inOrderPrint(theTree->root,printData);
}
void inOrderPrint(TreeNode* node, PrintFunc printData)
{
	if (node != NULL)
    {
        inOrderPrint(node->left,printData);
        printData(node->data);
        inOrderPrint(node->right,printData);
    }
}
void postOrderPrint(TreeNode* node, PrintFunc printData)
{
	if (node != NULL)
    {
        postOrderPrint(node->left,printData);
		postOrderPrint(node->right,printData);
        printData(node->data);
        
    }
}
void preOrderPrint(TreeNode* node, PrintFunc printData)
{
	if (node != NULL)
    {
		printData(node->data);
        preOrderPrint(node->left,printData);
		preOrderPrint(node->right,printData);
        
    }
}

TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data )
{
	TreeNode* tmp = malloc(sizeof (TreeNode));
	tmp->data = search(theTree->root,data,theTree->compareFunc);
	
	if(tmp->data!=NULL)
	{
			
		return search(theTree->root,data,theTree->compareFunc)->data;
	}
	else
	{		
		return NULL;
	}
}
TreeNode* search(TreeNode* node, TreeDataPtr data, CompareFunc compare)
{
	//ensures node isn't empty
	while(node!=NULL && compare(data,node->data)!=0)
	{
	   
		if(compare(data,node->data)<0)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
   }
   return node;

}
void removeFromTree(Tree * theTree, TreeDataPtr data)
{
	deleteFromTree(theTree->root,data,theTree->compareFunc,theTree->deleteFunc);
}
TreeNode* deleteFromTree(TreeNode* node, TreeDataPtr data, CompareFunc compare, DeleteFunc del)
{	
    
	if (node==NULL) 
	{
		return node;
	}
	//if data is less than starting node, take left branch
    if (compare(data,node->data)<0)
        node->left = deleteFromTree(node->left,data,compare,del);
 
    // if data is greater than starting node, take right branch
    else if (compare(data,node->data)>0)
        node->right = deleteFromTree(node->right,data,compare,del);
 
    // if equal
    else
    {
        //cases with one or no children
        if (node->left == NULL)
        {
            TreeNode *tmp = node->right;
			del(node->data);
            free(node);
            return tmp;
        }
        else if (node->right == NULL)
        {
            TreeNode *tmp = node->left;
			del(node->data);
            free(node);
            return tmp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
		TreeNode* tmp2 = node->right;
		while (tmp2->left != NULL)
		{
			tmp2 = tmp2->left;
		}
		node->data=tmp2->data;
		//copy the new node's data
        // Copy the inorder successor's content to this node
        // Delete the inorder successor
        node->right = deleteFromTree(node->right,tmp2->data,compare,del);
    }
    return node;
}
int isLeaf( TreeNode * treeNode)
{
	if(treeNode->left==NULL&&treeNode->right==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int hasTwoChildren( TreeNode *treeNode)
{
	if(treeNode->left!=NULL&&treeNode->right!=NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int getHeight(TreeNode* treeNode)
{
	if (treeNode==NULL) 
        return 0;
    else
    {
        int leftHeight = getHeight(treeNode->left);
        int rightHeight = getHeight(treeNode->right);
 
        if (leftHeight > rightHeight)
		{			
           return(leftHeight+1);
		}
        else
		{
			return(rightHeight+1);
		}
    }
}
void  destroyBinTree(Tree * toDestroy)
{
	destroyNode(toDestroy->root,toDestroy->deleteFunc);
}
void destroyNode(TreeNode* treeNode, DeleteFunc del)
{
  if( treeNode != NULL)
  {
      destroyNode(treeNode->left,del);
      destroyNode(treeNode->right,del);
	  del(treeNode->data);
      free(treeNode);
  }
}
