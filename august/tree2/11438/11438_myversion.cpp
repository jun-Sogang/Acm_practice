#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int LOG_MAX = 18;
queue < int > q;
vector < int > v[MAX];
int depth[MAX];
int parent[MAX][LOG_MAX];

