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

short dayname(dates d1) {

	short a, y, m, d;

	a = (14 - d1.month) / 12;
	y = d1.year - a;
	m = d1.month + (12 * a) - 2;
	d = (d1.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}


string backday(dates d) {

	string days[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};

	return "\n\ntoday is " + days[dayname(d)] + ", " + to_string(d.day) + "/" + to_string(d.month) + "/" + to_string(d.year);

}

string checkifendofweek(dates s) {

	cout << "\nis it end of week? \n";

	return dayname(s) == 6 ? "yes its end of week" : "not its not end of week";

}

string checkifweekend(dates s) { 

	cout << "\nis it weekend? \n";

	return (dayname(s) == 6 || dayname(s) == 5) ? "yes it is weekend" : "no not weekend";


}

string checkifbussinesday(dates s) {

	cout << "\nis it business day \n";

	return  (dayname(s) == 6 || dayname(s) == 5) ? "no it not business day" : "yes its business day";


}

short howmanydaystellendofweek(dates d) {

	short whatday = 6 - dayname(d);


	return whatday;
}

short howmanydaystellendofmonth(dates d, bool encludingendday) {

	short month = bringdaysofmonth(d.year, d.month);

	short tellendofmonth = month - d.day;


	return encludingendday ? ++tellendofmonth :tellendofmonth;
}


short howmanydaystellendofyear(dates d, bool encludingendday) {
	short days = 0;
	while (!(d.day ==31 && d.month == 12)) {

		if (d.day == bringdaysofmonth(d.year, d.month)) {

			d.day = 1;

			if (d.month == 12) {
				d.year++;
				d.day = 1;
				d.month = 1;
			}
			else {
				d.month++;
			}
		}
		else {
			d.day++;
		}

		days++;

	}
	
	return encludingendday ? ++days:days; 
}


int main()
{
	
	dates ask = askuser();

	cout << backday(ask) << endl;

	cout << checkifendofweek(ask) << endl; 
	cout << checkifweekend(ask) << endl;
	cout << checkifbussinesday(ask) << endl; 
	cout << "\ndays until end of week is: " << howmanydaystellendofweek(ask) << "Day(s). " << endl;
	cout << "days until end of month is: " << howmanydaystellendofmonth(ask,true) << "Day(s). " << endl;
	cout << "days until end of year is: " << howmanydaystellendofyear(ask,true) << "Day(s). " << endl; 

}
 