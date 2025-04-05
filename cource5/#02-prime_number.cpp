#pragma warning(disable : 4996) // this warning if the code unsafe and this ignore the warning 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string> // for strings 
#include <vector> //vector library 
#include <cctype> // for string to 
#include <fstream> //to deal with file 
#include <ctime> // for time 
// local librariy 
#include "myInput.h"
#include "randoms.h"
#include "mymath.h"

using namespace std;




enum enprimeornot { prime = 1, notprime = 2 };



int readnum() {

	int num;
	cout << "enter number to ckeck all of hif if prime or not ";
	cin >> num;

	return num;
}

enprimeornot check(int num) {

	if (num <= 1)
		return enprimeornot::notprime;

	
	for (int i = 2; i <= sqrt(num);i++) {

		if (num % i == 0)
			return enprimeornot::notprime;


	}
	return enprimeornot::prime;
}

void print(int num) {

	for (int i = 1;i <= num;i++) { 
		if (check(i) == enprimeornot::prime) { 
			cout << i << endl; 
		}
	}
}

int main()
{ 

	

	print(readnum()); 
	 

    return 0;
}








