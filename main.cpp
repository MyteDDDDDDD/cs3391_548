#include<iostream>
using namespace std;

int main(){
	_int64 a,b,sum; // the two input numbers ,a for A and b for B, [0,10^38], 
				//10^38 is the max of float type
	sum = 0;
	cin >> a >> b;
	//the largest number appears during counting is actually the result of applying bitwise operation "or" on a and b
	//however bitwise operation could only operate on integral number and input exceeds the range of int type 
	//_int64 supports [0,10^18]
	for(_int64 i=a;i<b;i++){
		sum =max(sum, i| b);
	}
	cout << sum<<endl;
	return 0;
}
