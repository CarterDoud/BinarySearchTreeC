# BinarySearchTreeC
A Binary search tree API and sample chat bot

## Description
This assignment implements a personal assistant using a binary search tree. The program reads a data file with rules containing keywords and responses.
The program can add/remove and modify rules.
The program will respond to questions based upon the level of significance of words in the question.

## Running the Program
To compile the program, navigate to the main directory for the assignment and use the command "make"
To run the program, use the command "./bin/program <INPUT FILE>" where <INPUT FILE> is a properly formatted text document
A sample file has been included in the assests directory
To compile the test program, navigate to the main directory for the assignment and use the command "make test"
To run the test program, use the command "./bin/testing"

## Testing
testmain.c runs several manually generated test cases to test the binary search tree functions with normal input
  
## Limitations
If the hash function generates two identical keys, the latter will not appear in certian hash table functions. The menu can act unusual if the input is not
a single integer on the menu. (Original specification of this project stated correct input would be given and error checking was not neccesary to include)
  

## Hash function and Collisions
The hash function is based upon a common string hash function. Each letter's ascii value is added in a sum to generate a key.
To help generate more unique keys, each letter's ascii value is multiplied by it's index in the word. The Index location in the hash table
is determined using hashing division.

Collisions are solved using a singly linked list structure inside the list node. Collisions are added to the next node. When nodes are removed
The links are reconnected to preserve the list.
