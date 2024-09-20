#include<bits/stdc++.h>
using namespace std;

// #define int long long int

/* COUNT FREQUENCY OF ELEMENTS IN A GIVEN SORTED ARRAY */
/*
	Equation of TC in BS:
		T(n) = T(n/2) + O(1)

	We know, that T(1) = O(1) = 1

	Arr: 1,2,3,4,5, search: 5

	mid = 3, at this place we did O(1) operation to check and discarded left half array
	
	Therefore, T(n) = O(1) + T(n/2) 
	=> T(n) = 1 + T(n/2)
	=> T(n) = 1 + 1 + T(n/4)
	=> T(n) = 1 + 1 + 1 + T(n/8)

	i.e.,
	=> T(n) = k + T(n/(2^k))

	As we know, T(1) = 1, let's say T(n/(2^k)) = 1

	for this, n/(2^k) has to be equals to 1

	therefore:

	n/2^k = 1
	=> n = 2^k
	=> logn = log(2^k)
	=> logn = k * log2
	=> k = logn

	Therefore BS: O(logn)
*/

/*

10 1
1 1 1 1 1 2 2 2 5 6

OUTPUT: 5

*/

// Approach 3 (using STL) - check this

int frequency3(int n, int arr[], int value) {
	vector<int> a = {1, 1, 1, 1, 1, 2, 2, 2, 5, 6};
	int upperB = upper_bound(a.begin(), arr.end(), value);
	int lowerB = lower_bound(a.begin(), arr.end(), value);

	if (upperB < 0  || lowerB < 0) return 0;

	return upperB - lowerB + 1;
}


// Approch 2 (Better based on logic)

// LogN & O(1)
int lowerBound2(int l, int r, int arr[], int value) {
	int mid = l + (r-l)/2;
	int minIndex = -1;

	while (l <= r) {
		mid = l + (r-l)/2;

		if (arr[mid] == value) { // Most Important part
			minIndex = mid;
			r = mid - 1; // continue BS on left part of array
		} 
		else if (arr[mid] < value) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return minIndex;
}

// LogN & O(1)
int upperBound2(int l, int r, int arr[], int value) {
	int mid = l + (r-l)/2;
	int maxIndex = -1;

	while (l <= r) {
		mid = l + (r-l)/2;

		if (arr[mid] == value) { // Most Important part
			maxIndex = mid;
			l = mid + 1; // continue BS on right part of array
		} 
		else if (arr[mid] < value) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return maxIndex;
}

int frequency2(int n, int arr[], int value) {
	int upperB = upperBound2(0,n-1,arr,value);
	int lowerB = lowerBound2(0,n-1,arr,value);

	if (upperB < 0  || lowerB < 0) return 0;

	return upperB - lowerB + 1;
}

// Approach 1

// LogN & logN i.e., aux tree space
int lowerBound(int l, int r, int arr[], int value) {
	if (l > r) return -1;

	int mid = l + (r-l)/2; // minimum l + something/zero

	// found state i.e., either first index or left value is smaller
	if (arr[mid] == value && (l == r || arr[mid-1] < value)) { 
		return mid;
	} 
	else if (arr[mid] < value) {
		return lowerBound(mid+1, r, arr, value);
	} 
	return lowerBound(l, mid-1, arr, value);
}

// LogN & logN
int upperBound(int l, int r, int arr[], int value) {
	if (l > r) return -1;

	int mid = (l+r)/2;

	//found state
	if (arr[mid] == value && (l == r || arr[mid+1] > value)) {
		return mid;
	}
	else if (arr[mid] < value) {
		return upperBound(mid+1, r, arr, value);
	}
	return upperBound(mid+1, r, arr, value);
}

int frequency(int n, int arr[], int value) {
	int upperB = upperBound(0,n-1,arr,value);
	int lowerB = lowerBound(0,n-1,arr,value);

	if (upperB < 0 || lowerB < 0) return 0;

	return upperB - lowerB + 1;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,d,value;
	cin>>n>>value;

	int arr[100] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		arr[i] = d;
	}

	cout<<"Frequency: "<<frequency(n, arr, value)<<endl;
	cout<<"Frequency: "<<frequency2(n, arr, value)<<endl;
	// cout<<"Frequency: "<<frequency3(n, arr, value);


	return 0;
}