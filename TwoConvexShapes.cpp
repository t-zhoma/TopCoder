#include "TwoConvexShapes.h"
#include <assert.h>

TwoConvexShapes::TwoConvexShapes(void)
{
}


TwoConvexShapes::~TwoConvexShapes(void)
{
}

int TwoConvexShapes::countWays(vector<string> grid)
{
	m_grid = grid;
	m_tempGrid = grid;

	if(!IsSatisfy())
		return 0;

	Pos p(0, 0);

	if(!GetFirstPos(grid, '?', p))
		return 1;

	int nRet = 0;
	Pos pTemp = p;
	while(pTemp.i != p.i || pTemp.j != p.j || m_grid[p.i][p.j] != 'B')
	{
		char ch = GetNextChar(m_grid[pTemp.i][pTemp.j]);
		m_grid[pTemp.i][pTemp.j] = ch;

		if( ch == '?')
		{
			bool bTemp = GetPrevPos(m_tempGrid, '?', pTemp, pTemp);
			assert(bTemp);
		}
		else if(IsValidValue(pTemp))
		{
			if(!GetNextPos(m_tempGrid, '?', pTemp, pTemp)) // last '?'
			{
				nRet++;
			}
		}
	}

	return nRet;
}

bool TwoConvexShapes::IsSatisfy()
{
	for(size_t i = 0; i < m_grid.size(); i++)
	{
		if(!IsRowValid(i))
			return false;
	}

	for(size_t j = 0; j < m_grid[0].size(); j++)
	{
		if(!IsColValid(j))
			return false;
	}

	if(!IsConnect())
		return false;

	return true;
}

bool TwoConvexShapes::GetFirstPos(const vector<string>& vt, char ch, Pos &p)
{
	for(size_t i = 0; i < vt.size(); i++)
		for(size_t j = 0; j < vt[0].size(); j++)
		{
			if(vt[i][j] == ch)
			{
				p.i = i;
				p.j = j;
				return true;
			}
		}

	return false;
}

bool TwoConvexShapes::GetNextPos(const vector<string>& vt, char ch, Pos prev, Pos &p)
{
	for(size_t j = prev.j + 1; j < vt[0].size(); j++)
	{
		if(vt[prev.i][j] == ch)
			{
				p.i = prev.i;
				p.j = j;
				return true;
			}
	}

	for(size_t i = prev.i + 1; i < vt.size(); i++)
		for(size_t j = 0; j < vt[0].size(); j++)
		{
			if(vt[i][j] == ch)
			{
				p.i = i;
				p.j = j;
				return true;
			}
		}

	return false;
}

bool TwoConvexShapes::GetPrevPos(const vector<string>& vt, char ch, Pos next, Pos &p)
{
	for(int j = next.j - 1; j >= 0; j--)
	{
		if(vt[next.i][j] == ch)
			{
				p.i = next.i;
				p.j = j;
				return true;
			}
	}

	for(int i = next.i - 1; i >= 0; i--)
		for(int j = vt[0].size() - 1; j >= 0; j--)
		{
			if(vt[i][j] == ch)
			{
				p.i = i;
				p.j = j;
				return true;
			}
		}

	return false;
}

char TwoConvexShapes::GetNextChar(char ch)
{
	switch(ch)
	{
	case '?':
		return 'W';

	case 'W':
		return 'B';

	case 'B':
		return '?';
	
	default:
		assert(false);
		return 'X';
	}
}

bool TwoConvexShapes::IsValidValue(Pos p)
{
	char ch = m_grid[p.i][p.j];
	assert(ch != '?');

	if(!IsConnect())
		return false;

	if(!IsRowValid(p.i))
		return false;

	if(!IsColValid(p.j))
		return false;

	return true;
}

