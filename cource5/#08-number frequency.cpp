

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;








unsigned long long readnum(string mass) { 
	unsigned long long num;
	do
	{
		cout << mass; 
		cin >> num; 

	} while (num <=0); 

	return num; 
}

void printfreq(int frq, int num) {
	int co = 0;
	int re = 0;
	while (num > 0) {
		re = num % 10;
		num = num / 10;
		if (frq == re) {
			co++;
		}
	}
	cout << "diget " << frq << "frequncy is " << co;
}




int main()
{ 
    
	

	int diget = readnum("enter the diget ");
	int frq = readnum("enter the the number you want to check frequncy of it ");

	printfreq(frq, diget);

    return 0;
}








