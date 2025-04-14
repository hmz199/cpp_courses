#include <iostream>
#include <string>
using namespace std; 


int readyear() {

	int year;


	cout << "plese enter a year to check ";
	cin >> year;


	return year;
}

int readmonth() {

	int month;
	short times = 3;

	do
	{
	cout << "\n\nplese enter a month to check from 1 - 12 ";
	cin >> month;

	if (month < 1 || month > 12) {

	--times;
	}
	
	if (times == 0){

		exit(0);
	}

	} while ((month < 1 || month > 12) && times != 0);


	return month; 
}

bool leapyear(int num) {

	return num % 400 == 0 ? true : num % 100 == 0 ? false : num % 4 == 0;
}

short numbersofdaysinmonth(short month,short year) {

	return month == 2 ? leapyear(year) ? 29 : 28 : month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31;

}


void printnumbers(int month , int year) {

	cout << "number of days     in month [" << month << "] is " << numbersofdaysinmonth(month, year) << endl;
}

int main()
{
	short ready = readyear();
	short readm = readmonth();

	printnumbers(readm,ready); 
   
}

