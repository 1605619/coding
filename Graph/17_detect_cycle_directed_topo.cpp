#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>

/* 
	Detect a cycle in directed graph using Topologic sorting (not path vector) 

	https://www.youtube.com/watch?v=iTBaI90lpDQ&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23
*/

bool isCycle(vvi &grid) {
	int n = grid.size();

	
}


int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vvi grid = {{},{},{3},{1},{0,1},{0,2}};

	cout<<isCycle(grid);

	return 0;
}