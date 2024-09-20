#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

/* https://leetcode.com/problems/number-of-provinces/description/ */

/*
	Build understanding:
	1. Matt Yang - https://www.youtube.com/watch?v=LVlihRYfVVw
	2. https://leetcode.com/problems/number-of-islands/solutions/56589/c-bfs-dfs/

	BFS uses Queue and DFS using call stack (Aux), but common thing is both moves in all 4 directions on grid
*/

// Trick:
// if mentioned: cells being adjacent or movement in 4 directions -> graph traversal
// or if problem involve optimisations such as maxmize path sum or if you already know already about grid then probably not graph traverasal


/*

WRONG - because:


	example:
		4
		1 0 0 1
		0 1 1 0
		0 1 1 1
		1 0 1 1

	This looks like 4 component graph, but if you draw it's a single connected graph.
	So my solution gives: 4 anser but correct answer is 1

	So this solution can't work for this problem

	We need to convert adj matrix to list to be able to do this or some other method

*/
void visitProvince(vvi &graph, int i, int j) {
	int size = graph.size();

	if (i<0 || j<0 || i == size || j == size) return;
	if (graph[i][j] == 0) return;

	graph[i][j] = 0;

	int move[5] = {0,1,0,-1,0};

	for (int k=0;k<4;k++) {
		visitProvince(graph, i + move[k], j + move[k+1]);
	}
}

// Wrong
int provinces2(vvi &graph) {
	int size = graph.size();

	int count = 0;

	for (int i=0;i<size;i++) {
		for (int j=0;j<size;j++) {
			if (graph[i][j] == 1) {
				count++;

				visitProvince(graph,i,j);
			}
		}
	}

	return count;
}

// Correct - using Adj list

void addEdge(vvi &adj, int s, int d) {
	adj[s].push_back(d);
}


vector<int> visited(100,0);

void remove(vvi graph, int start) {

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i=0;i<graph[curr].size();i++) {
			if (visited[graph[curr][i]] == 0) {
				visited[graph[curr][i]] = 1;
				q.push(graph[curr][i]);
			}
		}
	}
}

int provinces3(vvi &graph) {
	int size = graph.size();

	vvi adj(size, vector<int>());

	for (int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			if (graph[i][j] == 1 && i != j)
				addEdge(adj, i, j);
		}
	}

	int count = 0;

	for (int i=0;i<adj.size();i++) {
		if (visited[i] == 0) {
			remove(adj,i);
			count++;
		}
	}

	return count;
}

// Correct 2 - without using Adj list

void dfs(int i, vvi &graph, vector<int> &visitedGraph) {
	visitedGraph[i] = 1; 

	for (int j=0;j<graph[i].size();j++) {
		if(i != j && graph[i][j] && visitedGraph[j] == 0) {
			dfs(j, graph, visitedGraph);
		}	
	}
}

int provinces(vvi &graph) {
	int size = graph.size();

	int count = 0;

	vector<int> visitedGraph(size, 0);

	for (int i=0;i<size;i++) {
			if (visitedGraph[i] == 0) {
				count++;
				dfs(i, graph, visitedGraph);			
			}
	}

	return count;
}


int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,d;
	cin>>n;

	vvi graph(n, vector<int>(n));

	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin>>d;
			graph[i][j] = d;
		}
	}

	cout<<provinces(graph);

	return 0;
}