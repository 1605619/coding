#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/number-of-enclaves/description/ */

#define int long long int
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>

void print(vvc grid) {
	int m = grid.size(), n = grid[0].size();

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

// O(m*n) & O(HOT)
void dfs(vvi &grid, int i, int j, vvi &visited) { // 'A'
	int m = grid.size(), n = grid[0].size();

	if (i < 0 || j < 0 || i >= m || j >= n) return;
	if (grid[i][j] == 0) return;
	if (visited[i][j] == 1) return;

	visited[i][j] = 1;

	int move[5] = {0,1,0,-1,0};

	for (int k=0;k<4;k++) {
		dfs(grid, i + move[k], j + move[k+1], visited);
	}
}	

int numEnclaves(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid[0].size();

	vvi visited(m, vector<int>(n, 0));

	for (int i=0;i<n;i++) { // cols
		if (grid[0][i] == 1) {
			dfs(grid, 0, i, visited);
		}
		if (grid[m-1][i] == 1) {
			dfs(grid, m-1, i, visited);
		}
	}

	for (int i=0;i<m;i++) { // rows
		if (grid[i][0] == 1) {
			dfs(grid, i, 0, visited);
		}
		if (grid[i][n-1] == 1) {
			dfs(grid, i, n-1, visited);
		}
	}

	int count = 0;

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (grid[i][j] == 1 && visited[i][j] == 0) count++;
		}
	}

	return count;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int m,n,d;
	cin>>m>>n;

	vvi grid(m, vector<int>(n, 0));

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cin>>d;
			grid[i][j] = d;
		}
	}

	cout<<numEnclaves(grid);

	return 0;
}