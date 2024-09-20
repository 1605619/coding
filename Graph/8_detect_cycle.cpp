#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

bool bfs(vvi &graph, vector<int> &visited, int start) {
	// int n = graph.size();

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			int temp = q.front();
			q.pop();

			cout<<temp<<": ";

			for (int j=0;j<graph[temp].size();j++) {
				if (visited[graph[temp][j]] == 1 && )
				if (visited[graph[temp][j]] == 0) {
					visited[graph[temp][j]] = 1;
					q.push(graph[temp][j]);
				}
			}

		}
	} 

	return true;
}

bool detectCycle(vvi &graph) {
	int n = graph.size();

	vector<int> visited(n, 0);

	for (int i=0;i<n;i++) {
		if (visited[i] == 0) {
			if (bfs(graph, visited, i) == false) return false;
		}
	}

	cout<<endl;

	return true;
}

void addEdge(vvi &graph, int s, int d) {
	graph[s].push_back(d);
	graph[d].push_back(s);
}

void print(vvi graph) {
	for (int i=0;i<graph.size();i++) {
		cout<<i<<": ";
		for (auto x: graph[i]) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
		
	int n,s,d;
	cin>>n;

	vvi graph(n, vector<int>()); // can be a connected component

	for (int i=0;i<n;i++) {
			cin>>s>>d;
			addEdge(graph, s, d); // assuming that all nodes value are unique
	}

	// print(graph);

	cout<<detectCycle(graph);

	return 0;
}