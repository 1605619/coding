#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>

/* https://leetcode.com/problems/is-graph-bipartite/description/ */

void print(vvi grid) {
	int m = grid.size(), n = grid[0].size();

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cout<<"("<<i<<","<<j<<")"<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

// Fix it for test case: [[4],[],[4],[4],[0,2,3]]
bool dfs(vvi& grid, int start, vector<int> &visited) {
	stack<int> s;
	s.push(start);
	visited[start] = -1;

	cout<<start<<endl;

	int color = -1;

	while (!s.empty()) {
		int temp = s.top();
		s.pop();

		color *= -1;

		for (int i=0;i<grid[temp].size();i++) {
			if (visited[grid[temp][i]] == 0) {
				visited[grid[temp][i]] = color;
				s.push(grid[temp][i]);
			}
			else {
				if (visited[grid[temp][i]] != color) {
					cout<<i<<", "<<temp<<", "<<grid[temp][i]<<", "<<visited[grid[temp][i]]<<", "<<color<<endl;
					return false;
				}
			}
		}
	}

	return true;
}

// BFS (Queue)
bool bfs(vvi& grid, int start, vector<int> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = -1;

    int color = -1;

    while (!q.empty()) {
    	int size = q.size();
    	color *= -1;

    	for (int i=0;i<size;i++) {
    		int temp = q.front();
    		q.pop();

    		for (int j=0;j<grid[temp].size();j++) {
    			if (visited[grid[temp][j]] == 0) {
    				visited[grid[temp][j]] = color;
    				q.push(grid[temp][j]);
    			}
    			else {
    				if (visited[grid[temp][j]] != color) {
    					cout<<visited[grid[temp][j]]<<", "<<color<<endl;
    					return false;
    				}
    			}
    		}
    	}
    }
    
    return true; 
}

bool isBipartite(vvi& grid) {
	int n = grid.size();
	vector<int> visited(n, 0);

	// It's necessary for connected componenets & if '0' or some node doesn't exist
	for (int i=0;i<n;i++) {
		if (visited[i] == 0) {
			if (dfs(grid, i, visited) == false) {
				cout<<endl<<endl;

				for (int i=0;i<n;i++) {
					cout<<visited[i]<<", ";
				}

				cout<<endl<<endl;

				return false;
			}
		}
	}

	
	return true;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif

	vvi grid = {{4},{},{4},{4},{0,2,3}};

	cout<<isBipartite(grid);
	

	return 0;
}