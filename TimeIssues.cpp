#include "TimeIssues.h"

tmpt GetTimePoint1()
{
	return chrono::high_resolution_clock::now();
}
uint64_t GetDuration(tmpt timepoint1)
{
	//checks time the second time and returns miliseconds from first
	tmpt timepoint2 = chrono::high_resolution_clock::now();
	return chrono::duration_cast<chrono::milliseconds>(timepoint2 - timepoint1).count();
}
uint64_t GetDuration(tmpt timepoint1, tmpt timepoint2)
{
	return chrono::duration_cast<chrono::milliseconds>(timepoint2 - timepoint1).count();
}
