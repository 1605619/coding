#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvc vector<vector<char>>
#define vvi vector<vector<int>>

/*	
	store shape in some DS:

	1. YES: sets - balanced BST - sorted & unique: <pair<int,int>>
		- O(logN) insertion, search, etc

	2. NO: multiset - same as set but duplicated values 
		- we don't need this, as every cell <i,j> will be unique
	
	3. NO: unoredred maps - hashing: <pair<int,int>, bool> or <pair<int,int>, int>
		- avg: O(1), worst: O(N)

	4. NO: unordered_set - hashing: <int> -> unique, unsorted, hash
		- avg: O(1), worst: O(N)

	
	Final DS: set<vector<pair<int, int>>> - set of distinct islands

	We use set instead of hashing, as we need to store unique, and we can't use
	unordered_map<vector<pair<int, int>, int> or unordered_set<vector<pair<int, int>> as we vector is not taken as key inbuilt
*/

void print(vvi grid) {
	int m = grid.size(), n = grid[0].size();

	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			cout<<"("<<i<<","<<j<<")"<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

// Approch 1: using "set<set<pair<int, int>>>" & DFS -> will lead to O(m*n * log(m*n)), as set is balanced BST

// Approch 2: I can improve it further using "set<vector<pair<int, int>>>" because, as I will traverse in same pattern for 
// every island, i.e., right, down, left, up. Hence, BASE of every island is used
// TC will improve to O(m*n * log(#islands)) and #islands can be as n*m?

/*
	
	example:

	0 1 0 0 0
	1 1 0 0 0
	0 0 0 1 1
	0 0 0 1 0
	
	Here, for island 1, I've base as (0,1), traversal: (0,1) -> (1,1) -> (1,0)
	And we store {(0-0,1-0),(1-0,1-0),(1-0,0-1)} => {(0,1),(1,1),(1,-1)} in set

	for island 2, I've base as (0,1), traversal: (2,3) -> (2,4) -> (3,3)
	we store {(2-2,3-3), (2-2,4-3), (3-2,3-3)} => {(0,0),(0,1),(1,0)} in set

	both are different islands, as shape determined by vector + movement

*/

set<pair<int, int>> island; // use vector<pair<int, int>>

// TC: O(m*n*log(m*n)), SC: O()
void dfs(vvi &grid, vvi &visited, int i, int j, pair<int, int> base) {
	int m = grid.size(), n = grid[0].size();

	if (i < 0 || j < 0 || i >= m || j >= n) return;
	if (grid[i][j] == 0 || visited[i][j] == 1) return;

	visited[i][j] = 1;
	island.insert({i - base.first,j - base.second});

	int move[5] = {0,1,0,-1,0};

	for (int k=0;k<4;k++) {
		dfs(grid, visited, i+move[k], j+move[k+1], base);
	}
}

int numDistinctIslands(vvi& grid) {
    int m = grid.size(), n = grid[0].size();

    set<set<pair<int, int>>> distinct; // use "set<vector<pair<int, int>>>" for better TC
    vvi visited(m, vector<int>(n, 0));

   	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (grid[i][j] == 1  && visited[i][j] == 0) {
				dfs(grid, visited, i, j, {i,j});
				distinct.insert(island);
				island.clear();
			}
		}
	}

	return distinct.size();
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

	cout<<"Distinct Islands: "<<numDistinctIslands(grid);

	return 0;
}