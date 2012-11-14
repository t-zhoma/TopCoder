#include "SuminatorTest.h"
#include "Suminator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

SuminatorTest::SuminatorTest(void)
{
}


SuminatorTest::~SuminatorTest(void)
{
}

void SuminatorTest::Run()
{
	ifstream file("SuminatorTest.txt");
	if(!file.is_open())
	{
		cout<<"Open SuminatorTest.txt fail!"<<endl;
		return;
	}

	char line[1024] = {0};
	vector<int> vt;

	while(file.getline(line, 1024))
	{	
		vt.clear();
		stringstream ss(line);
		
		int n;
		while(ss>>n)
		{
			vt.push_back(n);
		}

		int answer = vt.back();
		vt.pop_back();
		int wantedResult = vt.back();
		vt.pop_back();

		Suminator s;
		int ret = s.findMissing(vt, wantedResult);
		
		cout<<"{";
		for(int i = 0; i < vt.size(); ++i)
		{
			cout<<vt[i];
			if(i < vt.size() - 1) { cout<<", ";}
		}

		cout<<"}, "<<wantedResult<<"\t"<<answer<<"\t"<<ret<<"\t"<<((answer == ret) ? "pass" : "fail")<<endl;
	}

	file.close();
}