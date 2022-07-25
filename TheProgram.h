#pragma once

#include<iostream>
#include<iomanip>
#include "TheSort.h"
#include "TestData.h"
#include "TimeIssues.h"


using namespace std;
using Iter = vector<int>::iterator;

void VectorOutput(vector<int>* vec, int colcount = 10);
bool TestSortForCorrectness(vector<int>* vec);
