#include "PlatypusDuckAndBeaver.h"


PlatypusDuckAndBeaver::PlatypusDuckAndBeaver(void)
{
}


PlatypusDuckAndBeaver::~PlatypusDuckAndBeaver(void)
{
}

int PlatypusDuckAndBeaver::minimumAnimals(int webbedFeet, int duckBills, int beaverTails)
{
	/*int	b = webbedFeet/2 + beaverTails - 3*duckBills;
	int	d = webbedFeet/2 - 2*duckBills;
	int	p = 4*duckBills - beaverTails - webbedFeet/2;*/

	int	b = webbedFeet/2 - beaverTails - duckBills;
	int	d = webbedFeet/2 - 2*beaverTails;
	int	p = 2*beaverTails + duckBills - webbedFeet/2;

	return d + b + p;
}