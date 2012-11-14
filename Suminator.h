/*Problem Statement
Suminator is a very limited programming language. A program in this language is simply a sequence of nonnegative integers. 
The program is evaluated using a stack of nonnegative integers. Initially, the stack is empty. Trying to pop an element from 
an empty stack returns a zero. (Alternately, you can imagine that the stack already contains a sufficient number of zeros in 
the beginning.)

A Suminator program is evaluated using the following algorithm:

for i = 0 to length(program) - 1 {
    if ( program[i] is 0) {
         Pop the top two elements from the stack, add them together
         and push the result to the top of the stack.
    } else {
         Push program[i] to the top of the stack.
    }
}
Pop the top element of the stack and print it.

For example, when executing the program {1}, we first push the 1 to the stack, and then we print it. When executing the program {5,0,1,2,0}, we take the following steps:

    We push the 5 to the top of the stack.
    We pop the top two elements (5 and 0), add them together and push the result (5).
    We push the 1 to the top of the stack.
    We push the 2 to the top of the stack. At this moment, the stack contains the values 5, 1, and 2 (from bottom to top).
    We pop the top two elements (2 and 1), add them together and push the result (3).
    We print the top element of the stack: the number 3. Note that the stack also contains the value 5, which is ignored.

You are given a int[] program containing a Suminator program (a sequence of nonnegative integers), in which one of the elements of the sequence was changed to -1. You are also given a int wantedResult. Your task is to change the -1 back to a nonnegative integer X in such a way that the resulting program prints the number wantedResult. Return X. If there are multiple possible values of X, return the smallest one. If there is no way to make the program print wantedResult, return -1 instead.
 
Definition
    	
Class:	Suminator
Method:	findMissing
Parameters:	int[], int
Returns:	int
Method signature:	int findMissing(int[] program, int wantedResult)
(be sure your method is public)
    
Notes
-	The return value always fits into an int. This follows from the constraints and the nature of the problem.
 
Constraints
-	program will contain between 1 and 50 elements, inclusive.
-	Each element of program will be between -1 and 1000000000 (10^9), inclusive.
-	program will contain -1 exactly once.
-	wantedResult will be between 1 and 1000000000 (10^9), inclusive.
 
Examples
0)	
	{7,-1,0}
	10
	
	Returns: 3

1)	
    {100, 200, 300, 0, 100, -1}
	600

	Returns: 0

2)	
    {-1, 7, 3, 0, 1, 2, 0, 0}
	13

	Returns: 0

	We can replace the first element with many other values, but 0 is the smallest that achieves the wanted result.

3)	
    {-1, 8, 4, 0, 1, 2, 0, 0}
	16

	Returns: -1

	It does not matter what value we use in the first element of the array, the result will always be 15.

4)	
    {1000000000, 1000000000, 1000000000,  1000000000, -1, 0, 0, 0, 0}
	1000000000

	Returns: -1

	It does not matter what we replace the -1 with, the result will be larger than 1000000000.

5)	
    {7, -1, 3, 0}
	3

	Returns: -1
	
My Idea
	If 0 satisfy the condition, then return 0;
	Else let A be the variable of -1, check the result to get the answer

Petr's Idea
	Silimar to mine, but replace -1 with 1 and 2 to prevent from using variable

K.A.D.R's Idea
	Set L = 1 and R = INF + 1, then use binary search to find result
*/


#pragma once

#include <vector>

using namespace std;

class Suminator
{
public:
	Suminator(void);
	~Suminator(void);

public:
	int findMissing(vector<int> program, int wantedResult);
};

