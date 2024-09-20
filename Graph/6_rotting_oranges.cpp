#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/rotting-oranges/description/ */

#define int long long int
#define vvc vector<vector<int>>


// WRONG CODE 0- MISSING EDGE CASES
int bfs(int i, int j, vvc &grid) {
	int m = grid.size(), n = grid[0].size();

	queue<pair<int, int>> q;
	q.push({i,j});
	grid[i][j] = -1;

	int time = 0;

	while (!q.empty()) {
		int size = q.size();
		time++;

		for (int k=0;k<size;k++) {
			pair<int, int> temp = q.front();
			q.pop();

			int move[5] = {0,1,0,-1,0};

			for(int p=0;p<4;p++) {
				int nr = temp.first + move[p], nc = temp.second + move[p+1];
				if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
					q.push({nr, nc});
					grid[nr][nc] = -1;
				}
			}
		}
	}

	return time-1;
}

int rottingOranges(vvc &grid) {
	int m = grid.size(), n = grid[0].size();

	int maxTime = 0;

	for (int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			if (grid[i][j] == 2) {
				maxTime = max(maxTime, bfs(i,j,grid));
			}
		}
	}

	for (int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			if (grid[i][j] == 1) return -1;
		}
	}

	return maxTime;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int m,n;
	cin>>m>>n;

	int d;

	vvc grid(m, vector<int>(n, 0)); // initilizing graph with '0' values

	for (int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>d;
			grid[i][j] = d; // don't do push_back
		}
	}

	cout<<rottingOranges(grid);

	return 0;
}