

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;






int readnum() {

	int num; 
	do
	{
		cout << "enter postive nums to reverse";
		cin >> num;

	} while (num <= 0);

	return num; 
}

void printreverse(int num) {
	int re;
	int rev = 0;

	while (num > 0) {
		re = num % 10; //5
		num = num / 10; //1234 - 5
		rev = rev * 10 + re; //rev here we store numbers in reverse 5 4 3 2 1

	}
	cout << rev;

}



int main()
{ 
    
	

	  printreverse(readnum());

    return 0;
}








