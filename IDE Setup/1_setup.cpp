#include<bits/stdc++.h>
using namespace std;

#define int long long int

/*
	1. https://www.youtube.com/watch?v=Fql_b-xZYwQ&t=116s - takeuforward setting sublime text
	
	2. #define ll long long int -> not recommended to alias it with 'll' in interviews, instead do with 'int'
	Now, you will have to change from 'int main()' to 'int32_t main()' as now int points to long long int
	
	int vs int32_t ? - int is not standardized accross platforms, but int32_t is. i.e.,
	int's size (bytes) can differ accross combinations of H/W and OS environments like Windows x64 vs Windows x86

	But, int32_t will have exact same size i.e., 4 bytes across all platforms i.e., -2^31 to 2^31-1

	#define int long long int -> done to avoid unforseen errors in interviews like value going out of range of int

	3. Build snippet: Tools > Developer -> New Snippet
	Now I place boiler plate code between CDATA[...HERE...], and saves files as cp.sublime-snippet
	And, <tabTrigger>cp</tabTrigger> uncomment it and make it trigger on 'cp'

	Refer Video 7. Using Macros by Apaar Kamal on Udemy DP course by Prateek Narang for this snippet thing if stuck
	Refer Video 8. Example Code, is also good for tricks and make your coding thing look cool
*/

/*
	int -> 4 bytes i.e., Approx -2*10^9 to 2*10^9
	unsigned int -> 4 bytes i.e., Approx 0 to 4*10^9
	long long int -> 8 bytes i.e., Approx -9*10^18 to 9*10^18
	unsigned ll int -> 8 bytes i.e., Approx 0 to 18*10^18

	Trick to remember: 4 bytes - 9 power, 8 bytes double i.e., 18 power
*/

int32_t main() { // int32_t is actually int just standardized by library across platforms
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n; // long long int i.e., 8 bytes & range is -2^63 to 2^63-1
	cin>>n;
	cout<<n+n;

	int m = 1e18;
	cout<<endl<<m;

	for (int i = 0; i < count; ++i)
	{
		/* code */
	}

	return 0;
}