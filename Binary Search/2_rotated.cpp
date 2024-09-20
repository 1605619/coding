#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/search-in-rotated-sorted-array/ */

/*
	Consirdering: array is in incremental order, no two elements are equal
*/

// O(logN) & O(1)
int rotated(int n, int arr[]) {
	int l=0, r=n-1, mid = l + (r-l)/2;

	while (l <= r) {
		mid = l + (r-l)/2;

		if (mid-1 >= 0 && arr[mid-1] > arr[mid]) return mid;

		if (arr[mid] > arr[r]) {
			l = mid + 1;
		} 
		else {
			r = mid - 1;
		}
	}
	return 0;
}

// O(logn) & O(1)
int search(int n, int arr[], int value) {
	int l = 0, r = n - 1, mid = 0;

	    while (l <= r) {
            mid = l + (r-l)/2;

            if (arr[mid] == value) return mid;

            if (arr[l] <= arr[mid]) { // left part if sorted
                if (value >= arr[l] && value <= arr[mid]) { // check if element lies btw sorted range
                    r = mid - 1;
                    continue;
                }
                l = mid + 1; // else probably lies on other part of array
            } else { // right sorted
                if (value <= arr[r] && value >= arr[mid]) { // check if element lies btw sorted range
                    l = mid + 1;
                    continue;
                }
                r = mid - 1; // else probably lies on other part of array
            }
        }

        return -1;
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

	cout<<"Index of pivot: "<<rotated(n,arr)<<endl;
	cout<<"Index of searched element: "<<search(n,arr,value);

	// Other way is, first find pivot index, and then either left or right part of array should contain the element


	return 0;
}