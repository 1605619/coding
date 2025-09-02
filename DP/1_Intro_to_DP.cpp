#include<bits/stdc++.h>
using namespace std;

#define int long long int

/*
	Divide and Conquer

	If we have a quite big problem, we can try to divide it into smaller sub-problems.
	So if we have a problem 'P', then it will be divided into problems 'P1' and 'P2'.
	But only dividing the problem into sub-problems is not enough, we also need to learn to use P1 and P2 result to get answer for 'P'.
	So if 'x' is solution from 'P1' and 'y' is the solution from 'P2', then we should get be able to combine 'x' and 'y' to get the answer for 'P'.

	We will keep dividing the problem into sub-problems and so on.. until we reach at a `trivial sub-problem`. 
	i.e., now we can't further divide it or we already know answer to that or very easy to find it.

	Example: 
	Array[] = {1,2,3,4,5,6,7,8}
	We need to find the sum of the array without using the for loop.

	sum(1,2,3,4,5,6,7,8) => sum(1,2,3,4) and sum(5,6,7,8)

	sum(1,2,3,4) => sum(1,2) and sum(3,4)
	sum(5,6,7,8) => sum(5,6) and sum(7,8)

	now sum(1,2) need not to be further divided, as we can easily add these.

	sum(1,2) gives: 1+2 = 3
	sum(3,4) gives: 3+4 = 7
	so on..


	Now it depends upon how we use 'x' and 'y', here we can add it. 

	Problem 1: Fibonacci Number
	Find nth Fibonacci Number. 
	1,1,2,3,5,8,...


*/

int functionEntered = 0;

int fibonacci(int n) {
	functionEntered++;

	// base condition
	if (n==0) return 0; // O(1)
	if (n==1 || n==2) return 1; // O(1)

	// recusive equation
	return fibonacci(n-1) + fibonacci(n-2); // O(1) Note: Here, it's like O(1) took in adding 'a' and 'b'
	// but `fibonacci(n-1)` and `fibonacci(n-2)` might have taken its own time inside their function call, which we're not counting here.
}

/*
	Hence, TC by 1 function call is O(1)
*/

/*
	Means, TC by 1 function call is O(1)
	And, TC for 1664079 function calls is O(1664079) (or maybe 1664079 * 3 based on number of operations inside each function call)
	Hence, for n = 30, TC: O(1664079), which is lot of work or TC

	Problem here is, that we're having overlapping sub-problems, means we're processing same subproblem multiple times. 
	For f(30), we computed f(28) multiple times. 

	Ideally, we should not be solving overlapping subproblems again and again, to save TC. 
	So we can store the answer like caching and return the stored answer for a subproblem when required.

	**Be very good at dividing the problems using DnQ, cuz if new problem comes up, you should be able to divide it, not just for already seen problems.

	1. How to store data so you can retrieve it very fast? 
		- map? like unordered_maps/hashmap (key value pairs TC: O(1)) or tree map O(logN) - N is the #keys stored in a map


	2. Whether the data is present or not, that is if you have solved this sub-problem before or not?
*/

/*
	What is DP?
	-> We realise that certain type of sub-problems are repeating, and we calculate the answer once and use it whenever needed.

	We think that, DP is about storing the answers to sub-problems, but it's starts with divide and concquer mindset.
*/
int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n=30;
	cout<<fibonacci(n)<<endl;
	cout<<functionEntered; // 1664079, for n=30, tells number of times fibonacci() function was called

	return 0;
}


- trial expiry and aligning with team wrt to suites add-on feature
- data inconsitency 