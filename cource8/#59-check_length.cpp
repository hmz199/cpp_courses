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


short length(period p1,bool encldeendday = false) {

	short length = 0;
	while (!datesequal(p1.startdate,p1.enddate)) {


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

	return encldeendday? ++length:length;
}






int main()
{
	
	cout << "period1: \n";
	period p1 = askuser();
	
	cout << "\n\nperios length is :" << length(p1) << endl;
	cout << "perios length is (encluding end date) :" << length(p1, true) << endl;


}
 