#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/median-of-two-sorted-arrays/description/ */

/*
	Three ways to solve I guess:
	1. Brute force - 2 pointers => O(n+m)
	2. Binary Search => O(log(n+m))
	3. Heap
*/ 

// O(N+M), O(N+M). Note: we can improve SC to O(1) by using variables instead of array
long double bruteForce(int n, int nums1[], int m, int nums2[]) {
	if (n == 0 && m == 0) return 0;

	int i=0, j=0;

	int nums3[2000] = {0}, k = 0;

	while (i < n && j < m) {
		if (nums1[i] <= nums2[j]) {
			nums3[k] = nums1[i];
			i++;
			k++;
		}
		else {
			nums3[k] = nums2[j];
			j++;
			k++;
		}
	}

	while (i < n) {
		nums3[k] = nums1[i];
		i++;
		k++;
	}

	while (j < m) {
		nums3[k] = nums2[j];
		j++;
		k++;
	}
	if ((n+m)%2 == 0) { //even
		int mid = (n+m)/2 - 1; // based on 0th index
		return (nums3[mid] + nums3[mid+1])/2.0;
	}
	else {
		return nums3[(n+m)/2];
	}
}

// 0,1
// 1,0
// 1,1
// 1,2 -> 
// 2,1

bool checkMid(int n1, int nums1[], int n2, int nums2[], int n1_elements, int n2_elements) {
	if (n2_elements >= 0 && nums2[n2_elements - 1] >= nums1[n1_elements]) return false;

	if (n1_elements >= 0 && nums1[n1_elements - 1] >= nums2[n2_elements]) return false;

	return true;
}

int getMedian(int n1, int nums1[], int n2, int nums2[], int n1_elements, int n2_elements) {
	int left = 0, right = 0;

	if ((n1+n2)%2 == 1) {
		if (n1 == 0) return nums2[n2_elements];
		if (n2 == 0) return nums1[n1_elements];
		return min(nums1[n1_elements], nums2[n2_elements]);
	}
	else {
		if (n1 == 0) {
			return nums2[n2_elements-1] + 
		}
	}


	return 0;
}

int binarySearch(int n1, int nums1[], int n2, int nums2[]) {
	if (n1 == 0 && n2 == 0) return 0;

	int mid = (n1 + n2)/2;

	// 1 2
	// 1 2 3 4
	// 1 2 3 4 5

	int n1_elements = 0, n2_elements = mid;

	while (n1_elements <= mid) {
		if (checkMid(n1,nums1,n2,nums2,n1_elements,n2_elements)) {
			break;
		}
		n1_elements++;
		n2_elements--;
	}

	if ((n1+n2)%2 == 1) {
		return min(nums1[n1_elements], nums2[n2_elements]);
	}


	return 0;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,m,d;
	cin>>n>>m;

	int nums1[1000] = {0}, nums2[1000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		nums1[i] = d;
	}

	for (int i=0;i<m;i++) {
		cin>>d;
		nums2[i] = d;
	}

	// cout<<bruteForce(n,nums1,m,nums2)<<endl;

	cout<<binarySearch(n,nums1,m,nums2);



	return 0;
}