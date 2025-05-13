#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;


struct dates {

	int year;
	int month;
	int day;

};

struct period {

	dates startdate;
	dates enddate;
};

enum encomparedates { before = -1, equal_date = 0, after = 1 };

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


dates readdates() {

	dates d;
	d.day = enterday();
	d.month = entermonth();
	d.year = enteryear();

	return d;
}


period askuser() {

	period dates;

	cout << "enter starsd date\n";
	dates.startdate = readdates();
	cout << "\n\nenter end date\n";
	dates.enddate = readdates();

	return dates;
}

bool leapyear(int num) {

	return (num % 400 == 0) ? true : num % 100 == 0 ? false : num % 4 == 0 ? true : false;
}

bool checkdate1less(dates d1, dates d2) {

	return d1.year < d2.year ? true : d1.year == d2.year && d1.month < d2.month ? true : d1.year == d2.year && d1.month == d2.month && d1.day < d2.day ? true : false;
}

bool datesequal(dates d1, dates d2) {

	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;

}

int bringdaysofmonth(int year, int month) {

	return month == 2 ? (leapyear(year) ? 29 : 28) : (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}

encomparedates comparedate(dates d1, dates d2) {

	if (datesequal(d1, d2))
		return encomparedates::equal_date;
	else if (checkdate1less(d1, d2))
		return encomparedates::before;


return encomparedates::after;
}

bool isoverlap(period d1, period d2) {

	if ((comparedate(d2.enddate, d1.startdate) == encomparedates::before) || (comparedate(d2.startdate, d1.enddate) == encomparedates::after))
		return false;
	else
		return true;
}







int main()
{
	
	cout << "period1: \n";
	period p1 = askuser();
	cout << "\n\nperiod1: \n";
	period p2 = askuser();

	if (isoverlap(p1, p2)) {

		cout << "yes its is overlap";
	}
	else {
		cout << "no its not ";
	}
	
}
 