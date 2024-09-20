#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif	
	
	// [[2,4],[1,3],[2,4],[1,3]]

	int size, node1, node2;
	cin>>size;

	int graph[1000][1000] = {{0}}; // SC: O(N^2) - not a good SC

	int max = 0;

	for (int i=0;i<size;i++) {
		cin>>node1>>node2;

		max = max < node2 ? node2 : max;
		max = max < node1 ? node1 : max;

		graph[node1][node2] = graph[node2][node1] = 1;
	}

	for (int i=0;i<=max;i++) {
		for (int j=0;j<=max;j++) {
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}


	// Adj lists

	vector<int> adj[size+1]; // i.e., array of vectors & SC: O(2*E) i.e., twice of #edges i.e., a lot less

	int edges;
	cin>>edges;

	for (int i=0;i<edges;i++) {
		cin>>node1>>node2;

		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}

	for (int i=0;i<size+1;i++) {
		cout<<i<<": ";
		for (auto x: adj[i]) {
			cout<<x<<" ";
		}
		cout<<endl;
	}


	return 0;
}