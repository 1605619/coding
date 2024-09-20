#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B */
// Video: 3 - TLE 11.0 

/* BS on decimals.
	
	Note 1: when dealing with integers we can do:
	while (l <= r) { ... }

	But when we deal with decimal points, let's say:

	0 .... 10^16 & with precision of 10^(-4) i.e., 4 decimal points

	And let's say while doing binary search, we reached when:
	l = 0.0001 and r = 0.0002 

	now, mid = (l+r)/2 i.e., mid = 0.00015

	now if we do, while (l <= r) { ... }, this will lead to issues, bcuz

	when doing division of decimal numbers it can lead to very long values 

	0.0001/2 -> 0.00015/2 -> 0.000125/2 -> 0.0001125 ... so on

	now let's say after mid = 0.00015, now let's say r becomes mid 
	i.e., r = 0.00015

	Therefore, whle (0.0001 <= 0.00015) -> this might keep going on

	Second thing, compter memory will be limited to store a value, probably computer can't store 0.000000000010020003 value

	Therefore dealing with decimals should be done carefully.

	If we change while condn to: while (upperBound - lowerBound > error i.e., 10^(-4)) { ... }

	because: while (LB < UB - error) is same as while (upperBound - lowerBound > error)

	Also we should not do (LB <= UB - error) because '=' again will voilate error scope

	Therefore do: while (UB - LB > error) { ... }

	***Note 2:

	If codeforces ask to give answer for upto 10^(-6) decimal places, to be in safe place
	instead of 6 dec, calculate and return answer with 7 decimal places, i.e., to handle any edge cases
	i.e., dealing with 10 more answer candidates

*/

bool predicate(int n, int ropes[], int k, double maxSize) {
	int count = 0;

	for (int i=0;i<n;i++) {
		count += ropes[i]/maxSize;
	}

	return count >= k;
}

double cutRopes(int n, int ropes[], int k) {
	double l = 0, r = 1e7, error = 1e-7, mid = 0;

	double result = 0; // use double or long double instead of float

	while (r - l > error) {
		mid = (l+r)/2;

		if (predicate(n,ropes,k,mid)) { // TTTTTTT'T'TTT.....FFFF
			result = max(result,mid);
			l = mid + error; // Important - increase by 1e-7
		}
		else {
			r = mid - error;
		}
	}

	return result;
}


int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,k,d;
	cin>>n>>k;

	int ropes[10000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		ropes[i] = d;
	}

	cout<<cutRopes(n,ropes,k);


	return 0;
}







