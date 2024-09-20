#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>
#define vi vector<int>

/*
	https://www.youtube.com/watch?v=uRbJ1OF9aYM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=20

	Find eventual states: DFS

	
	Terminal node - node which has outdegree = 0, i.e., no outgoing nodes
	Safe node - all paths from this node leads to a terminal node

	So, all terminal nodes are also safe nodes. 

	Problem: Need to find all safe nodes in given graph. Do it using tech of cycle detection in a directed graph

	Though, another approch could be also using Topo sort, that will be discussed later.
	
	-> Using DFS with visited[] and path[] for detecting cycles in a Directed Graph
	-> safe[] array to mark if a node is safe	
		
*/

// DFS (stack or memory stack)
bool detectCycle(vvi &grid, int start, vi &visited, vi &path, vi &safe) {
	int nbrs = grid[start].size();

	if (safe[start] == 1) return false; // if encounter a safe node, means no cycles further in the path, so no need to explore as already visited earlier

	// cycle detected on same path
	if (visited[start] == 1 && path[start] == 1) return true;  

	visited[start] = 1;
	path[start] = 1;

	for (int i=0;i<nbrs;i++) {
		if (detectCycle(grid, grid[start][i], visited, path, safe)) return true;
	}

	path[start] = 0; // backtracking

	safe[start] = 1; // marking it as safe node

	return false;
}

bool isCycle(vvi &grid) {
    int n = grid.size();

    vi visited(n,0);
    vi path(n,0);
    vi safe(n,0);

    for (int i=0;i<n;i++) {
    	if (visited[i] == 0) { // if not added, it will do O(N^2), as for each node, DFS will happen again
    		cout<<detectCycle(grid, i, visited, path, safe);
    	}
    }

    cout<<endl;
    for (int i=0;i<n;i++) {
    	cout<<safe[i]<<" ";
    }
    cout<<endl;

    return false;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vvi grid = {{},{2},{3},{1}};

	cout<<isCycle(grid);

	return 0;
}