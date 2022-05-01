/**
 * @file testmain.c
 * @author Carter Doud
 * @date November 2017
 * @brief testing binary tree search tree functions
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTreeAPI.h"
#include "rule.h"

int main()
{
	Tree* theTree = createBinTree(*compareRule,*deleteRule,*printRule2);
	char* keys[5] = {"5","3","6","4","2"};
	Rule *r1;
	Rule *r2;
	Rule *r3;
	Rule *r4;
	Rule *r5;
	Rule *r6;
	r1 = createRule(keys[0]," ",0.05,0.05);
	r2 = createRule(keys[1]," ",0.05,0.05);
	r3 = createRule(keys[2]," ",0.05,0.05);
	r4 = createRule(keys[3]," ",0.05,0.05);
	r5 = createRule(keys[4]," ",0.05,0.05);
	r6 = createRule(keys[2]," ",0.05,0.05);
	//r7 = createRule(keys[6]," ",0.05,0.05);
	//r8 = createRule(keys[7]," ",0.05,0.05);
	//r9 = createRule(keys[8]," ",0.05,0.05);
	addToTree(theTree,r1);
	addToTree(theTree,r2);
	addToTree(theTree,r3);
	addToTree(theTree,r4);
	addToTree(theTree,r5);
	//addToTree(theTree,r6);
	//addToTree(theTree,r7);
	//addToTree(theTree,r8);
	//addToTree(theTree,r9);
	printf("Testing values(added in order they appear):\n");
	printRule2(r1);
	printRule2(r2);
	printRule2(r3);
	printRule2(r4);
	printRule2(r5);
	//printRule2(r6);
	//printRule2(r7);
	//printRule2(r8);
	//printRule2(r9);
	printf("Testing CreateTree and addToTree and printInOrder\n");
	//printPreOrder(theTree,*printRule2);
	//printPostOrder(theTree,*printRule2);
	printInOrder(theTree,*printRule2);
	printf("Expected output:\n");
	printRule2(r5);
	printRule2(r2);
	printRule2(r4);
	printRule2(r1);
	printRule2(r3);
	printf("Testing printPostOrder\n");
	printPostOrder(theTree,*printRule2);
	printf("Expected output:\n");
	printRule2(r5);
	printRule2(r4);
	printRule2(r2);
	printRule2(r3);
	printRule2(r1);
	printf("Testing printPreOrder\n");
	printPreOrder(theTree,*printRule2);
	printf("Expected output:\n");
	printRule2(r1);
	printRule2(r2);
	printRule2(r5);
	printRule2(r4);
	printRule2(r3);
	printf("Testing remove from tree, removing node: ");
	printRule2(r5);
	removeFromTree(theTree,r5);
	printInOrder(theTree,*printRule2);
	printf("Expected output:\n");
	printRule2(r2);
	printRule2(r4);
	printRule2(r1);
	printRule2(r3);
	printf("Testing findInTree, looking for value: ");
	printRule2(r3);
	printf("result: ");
	printRule2(findInTree(theTree,r6));
	printf("Testing isLeaf on value: ");
	printRule2(r4);
	if(isLeaf(theTree->root->left->right)==1)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	printf("Expected output: True\n");
	printf("Testing hasTwoChildren on value ");
	printRule2(r4);
	if(hasTwoChildren(theTree->root->left->right)==1)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	printf("Expected output: False\n");
	printf("Testing get height, testing on root\n");
	printf("%d\n",getHeight(theTree->root));
	printf("expected output: 3\n");
	printf("Testing destroy tree\n");
	destroyBinTree(theTree);
	printf("Expected output: none\n");
}