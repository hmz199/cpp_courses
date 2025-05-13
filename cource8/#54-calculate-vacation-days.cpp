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


string daynamewithdate(dates d) {  

	string days[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};

	return days[dayname(d)] + ", " + to_string(d.day) + "/" + to_string(d.month) + "/" + to_string(d.year);

}

string checkifendofweek(dates s) {

	cout << "\nis it end of week? \n";

	return dayname(s) == 6 ? "yes its end of week" : "not its not end of week";

}

string checkifweekend(dates s) { 

	cout << "\nis it weekend? \n";

	return (dayname(s) == 6 || dayname(s) == 5) ? "yes it is weekend" : "no not weekend";


}

bool checkifbussinesday(dates s) {


	return !(dayname(s) == 6 || dayname(s) == 5);

}

void vacationdate(dates d1, dates d2) { 

	cout << "vacation from: " << daynamewithdate(d1) << endl;
	cout << "vacation from: " << daynamewithdate(d2) << endl;
}

short vactiondays(dates d1,dates d2) {

	int vacation = 0; 
	while (!equal(d1, d2)) {


		if (checkifbussinesday(d1)) {

			vacation++; 
		}

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

		
	}

	return vacation;
}

int main()
{
	
	cout << "vacation starts: \n";
	dates d1 = askuser();
	cout << "\n\nvaction ends: \n";
	dates d2 = askuser();
	 
	cout << endl; 
	vacationdate(d1, d2); 

	cout << "\n\nactual vcation days is: " << vactiondays(d1, d2);   

}
 