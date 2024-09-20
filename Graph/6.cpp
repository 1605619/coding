#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

int bfs(vvi &grid, queue<pair<int, int>> &q) {
	int m = grid.size(), n = grid[0].size();

	int level = 0;

	while (!q.empty()) {
		int size = q.size();
		level++;

		for (int i=0;i<size;i++) {
			pair<int, int> curr = q.front();
			q.pop();

			int move[5] = {0,1,0,-1,0};

			for (int k=0;k<4;k++) {
				int nr = curr.first + move[k], nc = curr.second + move[k+1];

				if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
					grid[nr][nc] = 2;
					q.push({nr, nc});
				}
			}

		}	
	}

	return level > 0 ? level - 1 : level;
}
	
int rottingOranges(vvi &grid) {
	int m = grid.size(), n = grid[0].size();

	queue<pair<int, int>> q;

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (grid[i][j] == 2) q.push({i,j});
		}
	}

	int time = bfs(grid, q);
	
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (grid[i][j] == 1) return -1;
		}
	}

	// Instead of using loop, I can just check if #fresh oranges and #oranges turned to rotten are same or not

	// if (countFresh != countRotten) return -1;

	return time;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int m,n;
	cin>>m>>n;

	int d;

	vvi grid(m, vector<int>(n, 0)); // initilizing graph with '0' values

	for (int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>d;
			grid[i][j] = d; // don't do push_back
		}
	}

	cout<<rottingOranges(grid);

	return 0;
}