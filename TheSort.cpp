#include "TheSort.h"

using Iter = vector<int>::iterator;

void SortPl(vector<int>* vec)
{
	//The algorithm uses minimums and maximums for each iteration and places them at the ends of the 
	//range being sorted
	Iter loopbeg = vec->begin();
	Iter loopend = vec->end();
	Iter runner = vec->begin();
	Iter runmin = vec->begin();
	Iter runmax = vec->begin();

	int min, max;
	int swapmin, swapmax;

	size_t rangelength = vec->size();

	while (rangelength > 1)	//if vector has an odd size, the last element will be left in the middle
	{
		min = INT_MAX;
		max = INT_MIN;
		runmin = loopbeg;
		runmax = loopend;
		//find min and max and their positions
		for (runner = loopbeg; runner != loopend; runner++)
		{
			if (*runner > max)
			{
				max = *runner;
				runmax = runner;
			}

			if (*runner < min)
			{
				min = *runner;
				runmin = runner;
			}

		}

		loopend--;	//both ends are moved toward each other during each iteration. Since the end 
					//points to the element AFTER the end of the range, it is being moved here, to make
					//easier access to the last element

		if (runmin == loopbeg && runmax == loopend)	//nothing to move
		{
			loopbeg++;
			//loopend--; already done
			rangelength -= 2;
			continue;
		}
		else if (runmin == loopend && runmax == loopbeg)//just swap the two extremes
		{
			swapmin = *loopend;
			*loopend = *loopbeg;
			*loopbeg = swapmin;
		}
		else if (runmin == loopend)	//one of the extremes is at the opposite end of the range
		{
			swapmin = *loopend;
			*loopend = *runmax;
			*runmax = *loopbeg;
			*loopbeg = swapmin;
		}
		else if (runmax == loopbeg)	//the other extreme is at the opposite end of the range
		{
			swapmax = *loopbeg;
			*loopbeg = *runmin;
			*runmin = *loopend;
			*loopend = swapmax;

		}
		else //general case, both extremes are at random positions, being swapped for ends
		{
			swapmin = *runmin;
			swapmax = *runmax;
			*runmin = *loopbeg;
			*runmax = *loopend;
			*loopbeg = swapmin;
			*loopend = swapmax;
		}
		//shorten the unsorted range
		loopbeg++;
		//loopend--; already done
		rangelength -= 2;
	}

}
