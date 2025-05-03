#include <iostream>
#include <string>
#include <iomanip>
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

short readday() {

	int year;


	cout << "\n\nplese enter a day to check ";
	cin >> year;


	return year;
}

bool leapyear(int year) {

	return year % 400 == 0 ? true : year % 100 == 0 ? false : year % 4 == 0;
}

int numbermonth(int month,int year) {

	return month == 2 ? (leapyear(year) ? 29 : 28) : month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31;
}


int bringtotalnumberofday(short year,short month,short day) {

	int all = 0;
	for (int i = 1; i < month ; i++) { 

		all += numbermonth(i,year ); 
		
	}

	return all + day ;  
}

int main()
{	
 
	int ready = readyear();

	int readm = readmonth();
	
	short readd = readday();


	cout << "\n\nthe number of days from the begining of year is " << bringtotalnumberofday(ready, readm, readd);
}

