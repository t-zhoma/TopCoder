#include "PlatypusDuckAndBeaverTest.h"
#include "PlatypusDuckAndBeaver.h"
#include <iostream>
#include <fstream>

using namespace std;

PlatypusDuckAndBeaverTest::PlatypusDuckAndBeaverTest(void)
{
}


PlatypusDuckAndBeaverTest::~PlatypusDuckAndBeaverTest(void)
{
}

void PlatypusDuckAndBeaverTest::Run()
{
	PlatypusDuckAndBeaver pdb;
	ifstream file("PlatypusDuckAndBeaverTest.txt");

	if(!file.is_open())
	{
		cout<<"Open PlatypusDuckAndBeaverTest.txt fail!"<<endl;
		return;
	}

	int webbedFeet, duckBills, beaverTails, expect;
	while(file>>webbedFeet>>duckBills>>beaverTails>>expect)
	{
		int ret = pdb.minimumAnimals(webbedFeet, duckBills, beaverTails);
		cout<<webbedFeet<<", "<<duckBills<<", "<<beaverTails<<" "<<expect<<" "<<ret<<" "<<((ret == expect) ? "Pass" : "Fail")<<endl;
	}

	file.close();
}