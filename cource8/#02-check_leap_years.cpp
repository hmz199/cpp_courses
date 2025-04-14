#include <iostream>
#include <string>
using namespace std; 


int enteryear() {

	int number;
	cout << "enter a year to check: ";
	cin >> number;

	return number;
}

bool leapyear(int num) {

	if ((num % 400) == 0) {

		return true;
	}
	else if (num % 100 == 0) {

		return false;
	}
	else if ((num % 4) == 0) {
		return true;
	}
	else {
		return false;
	}

}


int main()
{

	int read = enteryear();

	if (leapyear(read)) {
		cout << "yes its leap year";
	}
	else
		cout << "no not leap year";
   
}

