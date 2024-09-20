#include<bits/stdc++.h>
using namespace std;

#define int long long int

/*
	Binary Search on Decimals: Lecture 3 TLE-Level 11.0

	If we need to do BS on decimals:

	1. How many iterations will it take? - log(Search space)
	2. Precision issues?
	3. Ways to tackle

	b/w 3....4 there are infinite decimal answers, unlike integers which is finite like given range is 1 to 10^16. so possible #answrrs = 10^6

	also 1/3 => 0.3333333.....infinte, so how many decimal points to handle?

	Therefore, we need to limit the search space by limiting #decimal places, and it will be mentioned in questions

	"Print the answrr which has relative error of <= 10^(-6) with original answr" -> 

	means:

	(actual) your answr = x
	(expected) original answr = y

	Therefore |x-y| <= 10^(-6) i.e., "y + 10^(-6) >= x >= y - 10^(-6)"

	example;

	expected/original answre: 1.000123123
	actual or your ans: 1.000123 or 1.000124 would be fine, but 1.000122 won't be not as relative error is > 10^(-6)

	Note:

	let's say given search space is 0 to 10^16 and decimals upto 8 decimal points is included

	Then total candidate answers = 10^16 * 10^8 => 10^24

	Hence: O(Log(Search Space)) => O(log(10^24))


*/

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n;

	return 0;
}