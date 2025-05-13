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

	cout << "enter starsd date\n\n";
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


enum comparedates { before = -1, equal = 0, after = 1 };


comparedates compare(dates d1, dates d2) {

	if (datesequal(d1, d2))
		return comparedates::equal;
	else if (checkdate1less(d1, d2))
		return comparedates::before;
	else
		return comparedates::after;
}



bool checkdateinperiod(dates d1, period p) {

	return (compare(d1, p.startdate) != comparedates::before) && (compare(d1, p.enddate) != comparedates::after);
}



int main()
{
	
	cout << "enter perios \n";
	period p1 = askuser();
	cout << "\nenter date to check \n";
	cout << endl;
	dates d = readdates();

	if (checkdateinperiod(d, p1)) {
		cout << "yes, date is within period";
	}
	else {
		cout << "no its not with in perios";
	}

}
 