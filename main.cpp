#include<iostream>
using namespace std;

int main(){
	float a,b; // the two input numbers ,a for A and b for B, [0,10^38], 
				//10^38 is the max of float type
	float sum = 0;
	cin >> a >> b;
	//the largest number appears during counting is actually the result of applying bitwise operation "or" on a and b
	//however bitwise operation could only operate on integral number and input exceeds the range of int type 
	//
	sum = a | b; 
	cout << sum<<endl;
	return 0;
}