#include "TestData.h"


vector<int>* GenerateVector(int vectorsize, int lowerlimit, int upperlimit)
{
	vector<int>* vec = new vector<int>();
	mt19937 rndrange;
	int seedval = 2349;
	uniform_int_distribution<int> number(lowerlimit, upperlimit);

	while (vectorsize-- > 0)
		vec->insert(vec->end(), number(rndrange));

	return vec;
}
