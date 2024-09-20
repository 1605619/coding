#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A */

bool predicate(int w, int h, int n, int squareSize) {
	int rectangesInOneRow = squareSize/w;
	int rectangesInOneColumn = squareSize/h;

	// if (rectangesInOneRow * rectangesInOneColumn >= n) return true; // It will go overflow

	// ***IMPORTANTL watch vdo: TLE 11.0 Level 3 Week-2: Binary Search Problem Solving at 1.30 hr

	if (rectangesInOneColumn > 0 && rectangesInOneRow >= ((n + rectangesInOneColumn - 1)/rectangesInOneColumn)) return true;
	else return false;
}

int packingRectangles(int w, int h, int n) {
	int l = 1, r = 1e18, mid = 0;

	int result = 1e18;

	while (l <= r) {
		mid = (l+r)>>1;

		if (predicate(w,h,n,mid)) { // FFFFFFFF...TT'T'TTTT
			result = mid;
			r = mid - 1;
		}
		else { // FFFFFF'F'F...TTTTTTT
			l = mid + 1;
		}
	}

	return result;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int w,h,n;
	cin>>w>>h>>n;

	cout<<packingRectangles(w,h,n);


	return 0;
}