

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;





int readnum() {
	int num;
	do
	{
		cout << "enter pstive numbers to sum them ";
		cin >> num;

	} while (num <= 0);

	return num; 

}

void printsum(int num) {
	int sum = 0;
	int re = 0;
	while (num > 0) {
		re = num % 10; 
		num = num / 10;
		sum += re;
	}
	cout << "your total is " << sum << endl;
}


int main()
{ 

	 printsum(readnum());

    return 0;
}