bool TwoConvexShapes::IsSameValueAround(Pos p)
{
	char ch = m_grid[p.i][p.j];
	
	if(p.j > 0 && (m_grid[p.i][p.j-1] == ch || m_grid[p.i][p.j-1] == '?') )
	{
		return true;
	}

	if(p.j < m_grid[0].size()-1 && (m_grid[p.i][p.j+1] == ch || m_grid[p.i][p.j+1] == '?') )
	{
		return true;
	}

	if(p.i > 0 && (m_grid[p.i-1][p.j] == ch || m_grid[p.i-1][p.j] == '?') )
	{
		return true;
	}

	if(p.i < m_grid.size()-1 && (m_grid[p.i+1][p.j] == ch || m_grid[p.i+1][p.j] == '?') )
	{
		return true;
	}

	return false;
}

int TwoConvexShapes::Count(char ch)
{
	int nRet = 0;

	for(size_t i = 0; i < m_grid.size(); i++)
		for(size_t j = 0; j < m_grid[0].size(); j++)
		{
			if(m_grid[i][j] == ch)
			{
				nRet++;	
			}
		}

	return nRet;
}

bool TwoConvexShapes::IsRowValid(size_t r)
{
	size_t j;
	char temp;
	for(j = 0; j < m_grid[0].size(); j++)
	{
		if(m_grid[r][j] != '?')
		{
			temp = m_grid[r][j];
			break;
		}
	}
	
	if(j != m_grid[0].size())
	{
		for(j++;j < m_grid[0].size(); j++)
		{
			if(m_grid[r][j] != temp && m_grid[r][j] != '?')
			{
				for(j++;j < m_grid[0].size(); j++)
				{
					if(m_grid[r][j] == temp)
						return false;
				}
			}
		}
	}

	return true;
}

bool TwoConvexShapes::IsColValid(size_t c)
{
	size_t i;
	char temp;

	for(i = 0; i < m_grid.size(); i++)
	{
		if(m_grid[i][c] != '?')
		{
			temp = m_grid[i][c];
			break;
		}
	}
	
	if(i != m_grid.size())
	{
		for(i++;i < m_grid.size(); i++)
		{
			if(m_grid[i][c] != temp && m_grid[i][c] != '?')
			{
				for(i++;i < m_grid.size(); i++)
				{
					if(m_grid[i][c] == temp)
						return false;
				}
			}
		}
	}

	return true;
}

bool TwoConvexShapes::IsConnect()
{
	return IsConnect('B') && IsConnect('W');
}

bool TwoConvexShapes::IsConnect(char ch)
{
	assert(ch == 'B' || ch == 'W');
	Pos p(0,0);

	if(GetFirstPos(m_grid, ch, p))
	{
		vector<string> vt = m_grid;
		DFS(vt, ch, p);
		
		for(size_t i = 0; i < m_tempGrid.size(); i++)
			for(size_t j = 0; j < m_tempGrid[0].size(); j++)
			{
				if(m_grid[i][j] == ch && vt[i][j] != 'X')
					return false;
			}
	}

	return true;
}

void TwoConvexShapes::DFS(vector<string>& grid, char ch, Pos p)
{
	grid[p.i][p.j] = 'X';
	
	if(p.j > 0 && (grid[p.i][p.j-1] == ch || grid[p.i][p.j-1] == '?') )
	{
		grid[p.i][p.j-1] = 'X';
		DFS(grid, ch, Pos(p.i, p.j-1));
	}

	if(p.j < grid[0].size()-1 && (grid[p.i][p.j+1] == ch || grid[p.i][p.j+1] == '?') )
	{
		grid[p.i][p.j+1] = 'X';
		DFS(grid, ch, Pos(p.i, p.j+1));
	}

	if(p.i > 0 && (grid[p.i-1][p.j] == ch || grid[p.i-1][p.j] == '?') )
	{
		grid[p.i-1][p.j] = 'X';
		DFS(grid, ch, Pos(p.i-1, p.j));
	}

	if(p.i < grid.size()-1 && (grid[p.i+1][p.j] == ch || grid[p.i+1][p.j] == '?') )
	{
		grid[p.i+1][p.j] = 'X';
		DFS(grid, ch, Pos(p.i+1, p.j));
	}
}