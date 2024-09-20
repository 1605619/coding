#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>

/* Topologic Sort - possible only in DAG so conserdering only DAG graphs*/

void dfs(vvi &grid, int node, vi &visited, stack<int> &stack) {
	int n = grid[node].size();

	if (visited[node] == 1) return;

	visited[node] = 1;
	
	for (int i=0;i<n;i++) {
		dfs(grid, grid[node][i], visited, stack);
	} 

	stack.push(node);
}

//Approch 1: DFS - Topological Sort Algo
vi topological(vvi &grid) {
	int n = grid.size();

	vi topo;
	if (n == 0) return topo;

	stack<int> stack;
	vi visited(n,0);

	// connected component
	for (int i=0;i<n;i++) {
		if (visited[i] == 0) {
			dfs(grid, i, visited, stack);
		}
	}

	cout<<"DFS: ";

	while (!stack.empty()) {
		topo.push_back(stack.top());
		cout<<stack.top()<<" ";
		stack.pop();
	}
	cout<<endl;

	return topo;
}

//Approch 2: BFS - Kahn's Algo (Topological Sort Algo)
vi kahn(vvi &grid) {
	int n = grid.size();

	vi topo;
	vi indegree(n,0);
	// vi visited(n,0);

	for (int i=0;i<n;i++) {
		for (int j=0;j<grid[i].size();j++) {
			indegree[grid[i][j]]++;
		}
	}

	queue<int> q;

	for (int i=0;i<n;i++) {
		// it also covers connected component thing
		if (indegree[i] == 0) q.push(i); // conserdering it will push at least once, as DAG
	}

	cout<<"BFS (Kahn): ";

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			int temp = q.front();
			q.pop();

			topo.push_back(temp);
			cout<<temp<<" ";

			for (int j=0;j<grid[temp].size();j++) {
				indegree[grid[temp][j]]--;
				if (indegree[grid[temp][j]] == 0) {
					q.push(grid[temp][j]);
				}
			}
		}
	}

	return topo;
}

void print(vi topo) {
	for (int i=0;i<topo.size();i++) {
		cout<<topo[i]<<" ";
	}
	cout<<endl;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vvi grid = {{},{},{3},{1},{0,1},{0,2}};

	vi result_dfs = topological(grid);

	vi result_kahn = kahn(grid);

	return 0;
}