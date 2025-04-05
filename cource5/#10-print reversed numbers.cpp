

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;






int readnum() {
	int num;
	cout << "enter diget to print ";
	cin >> num;

	return num; 
}

int rev(int num) {
	int re = 0;
	int rev = 0;

	while (num > 0) {
		re = num % 10;
		num = num / 10;
		rev = rev * 10 + re; 

	}
	return rev;
}

void print(int num) {

	int re = 0;
	while (num > 0) {
		re = num % 10;
		num = num / 10;

		cout << re << endl;  
	}
}



int main()
{ 
    
	

	print(rev(readnum()));
	 

    return 0;
}








