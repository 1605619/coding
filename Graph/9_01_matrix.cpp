#include<bits/stdc++.h>
using namespace std;

/* https://leetcode.com/problems/01-matrix/description/ */

#define int long long int
#define vvi vector<vector<int>>

void print(vvi grid) {
	int m = grid.size(), n = grid[0].size();

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

// TC: O(m*n) and SC: O(m*n)
vvi updateMatrix(vvi &grid) {
	int m = grid.size(), n = grid[0].size();

	vvi visited(m, vector<int>(n, 0));
	vvi result(m, vector<int>(n, 0)); // it's not a good practice to modify grid and always recommeded to create new vector

	queue<pair<int,int>> q;

	for (int i=0;i<m;i++) { // O(m*n)
		for (int j=0;j<n;j++) {
			if (grid[i][j] == 0) {
				q.push({i,j});
				visited[i][j] = 1;
			}
		}
	}

	int level = 0;

	while (!q.empty()) { 
		int size = q.size();
		level++;

		for (int i=0;i<size;i++) {
			pair<int, int> temp = q.front();
			q.pop();

			int move[5] = {0,1,0,-1,0};

			for (int k=0;k<4;k++) {
				int nr = temp.first + move[k], nc = temp.second + move[k+1];

				if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
					
					if (visited[nr][nc] == 0) {
						visited[nr][nc] = 1;
						result[nr][nc] = level;
						q.push({nr, nc});
					}
				}
			}
		}
	}

	return result;
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

	vvi result = updateMatrix(grid);
	print(result);

	return 0;
}