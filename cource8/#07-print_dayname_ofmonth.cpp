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

short readday() {
	short day;
	cout << "\n\nplese enter a day ";
	cin >> day;

	return day;
}

string date(short year,short month,short day) {

	return to_string(day) + "/"  +to_string(month) + "/" +to_string(year);
}

short dayorder(short year, short month, short day) {

	short a, y, m, d;

	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string dayname(short day) {

	string days[] = { "sun","mon","tue","wed","thurs","friday","saturday" };

	return days[day];
}

void printdayname(short year, short month, short day) {

	cout << "\n\ndate " << date(year, month, day) << endl; 
	cout << "day order " << dayorder(year, month, day) << endl; 
	cout << "day name " << dayname(dayorder(year, month, day)) << endl; 
}




int main()
{

	short ready = readyear();
	short readm = readmonth();
	short readd = readday();

	printdayname(ready, readm, readd);
	
}

