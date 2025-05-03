#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;


int enteryear() {

	int year;
	cout << "please enter year? ";
	cin >> year;


	return year;
}

int entermonth() {

	int month;
	cout << "please enter month? ";
	cin >> month;


	return month; 
}

int enterday() {

	int day;
	cout << "please enter day? ";
	cin >> day;


	return day;
}

struct dates {

	int year;
	int month;
	int day;
};

dates askuser() {

	dates d;

	d.day = enterday();
	d.month = entermonth();
	d.year = enteryear();

	return d;
}

bool leapyear(int num) {

	return (num % 400 == 0) ? true : num % 100 == 0 ? false : num % 4 == 0 ? true : false;
}

bool checkdate2less(dates d1, dates d2) { 

	return d1.year > d2.year ? true : d1.year == d2.year && d1.month > d2.month ? true : d1.year == d2.year && d1.month == d2.month && d1.day > d2.day ? true : false;
}

bool equal(dates d1, dates d2) {

	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;

}

int bringdaysofmonth(int year,int month) {

	return month == 2 ? (leapyear(year) ? 29 : 28) : ( month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31 ;
}

dates increaseDateby1day(dates d1) {

		if (d1.day == bringdaysofmonth(d1.year, d1.month)) {

			if (d1.month == 12) {

				d1.day = 1;
				d1.month = 1;
				d1.year++;
			}
			else {
				d1.day = 1;
				d1.month++;
			}

		}
		else {
			d1.day++;
		}

	
	return d1; 

}

dates increaseDateby10daya(dates d1) {

	for (int i = 1; i <= 10; i++) {

		d1 = increaseDateby1day(d1);
	 }

	return d1;
}

dates increaseDateby1week(dates d1) {

	for (int i = 1; i <= 7; i++) {

		d1 = increaseDateby1day(d1);
	}

	return d1;
}

dates increaseDateby10week(dates d1) {

	for (int i = 1; i <= 10 ; i++) { 

		d1 = increaseDateby1week(d1); 
	}

	return d1;
}

dates increaseDateby1month(dates d1) { 

	

	if (d1.month == 12) {

		d1.month = 1;
		d1.year++;
	}
	else {
		d1.month++;
	}

	int newmonth = bringdaysofmonth(d1.year, d1.month); 

	
	if (d1.day > newmonth) {
		d1.day = newmonth; 
	}

	return d1;
}

dates incresedatebyXmonth(dates d1,short month) {

	for (int i = 1; i <= month; i++) {

		d1 = increaseDateby1month(d1);
	}

	return d1; 
}

dates incresedateby1year(dates d1) {

	d1.year++;

	return d1;
}

dates incresedatebyXyear(dates d1,short years) {

	for (int i = 1; i<= years; i++) {

		d1 = incresedateby1year(d1); 
	}

	return d1;
}
dates incresedatebyXyearfaster(dates d1) { 

	d1.year += 10;

	return d1;
}

dates incresedatebydecade(dates d1) {

	d1.year += 10;

	return d1;
}

dates incresedatebyXdecade(dates d1,short decades) {

	for (int i = 1; i <= decades; i++) {

		d1 = incresedatebydecade(d1);
	}

	return d1;
}

dates incresedatebyXdecadefaster(dates d1, short decades) {

	d1.year += 10 * decades;
	return d1;
}

dates incresedatebycentury(dates d1) {

	d1.year += 100;
	return d1;
}

dates incresedatebymillennium(dates d1) { 

	d1.year += 1000;
	return d1;
}

int main()
{
	
	dates d = askuser(); 
	dates d1 = increaseDateby1day(d); 
	
	cout << "01-adding ony day is: " << d1.day << "/" << d1.month << "/" << d1.year << endl; 
	d1 = increaseDateby10daya(d1);
	cout << "02-adding ten days is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = increaseDateby1week(d1);
	cout << "03-adding 1 week is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = increaseDateby10week(d1);
	cout << "04-adding 10 week is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = increaseDateby1month(d1);
	cout << "05-adding 1 month is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebyXmonth(d1,5);
	cout << "06-adding 5 month is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedateby1year(d1);
	cout << "07-adding 1 year is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebyXyear(d1,10);
	cout << "08-adding 10 year is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebyXyearfaster(d1);
	cout << "09-adding 10 year faster is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebydecade(d1);
	cout << "010-adding decade faster is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebyXdecade(d1,10);
	cout << "011-adding 10 decade : " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebyXdecadefaster(d1,10);
	cout << "012-adding 10 decade faster is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebycentury(d1);
	cout << "013-adding century is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = incresedatebymillennium(d1);
	cout << "014-adding millennium is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;

}

 