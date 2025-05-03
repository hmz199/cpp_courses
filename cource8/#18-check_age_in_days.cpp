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

bool checkbigger(dates d1, dates d2) {

	return d1.year < d2.year ? true : d1.year == d2.year && d1.month < d2.month ? true : d1.year == d2.year && d1.month < d2.month && d1.day < d2.day;
}

bool equal(dates d1, dates d2) {

	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;

}

int bringdaysofmonth(int year,int month) {

	return month == 2 ? (leapyear(year) ? 29 : 28) : ( month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31 ;
}

dates getrealtime() {
	dates d1;
	time_t now = time(0);  
	tm* ltm = localtime(&now); 

	d1.day = ltm->tm_mday;
	d1.month = ltm->tm_mon + 1; 
	d1.year = ltm->tm_year + 1900; 

	
	return d1; 
}

int diffrencebetweenyears(dates d1,dates realtime) {

	int days = 0;
	while (!equal(d1,realtime)) {  

		if (d1.day == bringdaysofmonth(d1.year, d1.month)) {

			d1.day = 1;

			if (d1.month == 12) {

				d1.month = 1;
				d1.year++;
			}
			else {
				d1.month++;
			}
		}
		else {
			d1.day++;
		}

		days++;
	}
	
	return days;

}

int main()
{

	dates d1 = askuser();

	dates realtime = getrealtime();

	cout << "\nyour ages is : " << diffrencebetweenyears(d1,realtime) << "days(s).";


	
}

