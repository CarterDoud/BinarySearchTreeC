/**
 * @file rule.c
 * @author Carter Doud
 * @date November 2017
 * @brief File containing the functions for a rule
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rule.h"
Rule* createRule(char* keyWord, char* response, double learningRate, double userRating)
{
	Rule* tmp;
	tmp=( Rule *)malloc(sizeof( Rule));
	tmp->keyWord=strdup(keyWord);
	tmp->userRating=userRating;
	tmp->sysRating=userRating;
	tmp->learningRate=learningRate;
	tmp->response=strdup(response);
	tmp->count = 0;
	return tmp;
}
char *strdup (const char *s) 
{
    char *d = malloc (strlen (s) + 1);   
    if (d == NULL) return NULL;          
    strcpy (d,s);                        
    return d;
}
const char* getKeyWord(Rule* r)
{
	return r->keyWord;
}
const char* getResponse(Rule* r)
{
	return r->response;
}
double getSysRating(Rule* r)
{
	return r->sysRating;
}
double getUserRating(Rule *r)
{
	return r->userRating;
}
void printRule(void* r)
{
	if(r!=NULL)
	{
		printf("%s       %f         %f        %d\n",getKeyWord(r),getUserRating(r),getSysRating(r),getCount(r));
	}
}
void printRule2(void* r)
{
	if(r!=NULL)
	{
		printf("%s\n",getKeyWord(r));
	}
}
int compareRule(const void* a, const void* b)
{
	//printf("%d %s %s\n",strcmp(getKeyWord(((Rule*)a)),getKeyWord((Rule*)b)) ,getKeyWord((Rule*)a), getKeyWord((Rule*)b));
	
	return strcmp(getKeyWord(((Rule*)a)),getKeyWord((Rule*)b));
}
void deleteRule(void* data)
{
	free(data);
}
void setUserRating(Rule* r,double rating)
{
	r->userRating = rating;
}
void setSystemRating(Rule*r,double rating)
{
	r->sysRating=rating;
}
int getCount(Rule *r)
{
	return r->count;
}
void indexCount(Rule *r)
{
	r->count++;
}
double getLearningRate(Rule *r)
{
	return r->learningRate;
}
