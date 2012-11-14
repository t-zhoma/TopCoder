#include "TwoConvexShapesTest.h"
#include "TwoConvexShapes.h"
#include "TwoConvexShapesWiki.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

TwoConvexShapesTest::TwoConvexShapesTest(void)
{
}


TwoConvexShapesTest::~TwoConvexShapesTest(void)
{
}

void TwoConvexShapesTest::Run()
{
	ifstream file("TwoConvexShapesTest.txt");
	if(!file.is_open())
	{
		cout<<"Open TwoConvexShapesTest.txt fail!"<<endl;
		return;
	}

	//##TwoConvexShapes tcs;
	TwoConvexShapesWiki tcs;

	char line[1024] = {0};
	vector<string> vt;

	while(file.getline(line, 1024))
	{	
		string str(line);
		
		if('0' <= str[0] && str[0] <= '9')
		{
			int nExpect = atoi(str.c_str());
			int nRet = tcs.countWays(vt);

			if(nExpect != nRet)
			{
				for(size_t i = 0; i < vt.size(); i ++)
				{
					cout<<vt[i]<<endl;
				}
				cout<<nExpect<<"\t"<<nRet<<"\t"<<(nExpect == nRet ? "Pass" : "Fail")<<endl<<endl;
			}

			vt.clear();
		}
		else
		{
			vt.push_back(str);
		}	
	}

	file.close();
}