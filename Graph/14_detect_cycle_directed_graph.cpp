#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

bool dfs(vvi &grid, int node, vector<int> &visited, vector<int> &path) {
	if (visited[node] == 1 && path[node] == 1) {
		return true;
	}

	visited[node] = 1;
	path[node] = 1;

	for (int i=0;i<grid[node].size();i++) {
		if (dfs(grid, grid[node][i], visited, path) == true) {
			return true;
		}
	}

	path[node] = 0; // backtrack

	return false;
}

bool isCycleDetected(vvi &grid) {
	int n = grid.size();

	cout<<n<<endl;

	vector<int> visited(n, 0);
	vector<int> path(n, 0);

	for (int i=0;i<n;i++) {
		if (dfs(grid, i, visited, path) == true) return true;
	}

	return false;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vvi grid = {{},{2},{3},{1}};

	cout<<isCycleDetected(grid);

	return 0;
}