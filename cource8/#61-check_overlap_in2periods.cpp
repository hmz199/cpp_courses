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


short length(period p1, bool encldeendday = false) {

	short length = 0;
	while (!datesequal(p1.startdate, p1.enddate)) {


		if (p1.startdate.day == bringdaysofmonth(p1.startdate.year, p1.startdate.month)) {

			p1.startdate.day = 1;

			if (p1.startdate.month == 12) {

				p1.startdate.year++;
				p1.startdate.month = 1;
			}
			else {

				p1.startdate.month++;

			}
		}
		else {
			p1.startdate.day++;
		}

		length++;
	}

	return encldeendday ? ++length : length;
}


bool isoverlap(period p1, period p2) {

	return (compare(p2.enddate, p1.startdate) != comparedates::before) && (compare(p2.startdate, p1.enddate) != comparedates::after);
}

bool checkdateinperiod(dates d1, period p) {

	return (compare(d1, p.startdate) != comparedates::before) && (compare(d1, p.enddate) != comparedates::after);
}

int overlapdaysdays(period p1, period p2) {

	int co = 0;

	if (!isoverlap(p1, p2)) {
		return 0;
	}

	dates current = compare(p1.startdate, p2.startdate) == comparedates::before ? p2.startdate : p1.startdate; 
	dates end = compare(p1.enddate, p2.enddate) == comparedates::before ? p1.enddate : p2.enddate;

	while (compare(current, end) != comparedates::after ) { 
		co++;
		current = increaseDateby1day(current);
	}
	

	return co;
}


int main()
{
	
	cout << "enter perios1 \n";
	period p1 = askuser();
	cout << "\nenter period2 \n";
	period p2 = askuser();


	cout << "overlap days count is: " << overlapdaysdays(p1, p2);
	
}
 