#include "TheProgram.h"

//RANGE OF NUMBERS GENERATED IN THE TEST VECTOR:
#define LOWERLIMIT -1000
#define UPPERLIMIT 1000

int main()
{
	cout << "****************** This program presents and tests a sorting algorithm ****************** " << endl<<endl;
	cout << "A vector of random integer numbers is generated according to user input, then sorted using \n";
	cout << "the algorithm. Finally the result is tested by comparing each two successive elements. The \n";
	cout << "program also uses <chrono> to compare the algorithm's performance to the sorting algorithm \n";
	cout << "in the C++ Standard Library\n\n";

	int lowerlimit = LOWERLIMIT;
	int upperlimit = UPPERLIMIT;

	cout << endl << "Enter a positive number. This is how many random elements the vector will have: \n";
	uint32_t vectorsize;
	cin >> vectorsize;
	
	//Generate using random numbers, and output the sample vector
	vector<int>* vec = GenerateVector(vectorsize, lowerlimit, upperlimit);
	
	cout << endl;
	cout << "Here's the vector: \n\n";
	VectorOutput(vec);

	//Copy the vector for future comparison with the C++ STL sorting algorithm
	vector<int>* veccopy = new vector<int>(*vec); //copy of the vector to compare with stdlib sort
	
	//Perform the sort while measuring machine time
	tmpt timepoint1 = GetTimePoint1();
	SortPl(vec);
	uint64_t duration1 = GetDuration(timepoint1);

	cout << "Here's the vector again, sorted: \n";
	VectorOutput(vec);


	//Run test to see if elements are in correct order
	if (TestSortForCorrectness(vec))
		cout << "The algorithm has sorted correctly.\n\n";
	else
		cout << "The algorithm doesn't even sort correctly! :D.\n\n";

	//Output the time performance of the algorithm
	cout << "Evaluating performance:\n";
	cout << "The subject sorting algorithm took " << duration1 << " miliseconds.\n";

	//Sort again using the STL algorithm, while measuring machine time
	tmpt timepoint2 = GetTimePoint1();
	sort(veccopy->begin(), veccopy->end(), less<int>() );
	uint64_t duration2 = GetDuration(timepoint2);
	
	//Output the time performance and comparison
	cout << "The standard library sorting algorithm took " << duration2 << " miliseconds.\n";
	
	if (duration1 < duration2)
		cout << "That is pretty good :)\n\n";
	else if (duration1 == duration2)
		cout << "Both algorithms took about the same time! \n\n";
	else
		cout << "That is a pretty slow aogrithm! :D\n\n";

	delete vec, veccopy;

	return 0;
	
}

bool TestSortForCorrectness(vector<int>* vec)
{
	vector<int> positions; //collect positions whree the sorted vector is in an incorrect order

	for (uint32_t i = 1; i < vec->size(); i++)
		if ((*vec)[i - 1] > (*vec)[i])
			positions.insert(positions.end(), i);

	if (positions.size() == 0)
	{
		cout << "The vector has been sorted ascending. " << endl;
		return true;
	}
	else
	{
		cout << "At the following positions the elements of the vector are not in ascending order: " << endl;
		VectorOutput(&positions);
		return false;
	}
			

}

void VectorOutput(vector<int>* vec, int colcount)
{	//default colcount = 10 in declaration

	int i = 0;
	int j = 0;

	while(i < vec->size())
	{
		while(j < colcount && i < vec->size())
		{
			cout << setw(10) << (*vec)[i] << ' ';
			i++;
			j++;
		}
		cout << endl;
		j = 0;
	}
	cout << endl << endl;

}


	

