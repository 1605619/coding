#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* Prateek Narang: Finding Roots problem

Given an integer N and an integer P, you need to find the square root of 
number N upto P places. Do it without using STL 

*/

/* 
	Monotonic search space i.e., N = 10, P = 3

	let's say search space is 1 to 10
	
	l       m          r
	1,2,3,4,5,6,7,8,9,10
	T T T F F F F F F F

	Therefore, l = 0, r = 9 and mid = 5

	5^2 => 25 > 10 => F

	Therefore, search space: 0 to 4, mid = 2

	2^2 => 4 <= 10 => T

	Therefore, true for: 1^2 => 1 <= 10 this as well and any element on left
 */

// For N=10, P=3, we find '3' as output of this function
// O(LogN) & O(1), Note: we could also find root using while (i^2 <= 10) but this would have taken O(sqrt(N)), but O(LogN) is better
// this can also be done using BS on answer, using monotonic TTTTTFFFF and predicate func(), refer: TLE: Week-2: Binary Search Problem Solving
int findRoot(int n) {
	int l = 1, r = n/2, mid = 0; 
	// Note: Here monotonous search space is: 1,2,3,4,5 because 10/2 = 5, because, sqrt(N) < N/2

	int root = 0;

	while (l <= r) {
		mid = l + (r-l)/2;

		if (mid*mid <= n) { // T i.e, left part of monotonic array would also be True, so lets explore right part
			root = max(root, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return root;
}

// Linear Search: O(9) as for each decimal place we can check for 9 times i.e., 3.0 to 3.9
// We could do it using BS also, but time complexity is constant here also easier to implement
float decimalRoot(float root, float decimal, int n) {
	int i = 0;

	for (i=0;i<=9;i++) {
		if (root*root <=  n) {
			root += decimal;
		} 
		else {
			break;
		}
	}

	return (i-1)*decimal;
}

// TC: O(logN + p*9) & SC: O(1)
float squareRoot(int n, int p) {

	int root = findRoot(n); // Binary Search, therefore: O(logN)
	float decimalValue = 0.1;

	float result = (float)root;

	for (int i=1;i<=p;i++) {
		result += decimalRoot(result, decimalValue, n); // LS: p*O(9)
		decimalValue = decimalValue/10;
	}

	return result;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,p;
	cin>>n>>p;

	cout<<squareRoot(n,p);

	return 0;
}