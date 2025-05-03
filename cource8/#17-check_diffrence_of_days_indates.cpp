#include <iostream>
#include <string>
#include <iomanip>
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

	return d1.year < d2.year ? true : d1.year == d2.year && d1.month < d2.month ? true : d1.year == d2.year && d1.month == d2.month && d1.day < d2.day;
}

bool equal(dates d1, dates d2) {

	return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;

}

int bringdaysofmonth(int year,int month) {

	return month == 2 ? (leapyear(year) ? 29 : 28) : ( month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31 ;
}
int diffrencebetweenyears(dates d1, dates d2, bool includeendday = false) {

	int diff = 0;

	if (checkbigger(d2, d1)) {
		dates temp = d1; 
		d1 = d2;
		d2 = temp;
	}

	while (!equal(d1, d2)) {

		if (d1.day == bringdaysofmonth(d1.year, d1.month)) {

			d1.day = 1;
			if (d1.month == 12) {

				d1.month = 1;
				d1.year++;
			}
			else
			{
				d1.month++;
			}
		}
		else {
			d1.day++;
		}

	diff++;
	}

	return includeendday ? ++diff : diff; 
}

int main()
{

	dates d1 = askuser();
	cout << endl;
	dates d2 = askuser(); 

	cout << "\nDiffrence is: "
		<< diffrencebetweenyears(d1, d2) << " Day(s)."; 
	cout << "\nDiffrence (Including End Day) is: "
		<< diffrencebetweenyears(d1,d2,true)  << " Day(s).";
	
}

