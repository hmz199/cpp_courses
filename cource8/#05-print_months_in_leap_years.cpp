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

		if (times == 0) {

			exit(0);
		}

	} while ((month < 1 || month > 12) && times != 0);


	return month;
}

bool leapyear(int num) {

	return num % 400 == 0 ? true : num % 100 == 0 ? false : num % 4 == 0;
}

short numbersofdaysinmonth(short month,short year) {

	if (month == 2) {

		return leapyear(year) ? 29 : 28;
	}
	

	short monthwith31day[] = { 1,3,5,7,8,10,12 };

	for (int i = 0; i < 7; i++) {

		if (month == monthwith31day[i]) {

			return 31;
		}
	}

	return 30;
	
}
short numbersofhoursinmonth(short month,short year) {

	return numbersofdaysinmonth(month, year) * 24;
}
int numbersofminutesinmonth(short month, short year) {

	return numbersofhoursinmonth(month, year) * 60;
}
int numbersofsecondsinmonth(short month, short year) {

	return numbersofminutesinmonth(month, year) * 60;
}

void printnumbers(int month , int year) {

	cout << "number of days     in month [" << month << "] is " << numbersofdaysinmonth(month, year) << endl;
	cout << "number of days     in month [" << month << "] is " << numbersofhoursinmonth(month, year) << endl;
	cout << "number of days     in month [" << month << "] is " << numbersofminutesinmonth(month, year) << endl;
	cout << "number of days     in month [" << month << "] is " << numbersofsecondsinmonth(month, year) << endl; 




}

int main()
{
	short ready = readyear();
	short readm = readmonth();

	printnumbers(readm,ready); 

	
	
   
}

