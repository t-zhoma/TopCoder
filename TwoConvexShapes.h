/*Problem Statement
A platypus has been given the mission to paint the cells on a grid either black or white according to the following two conditions:

1. For each color, all cells of that color must be connected. Formally, a pair of cells of color X is connected if there is a path of 
   adjacent cells of color X between them. (Two cells are adjacent if they share a common edge.) We require that for each color, each pair 
   of cells of that color must be connected.
    
2. All the cells of each color must form a convex shape. A group of cells of a given color is convex if in each row and each column the 
   cells of that color form a connected segment (possibly taking the whole row or column). In other words, whenever two cells of the same 
   color share the same row or the same column, all cells between them must also have that particular color.

The platypus is also allowed to paint the grid completely white or black.

The platypus may have already painted some of the cells. The current state of the grid is given as a String[] grid. The i-th character of 
the j-th element of grid that represents the cell at row j, column i is 'W' if it has been painted white, 'B' if it has been painted black, 
and '?' if it does not have a color yet. Let X be the number of different ways how to color the rest of the grid according to the above 
conditions. Return the value X modulo 1000000007 (10^9 + 7). Two ways to color a grid are different if the color of at least one cell differs.
 
Definition
    	
Class:	TwoConvexShapes
Method:	countWays
Parameters:	String[]
Returns:	int
Method signature:	int countWays(String[] grid)
(be sure your method is public)
     
Constraints
-	grid will contain between 1 and 50 elements, inclusive.
-	Element 0 of grid will contain between 1 and 50 characters, inclusive.
-	The remaining elements of grid will contain the same number of characters as element 0.
-	Each character in each element of grid will be one of 'B', 'W', and '?' (quotes for clarity).
 
Examples

0)	
{"??",
 "??"}

Returns: 14

Of all the 16 different ways to color the grid, only the following 2 are not valid.

BW WB
WB BW

This is because cells of the same color are not connected.

1)	
{"B?",
 "??"}

Returns: 7

The following seven ways to color the grid are correct:

BB BW BB BW BB BB BW
BB BW WW WW WB BW BB

2)	
{"WWB",
 "WWW",
 "WWW",
 "WWW"}

Returns: 1

All colors have already been picked. The only possible coloring is already valid.

3)	
{"BBBBBB",
 "WWBBBB",
 "WBBBBB"}

Returns: 0

This coloring of the grid is not valid, the black cells do not form a convex shape.

4)	
{"?BB?",
 "BBBB",
 "?BB?"}

Returns: 5

5)	
{"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}

Returns: 73741817

Each of the 2^30 ways to color the remaining cells in the grid is valid.

My idea
Travel all value and use DFS to verify whether connect, It will overtime when data is large

Wiki's idea
Dynamic programming, classify the pattern depends on the number of corner of grid painted black
*/

#pragma once

#include <vector>

using namespace std;

class Pos
{
public:
	Pos(size_t i, size_t j) 
	{
		this->i = i;
		this->j = j;
	}

	size_t i;
	size_t j;
};

class TwoConvexShapes
{
public:
	TwoConvexShapes(void);
	~TwoConvexShapes(void);

	int countWays(vector<string> grid);

private:
	bool IsSatisfy();
	bool GetFirstPos(const vector<string>& vt, char ch, Pos &p);
	bool GetNextPos(const vector<string>& vt, char ch, Pos prev, Pos &p);
	bool GetPrevPos(const vector<string>& vt, char ch, Pos next, Pos &p);
	char GetNextChar(char ch);
	bool IsValidValue(Pos p);
	bool IsRowValid(size_t r);
	bool IsColValid(size_t c);
	bool IsConnect();
	bool IsConnect(char ch);
	bool IsSameValueAround(Pos p);
	int Count(char ch);
	void DFS(vector<string>& grid, char ch, Pos p);

private:
	vector<string> m_tempGrid;
	vector<string> m_grid;
};

