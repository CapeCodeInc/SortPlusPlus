#pragma once

#include<chrono>

using namespace std;
using tmpt = chrono::steady_clock::time_point;


tmpt GetTimePoint1();
uint64_t GetDuration(tmpt timepoint1);
uint64_t GetDuration(tmpt timepoint1, tmpt timepoint2);
