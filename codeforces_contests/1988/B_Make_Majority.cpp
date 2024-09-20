#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://codeforces.com/contest/1988/problem/B */

int countZeros(string s) {
	int count = 0;
	for (int i=0;i<s.length();i++) {
		if (s[i]-48 == 0) count++;
	}

	return count;
}

string removeBunchOfZeros(string s) {
	bool isPreviousZero = false;

	string newS="";

	for (int i=0;i<s.length();i++) {
		if (s[i]-48 == 1) {
			newS.push_back(s[i]);
			isPreviousZero = false;
			continue;
		}

		if (!isPreviousZero) {
			newS.push_back(s[i]);
			isPreviousZero = true;
		}
	}

	return newS;
}

bool isMajority(string s) {
	if (s.length() == 1) return s[0]-48;

	string newString = removeBunchOfZeros(s);

	int zeros = countZeros(newString);
	int ones = newString.length() - zeros;

	if (ones > zeros) return true;

	return false;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int t,n;
	cin>>t;

	string s;

	for (int i=0;i<t;i++) {
		cin>>n;
		cin>>s;

		if(isMajority(s) == 1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}