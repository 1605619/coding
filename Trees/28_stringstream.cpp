#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://www.geeksforgeeks.org/stringstream-c-applications/ */

int words(string s) {
	stringstream str(s); // buffer

	cout<<str.str()<<endl; // to print the stream, need to convert it to string type

	string word;

	str>>word; // it stops reading when it encounters whitespace (e.g., spaces, newlines) and then moves the read pointer to the start of the next word.

	cout<<word<<endl;
	cout<<str.str()<<endl;

	str.clear(); // it doesn't reset my read pointer

	//	to reset read read pointer, I can use different approches:

	str.str(str.str()); // Reloads the string, effectively resetting the pointer

	int count = 0; // we haven't read any new word since reset of read pointer

	while (str >> word) // while there are words to be read
	{
		count++;
	}

	cout<<endl<<endl;

	//////////////////// Learning: ////////////////////////////////////

		stringstream temp;

		// '<<' operator to insert data into stream buffer or streambuf
		temp<<"Hello "<<"World!";
		cout<<temp.str()<<endl;

		// if any failures happened like why extracting etc, it will clear those failure flags, such that ss can be re-used
		// it won't clear data of ss
		temp.clear();
		cout<<temp.str()<<endl;

		// '>>' operator to extract/read data from stream buffer
		int number;
		float decimalNumber;
		string words;

		temp.str("-12 -12.12 India"); // update content of temp with new

		temp>>number>>decimalNumber>>words; // Note: when it does ss>>int; it does parsing and reads until non-digit character found, and convert digits into integer

		cout<<number<<", "<<decimalNumber<<", "<<words<<endl;

	////////////////////////////////////////////////////////////

	string binaryTree = "1,2,3,null,null,4,5";

	stringstream BTStream(binaryTree);

	cout<<endl<<endl<<BTStream.str()<<endl;	

	string node;

	getline(BTStream, node, ','); // third parameter is optional, and If I don't pass anything, it will assumne '\n' next line

	// output: 1
	cout<<node<<" "; // it will read until encounters ',' and will store in node variable

	getline(BTStream, node, ',');

	cout<<node<<" "; // 2

	while (getline(BTStream, node, ',')) {
		cout<<node<<" "; // 3 null null 4 5 
	}
	cout<<endl;


	//Note: print in integer format

	string node2;

	stringstream BTStream2(BTStream.str()); // resetting read pointer by storing in a new stream, as probably prev method doesn't work here

	cout<<endl<<endl<<"test: "<<BTStream2.str()<<endl;

	while (getline(BTStream2, node2, ',')) {
		cout<<stoi(node2)<<" "; // fails at 'null', expected as 'null' can't be parsed as int
		// stringToInteger STL
	}
	cout<<endl;

	return count;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	string s = "This is really a bad world!";
	cout<<words(s);

	return 0;
}