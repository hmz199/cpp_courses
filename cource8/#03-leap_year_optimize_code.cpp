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

	return num % 400 == 0 ? true : (num % 100 == 0) ? false : num % 4 == 0;

}



int main()
{

	int read = enteryear();

	if (leapyear(read)) 
		cout << "yes its leap";
	else
		cout << "not its not";
   
}

