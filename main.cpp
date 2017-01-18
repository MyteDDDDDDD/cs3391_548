#include<iostream>
#include <algorithm> 
#include <stdio.h>
using namespace std;
bool compare(int i, unsigned long long a) {
	if (a & (1ULL << i)) // bitwise operation, only 1 1 to 1, and the else to 0. if a is 1 at certain i-th bit, return true. use 1i64 as 64-bit integer!!!!!!!
		return true;
	else
		return false;
}

unsigned long long highest_bit_position(unsigned long long x) // binary search strategy, find the highest bit of input
{
	x--;
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	x |= x >> 32;
	x++;
	return x;
}

int main() {
	unsigned long long a, b, sum;

	// the two input numbers ,a for A and b for B, [0,10^38]
	//_int64, unsigned long long supports 8bytes ,range of value is [0,10^18]

	//read one input first, EOF mark location is after its conceptual location!!!!
	cin >> a;
	while (!cin.eof()) { //detect whether eof, eof needs a primce read to "boostrap" !!! 
		cin >> b;
		sum = 0; //initial sum to 0 at every iteration
		int temp = log2(max(highest_bit_position(a), highest_bit_position(b)));
		
		for (int i = temp; i >-1; i--) {
			if (compare(i, a) == compare(i, b)) { // compare a and b from the left-most bit
				if (compare(i, a)) // a and b are the same at that bit, and define sum accordlingly at that bit
					sum |= (1ULL << i);  // bitwise operation "|" ,1 0 to 1 ,0 1 to 1, 1 1 to 1, 0 0 to 0 . used to define sum's i-th bit to 1 here
				else
					sum |= (0ULL << i);
			}
			else {
				for (int j = i; j > -1; j--) { // if a and b are not the same on certain bit, then define all the bits on right hand to 1
					sum |= (1ULL << j);
				}
				break;
			}
		}
		cout << sum << endl;
		cin >> a;
	}
	return 0;
}




