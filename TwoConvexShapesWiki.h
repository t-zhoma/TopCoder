#pragma once
#include <vector>

using namespace std;

class TwoConvexShapesWiki
{
public:
	TwoConvexShapesWiki(void);
	~TwoConvexShapesWiki(void);

	int countWays(vector<string> grid);

private:
	vector<string> rotate(vector<string> grid);
	void print(const vector<string> grid);
	int count_0(const vector<string> grid, char c);
	int count_1(const vector<string> grid, char c);
	int count_2(const vector<string> grid, char c);
};

