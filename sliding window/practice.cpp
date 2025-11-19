#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

void testMultiset(vi nums) {
	multiset<int> m;

	for (int i=0;i<nums.size();i++) {
		m.insert(nums[i]);
	}

	for (int ele : m) {
		cout<<ele<<" ";
	}

	cout<<endl;

	// Code equalent to
	for (auto it = m.begin(); it != m.end(); it++) {
		cout<<*it<<" ";
	} 

	cout<<endl;

	cout<<*m.begin()<<", "<<*m.rbegin();

	m.erase(m.find(4));

	cout<<endl;

	for (auto it = m.begin(); it != m.end(); it++) {
		cout<<*it<<" ";
	} 
	
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vi nums = {5,4,5,3,4,2,4};
	testMultiset(nums);

	return 0;
}
