/**
 * @file rule.h
 * @author Carter Doud
 * @date November 2017
 * @brief File containing the function declarations and structure for rules
 */
#ifndef RULE_H
#define RULE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* rule structure
**/
typedef struct rule{
	char *keyWord;
	char *response;
	double sysRating;
	double userRating;
	double learningRate;
	int count;
}Rule; 


/**Function to duplicate a string
*@return a copy of a string
*@param s string to duplicate
**/
char *strdup (const char *s);

/**Function to create a Rule. Allocates memory to the struct
*@return pointer to a rule
*@param keyWord string of characters for the rule
*@param response for the rule
*@param sysRating double storing importance of rule
*@param learning double storing the rate of learning
**/
Rule* createRule(char* keyWord, char* response, double learningRate, double userRating);

/**Function to print the value of a rule
*@param r rule to print
*@post prints the value of the rule to stdout
**/
void printRule(void* r);

/**Function to print the value of a rule
*@param a first rule
*@param b second rule
*@return 0 if equal, if b<a return negative, if a<b return positive
**/
int compareRule(const void* a, const void* b);

/**Function to return the keyword of a rule
*@param rule to get keyword from
*@return keyword of r
**/
const char* getKeyWord(Rule* r);

/**Function to delete a rule
*@param data to delete
*@post frees the memory of data
**/
void deleteRule(void* data);

/**Function to change a user Rating
*@param r rule to change
*@param rating new user rating
*@post changes user rating
**/
void setUserRating(Rule* r,double rating);

/**Function to return user rating
*@param r rule to return user rating from
*@param rating new user rating
*@return user rating of r
**/
double getUserRating(Rule *r);

/**Function to return count of a rule
*@param r rule to return count of
*@return count of r
**/
int getCount(Rule *r);

/**Function to index count of a rule
*@param r rule to increase count of
*@post r->count increases by1
**/
void indexCount(Rule *r);

/**Function to return system rating
*@param r rule to return value of
*@return system rating of r
**/
double getSysRating(Rule* r);

/**Function to return response of a rule
*@param r rule to return value of
*@return resposne of r
**/
const char* getResponse(Rule* r);

/**Function to change a system Rating
*@param r rule to change
*@param rating new system rating
*@post changes system rating
**/
void setSystemRating(Rule*r,double rating);

/**Function to return learning rate of a rule
*@param r rule to return value of
*@return learning rate of r
**/
double getLearningRate(Rule *r);

/**Function to print the value of a rule. Only prints keyword
*@param r rule to print
*@post prints the value of the rule to stdout
**/
void printRule2(void* r);
#endif