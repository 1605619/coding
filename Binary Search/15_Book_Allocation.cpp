#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://www.naukri.com/code360/problems/allocate-books_1090540 */



int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,m,d;
	cin>>n>>m;

	int arr[1000000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		arr[i] = d;
	}

	cout<<bookAllocation();

	return 0;
}