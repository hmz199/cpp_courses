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

dates decreasedatebyoneday(dates d1) {

	

	if (d1.day == 1) {

		if (d1.month == 1) {

			d1.year--;
			d1.month = 12;
			d1.day = 31;
		}
		else {
			d1.month--;
			d1.day = bringdaysofmonth(d1.year, d1.month);
		}
	}
	else {
		d1.day--;
	}
	
	return d1; 

}

dates decreasedatebytenday(dates d1) {

	for (int i = 1; i <= 10; i++) {

		d1 = decreasedatebyoneday(d1); 
	 }

	return d1;
}

dates decreasedate1week(dates d1) {

	for (int i = 1; i <= 7; i++) {

		d1 = decreasedatebyoneday(d1);
	}


	return d1;
}

dates decreasedate10week(dates d1,short week) {

	for (int i = 1; i <= week ; i++) { 

		d1 = decreasedate1week(d1);
	}

	return d1;
}

dates decreasedate1month(dates d1) {

	

	if (d1.month == 1) {

		d1.month = 12;
		d1.year--;
	}
	else {
		d1.month--;
	}

	int cuurentmonth = bringdaysofmonth(d1.year, d1.month);

	
	if (d1.day > cuurentmonth) {
		d1.day = cuurentmonth;
	}

	return d1;
}

dates decreasedatexmonth(dates d1,short month) { 

	for (int i = 1; i <= month; i++) {

		d1 = decreasedate1month(d1); 
	}

	return d1; 
}

dates decreasedate1year(dates d1) {

	d1.year--;

	return d1;
}

dates decreasedateXyear(dates d1,short years) {

	for (int i = 1; i<= years; i++) {

		d1 = decreasedate1year(d1);
	}

	return d1;
}
dates decreasedatebyXyearfaster(dates d1) {

	d1.year -= 10;

	return d1;
}

dates decreasdatebydecade(dates d1) {

	d1.year -= 10;

	return d1;
}

dates decreasdatebyXdecade(dates d1,short decades) {

	for (int i = 1; i <= decades; i++) {

		d1 = decreasdatebydecade(d1); 
	}

	return d1;
}

dates decreasdatebyXdecadefaster(dates d1, short decades) {

	d1.year -= 10 * decades;
	return d1;
}

dates decreasdatebycentury(dates d1) {

	d1.year -= 100;
	return d1;
}

dates decreasdatebymillennium(dates d1) {

	d1.year -= 1000;
	return d1;
}

int main()
{
	
	dates d = askuser();

	dates d1 = decreasedatebyoneday(d);
	cout << "01-decreas ony day is: " << d1.day << "/" << d1.month << "/" << d1.year << endl; 
	d1 = decreasedatebytenday(d1);
	cout << "02-decreas ten days is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasedate1week(d1); 
	cout << "03-decreas 1 week is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasedate10week(d1,10);
	cout << "04-decreas 10 week is: " << d1.day << "/" << d1.month << "/" << d1.year << endl; 
	d1 = decreasedate1month(d1);   
	cout << "05-decreas 1 month is: " << d1.day << "/" << d1.month << "/" << d1.year << endl; 
	d1 = decreasedatexmonth(d1,5);
	cout << "06-decreas 5 month is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasedate1year(d1);
	cout << "07-decreas 1 year is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasedateXyear(d1,10); 
	cout << "08-decreas 10 year is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasedatebyXyearfaster(d1);
	cout << "09-decreas 10 year faster is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasdatebydecade(d1);
	cout << "010-decreas decade faster is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasdatebyXdecade(d1,10);
	cout << "011-decreas 10 decade : " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasdatebyXdecadefaster(d1,10);
	cout << "012-decreas 10 decade faster is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasdatebycentury(d1);
	cout << "013-decreas century is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;
	d1 = decreasdatebymillennium(d1);
	cout << "014-decreas millennium is: " << d1.day << "/" << d1.month << "/" << d1.year << endl;

}

 