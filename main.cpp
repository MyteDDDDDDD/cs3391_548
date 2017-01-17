#include<iostream>
#include <algorithm> 
#include <stdio.h>
using namespace std;


int main() {
	unsigned long long a, b, sum,temp;
	// the two input numbers ,a for A and b for B, [0,10^38], 
	//read one input first, EOF mark location is after its conceptual location!!!!
	cin >> a;
	while (!cin.eof()) { //detect whether eof, eof needs a primce read to "boostrap" !!! 
		
		/* this one also works
		while(true){
		int a;
		cin>>a;
		if(!cin.eof())
			break;
		cout<<a;
		}
		*/
		cin >> b;
		
		temp = pow(2,floor(log2(b)));
		if (a < temp) {
			sum = 2*temp - 1;
			cout << sum<<endl;
		}
		else {
			sum = b;
			for (unsigned long long i = a; i < b; i++) {
				sum = max(sum, i | (i + 1)); // max() is under <algorithm> header
			}
			cout << sum<<endl;
		}
	
		
		//the largest number appears during counting is actually the result of applying bitwise operation "or" on a and b
		//however bitwise operation could only operate on integral number and input exceeds the range of int type 
		//_int64, unsigned long long supports 8bytes ,range of value is [0,10^18]
		
		cin >> a;
		}
	return 0;
}
