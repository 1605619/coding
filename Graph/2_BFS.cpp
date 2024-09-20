#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

void addEdge(vvi &graph, int s, int d) {
	graph[s].push_back(d);
	graph[d].push_back(s);
}

void bfs(vvi graph, int start) {
	int visited[100] = {0};

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		cout<<curr<<" ";

		for (int i=0;i<graph[curr].size();i++) {
			if (visited[graph[curr][i]] == 0) {
				visited[graph[curr][i]] = 1;
				q.push(graph[curr][i]);
			}
		}
	}
}

void dfs(vvi graph, int start) {
	int visited[100] = {0};

	stack<int> s;
	s.push(start);
	visited[start] = 1;

	while (!s.empty()) {
		int curr = s.top();
		s.pop();

		cout<<curr<<" ";

		for (int i=0;i<graph[curr].size();i++) {
			if (visited[graph[curr][i]] == 0) {
				visited[graph[curr][i]] = 1;
				s.push(graph[curr][i]);
			}
		}
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif

	int n,s,d;
	cin>>n;

	vvi graph(n+1);

	for (int i=0;i<n;i++) {
		cin>>s>>d;
		addEdge(graph, s, d);
	}

	dfs(graph, 1);
	
	return 0;
}