#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/surrounded-regions/description/ */

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
void dfs(vvc &grid, int i, int j, vvi &visited) { // 'A'
	int m = grid.size(), n = grid[0].size();

	if (i < 0 || j < 0 || i >= m || j >= n) return;
	if (grid[i][j] == 'X') return;
	if (visited[i][j] == 1) return;

	visited[i][j] = 1;
	// grid[i][j] = 'A';

	int move[5] = {0,1,0,-1,0};

	for (int k=0;k<4;k++) {
		dfs(grid, i + move[k], j + move[k+1], visited);
	}
}	

// O(m*n) & O(HOT)
void solve(vvc &grid) {
	int m = grid.size(), n = grid[0].size();

	vvi visited(m, vector<int>(n, 0));

	// 1. Convert all regions with 'O's to 'A's which are touched by boundary
	// 2. Convert all 'O's to 'X's if there are any - it will cover surrounded regions
	// 3. Convert all 'A's to 'O's again

	// OR

	// a bit better:

	// 1. Mark visited all cells for all regions with 'O's which are touched by boundary
	// 2. Convert all 'O's to 'X's if they are not visited - it will cover surrounded regions

	for (int i=0;i<n;i++) { // cols
		if (grid[0][i] == 'O') {
			dfs(grid, 0, i, visited);
		}
		if (grid[m-1][i] == 'O') {
			dfs(grid, m-1, i, visited);
		}
	}

	for (int i=0;i<m;i++) { // rows
		if (grid[i][0] == 'O') {
			dfs(grid, i, 0, visited);
		}
		if (grid[i][n-1] == 'O') {
			dfs(grid, i, n-1, visited);
		}
	}

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (grid[i][j] == 'O' && visited[i][j] == 0) grid[i][j] = 'X';
		}
	}

	// for (int i=0;i<m;i++) {
	// 	for (int j=0;j<n;j++) {
	// 		if (grid[i][j] == 'A') grid[i][j] = 'O';
	// 	}
	// }
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int m,n;
	cin>>m>>n;

	char d;

	vvc grid(m, vector<char>(n, 'X'));

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cin>>d;
			grid[i][j] = d;
		}
	}

	solve(grid);
	print(grid);

	return 0;
}