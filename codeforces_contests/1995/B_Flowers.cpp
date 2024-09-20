#include<bits/stdc++.h>
using namespace std;

#define uii unordered_map<int, int>
#define int long long int

bool diffChecker(uii umap, int petals) {
	for (auto x: umap) {
		if (abs(x.first - petals) > 1) return false;
	}
	return true;
}

int totalPetals(uii umap) {
	int count = 0;

	for (auto x: umap) {
		count += x.first * x.second;
	}

	return count;
}

int dp[200000] = {-1};

int bouquet(int i, int n, int m, int petals[], uii umap) {
	if (i == n) return totalPetals(umap);

	if (dp[i] != -1) return dp[i];

	int count = bouquet(i+1,n,m,petals,umap); // did not take it

	// if total <= m && diff <= 1
	if ((totalPetals(umap) + petals[i]) <= m && diffChecker(umap, petals[i])) {
		umap[petals[i]]++;
		count = max(count, bouquet(i+1,n,m,petals,umap));
	}
	return dp[i] = count;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif

	int t;
	int n,m,d;
	cin>>t;

	for (int test = 1; test <= t; test++) {
		cin>>n>>m;

		memset(dp, -1, sizeof(dp));

		int petals[200000]= {0};

		for (int i=0;i<n;i++) {
			cin>>d;
			petals[i] = d;
		}

		uii umap;

		cout<<bouquet(0, n, m, petals, umap)<<endl;
	}
	
	return 0;
}