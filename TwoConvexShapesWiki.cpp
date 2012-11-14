#include "TwoConvexShapesWiki.h"
#include "Macros.h"
#include <iostream>

TwoConvexShapesWiki::TwoConvexShapesWiki(void)
{
}


TwoConvexShapesWiki::~TwoConvexShapesWiki(void)
{
}

int TwoConvexShapesWiki::countWays(vector<string> grid)
{
	int res = count_0(grid, 'B') + count_0(grid, 'W');

	FOR(i,1,4)
	{
		res += count_1(grid, 'B') + count_1(grid, 'W');
		grid = rotate(grid);
	}

	FOR(i,1,4)
	{
		res += count_2(grid, 'B');
	}
	
	return res;
}

int TwoConvexShapesWiki::count_0(const vector<string> grid, char c)
{
	int m = grid.size();
	int n = grid[0].size();

	FOR(i,0,m-1)
	FOR(j,0,n-1)
	{
		if(grid[i][j] != c && grid[i][j] != '?')
			return 0;
	}

	return 1;
}

int TwoConvexShapesWiki::count_1(const vector<string> grid, char c)
{
	int m = grid.size();
	int n = grid[0].size();
	int f[55][55], low[55], high[55];
	
	SET(low, 0);
	FOR(i, 0, m-1)
	FOR(j, 0, n-1)
	{
		if(grid[i][j] == c)
			low[i] = j;
	}

	FOR(i, 0, m-1)
	{
		high[i] = n;
		FORD(j, n-1, 0)
		{
			if(grid[i][j] != c && grid[i][j] != '?')
				high[i] = j;
		}
	}

	FOR(i, 0, m-1)
	FOR(j, 0, high[i]-1)
	{
		if(grid[i][j] != c && grid[i][j] != '?')
			return 0;
	}

	// Init f
	SET(f, 0);
	FOR(j, max(1,low[0]), n-1)
		f[0][j] = j < high[0];

	// Dynamic program
	FOR(i, 1, m-1)
	FOR(j, low[i], high[i]-1)
	{
		f[i][j] = 0;
		FOR(k, j, n-1)
		{
			f[i][j] = (f[i][j] + f[i-1][k]) % mod;
		}
	}

	return f[m-1][0];
}

int TwoConvexShapesWiki::count_2(const vector<string> grid, char c)
{
	int m = grid.size();
	int n = grid[0].size();
	int f[55][55][3], low[55], high[55];
	
	SET(low, 0);
	FOR(i, 0, m-1)
	FOR(j, 0, n-1)
	{
		if(grid[i][j] == c)
			low[i] = j;
	}

	FOR(i, 0, m-1)
	{
		high[i] = n;
		FORD(j, n-1, 0)
		{
			if(grid[i][j] != c && grid[i][j] != '?')
				high[i] = j;
		}
	}

	FOR(i, 0, m-1)
	FOR(j, 0, high[i]-1)
	{
		if(grid[i][j] != c && grid[i][j] != '?')
			return 0;
	}

	// Init f
	SET(f, 0);
	FOR(j, max(1,low[0]), min(high[0]-1,n-1))
		f[0][j][0] = 1;

	// Dynamic program
	FOR(i, 1, m-1)
	FOR(j, max(1,low[i]), min(high[i]-1,n-1))
	{
		f[i][j][0] = f[i-1][j][0];

		f[i][j][1] = f[i-1][j][1];
		FOR(k, j+1, n-1)
		{
			f[i][j][1] = (f[i][j][1] + f[i-1][k][0]) % mod;
			f[i][j][1] = (f[i][j][1] + f[i-1][k][1]) % mod;
		}

		f[i][j][2] = f[i-1][j][2];
		FOR(k, 1, j-1)
		{
			f[i][j][2] += (f[i][j][2] + f[i-1][k][0]) % mod;
			f[i][j][2] += (f[i][j][2] + f[i-1][k][2]) % mod;
		}
	}

	int ret = 0;
		FOR (i, max(low[m-1], 1) , min(n - 1, high[m-1] - 1)) 
			ret = (ret + f[m-1][i][0] + f[m-1][i][1] + f[m-1][i][2]) % mod;
	return ret;
}

vector<string> TwoConvexShapesWiki::rotate(vector<string> grid)
{
	vector<string> ret;

	int m = grid.size();
	int n = grid[0].size();

	FOR(i, 0, n-1)
	{
		char* str = new char[m+1];
		str[m] = 0;
		FOR(j, 0, m-1)
		{
			str[j] = grid[j][n-1-i];
		}
		
		ret.push_back(str);
	}

	return ret;
}

void TwoConvexShapesWiki::print(const vector<string> grid)
{
	int m = grid.size();
	int n = grid[0].size();

	FOR(i,0,m-1)
	{
		FOR(j,0,n-1)
		{
			cout<<grid[i][j];
		}
		cout<<endl;
	}
}