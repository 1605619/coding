#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvc vector<vector<char>>

/* https://leetcode.com/problems/number-of-islands/description/ */

void dfs(int i, int j, int m, int n, vvc &graph) {
	if (i<0 || j<0 || i == m || j == n) return;
	if (graph[i][j] == '0') return;

	graph[i][j] = '0';

	int move[5] = {0,1,0,-1,0};
	for (int k=0;k<4;k++) {
		dfs(i+move[k], j+move[k+1], m, n, graph);
	}
}

int islands(vvc &graph) {
	int count = 0, m = graph.size(), n = graph[0].size();

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (graph[i][j] == '1') {
				count++;

				dfs(i,j,m,n,graph);
			}
		}
	}

	return count;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
		
	int m,n;
	cin>>m>>n;

	char d;

	vector<vector<char>> graph(m, vector<char>(n, '0')); // initilizing graph with '0' values

	for (int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>d;
			graph[i][j] = d; // don't do push_back
		}
	}

	// print(graph);

	cout<<islands(graph);

	return 0;
}