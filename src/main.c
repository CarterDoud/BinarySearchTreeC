/**
 * @file main.c
 * @author Carter Doud
 * @date November 2017
 * @brief Assignment 4, chat bot/ personal assistant. Uses binary search trees to implement a chat bot
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTreeAPI.h"
#include "rule.h"
int main(int argc, char *argv[])
{
	FILE* fileIn = NULL;
	char keyTmp[255];
	char *word;
	char *phraseTmp;
	char dataString [255];
	double learnRateTmp;
	double userRateTmp;
	char helpful;
	int quit=0;
	int choice;
	if (argc != 2)
	{
		//exits program if incorrect number of command line args are entered
		exit(0);
	}
	fileIn = fopen(argv[argc-1], "r+");
	Tree* theTree = createBinTree(*compareRule,*deleteRule,*printRule);
	if (fileIn == NULL)
	{
		printf("File Empty\n");
		exit(0);
		//checks if file is empty        
	}
	while (fgets(dataString, 255, fileIn) != NULL)
	{
		sscanf(dataString,"%254s",keyTmp);
		fgets(dataString,255,fileIn);
		phraseTmp= strtok(dataString,"\n"); 
		//creates rule with default user rating and learning rate
		Rule *r = createRule(keyTmp,phraseTmp,0.05,0.5);
		addToTree(theTree,r);
	}

	while(quit==0)
	{
			Rule *r;
			printf("1.Insert a new Rule\n");
			printf("2.Remove a Rule\n");
			printf("3.Display Rules\n");
			printf("4.Modify Rule Rating\n");
			printf("5.Discuss\n");
			printf("9.Exit\n");
			printf("Enter your choice:");     
			scanf("%d",&choice);
			(void)getchar();
			switch(choice)
			{
				case 1:
					printf("Enter a keyword\n");
					scanf("%254s",keyTmp);
					printf("Enter a response\n");
					scanf("%254s",phraseTmp);
					printf("Enter a learning rate [0-1]\n");
					scanf("%lf",&learnRateTmp);
					printf("Enter a Rating of important [0-1]\n");
					scanf("%lf", &userRateTmp);
					r = createRule(keyTmp,phraseTmp,learnRateTmp,userRateTmp);
					addToTree(theTree,r);
					printInOrder(theTree,*printRule);
				break;
				case 2:
					printf("Enter a keyword\n");
					scanf("%254s",keyTmp);
					//creates temporary rule to find an equal rule in the tree
					r = createRule(keyTmp," ",0,0);
					if(findInTree(theTree,r)!=NULL)
					{
						removeFromTree(theTree,r);
					}
					else
					{
						printf("keyword not found\n");
					}
				break;
				case 3:
					printf("KeyWord\t  User Rating\tSystem Rating\tCount\n");
					printInOrder(theTree,*printRule);
				break;
				case 4:
					printf("Enter a keyword\n");
					scanf("%254s",keyTmp);
					//creates temporary rule
					r = createRule(keyTmp," ",0,0);
					//if the rule is in the tree
					if(findInTree(theTree,r)!=NULL)
					{
						//creates 2 temporary nodes
						//TreeNode* tmp = malloc(sizeof (TreeNode));
						TreeNode* node = malloc(sizeof (TreeNode));
						node=theTree->root;
						//iterates through tree until the node is found
						while(node!=NULL && theTree->compareFunc(r,node->data)!=0)
						{
						   
							if(theTree->compareFunc(r,node->data)<0)
							{
							 node = node->left;
							}
							else
							{
							 node = node->right;
							}

					   }
					   printf("Rule Found:\n");
					   printf("KeyWord\t  User Rating\tSystem Rating\tCount\n");
					   printRule(node->data);
					   printf("Enter a new rating\n");
					   scanf("%lf", &userRateTmp);
					   setUserRating(node->data,userRateTmp);

					}
					else
					{
						printf("Rule not found\n");
					}
				break;
				case 5:
					printf("Enter a question\n");
					fgets(dataString,255,stdin);
					int found = 0;
					char *pos;
					double totalRating = 0;
					//removes newline char
					if ((pos=strchr(dataString, '\n')) != NULL)
					{
						*pos = '\0';
					}
					word = strtok(dataString," ");					
					//printf("%s\n",word);
					r = createRule(word," ",0,0);
					TreeNode* node = malloc(sizeof (TreeNode));
					Rule* tmpRule2 = malloc(sizeof (Rule));
					//breaks string into 
					while(word!=NULL)
					{
						Rule* tmpRule = findInTree(theTree,r);
						if(tmpRule!=NULL)
						{
							found = 1;
							if(getSysRating(tmpRule)+getUserRating(tmpRule)>totalRating)
							{
								totalRating =getSysRating(tmpRule)+getUserRating(tmpRule);
								tmpRule2 = tmpRule;
							}
							//printf("%lf\n",getSysRating(tmpRule));
						}
						word=strtok(NULL," ");
					}

					
					if(found==0)
					{
						printf("no matches found\n");
					}
					else
					{
						printf("%s\n",getResponse(tmpRule2));
						printf("Was this response helpful? (Y/N)\n");
						helpful=getchar();
						node=theTree->root;
						while(node!=NULL && theTree->compareFunc(r,node->data)!=0)
						{
						   
							if(theTree->compareFunc(r,node->data)<0)
							{
								node = node->left;
							}
							else
							{
								 node = node->right;
							}
						}
						indexCount(node->data);
						if (helpful== 'y'|| helpful== 'Y')
						{
							
							setSystemRating(node->data,getSysRating(tmpRule2)+getSysRating(tmpRule2)*getLearningRate(tmpRule2)/getCount(tmpRule2));
						}
						else if (helpful== 'n'|| helpful=='N')
						{
							setSystemRating(node->data,getSysRating(tmpRule2)-getSysRating(tmpRule2)*getLearningRate(tmpRule2)/getCount(tmpRule2));
						}
						
						
					}
				break;
				case 9:
					exit(0);
				break;
			}
	}
	return 0;
}