#include <iostream>
#include <cmath>
using namespace std;

int doubleSquare(unsigned num)
{
	int upper = sqrt((double)num / 2.0); 
	int total = 0;
	for(int i = 0; i <= upper; i++)
	{
		double m = sqrt((double)num - i*i);
		if(m - (int)m == 0)
			total++;
	}
	return total;
}
