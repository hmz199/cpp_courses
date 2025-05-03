#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



int enteryear() {

	int number;
	cout << "enter a year ";
	cin >> number;

	return number;
}

int chosemonth() {

	int number;
	cout << "enter a month ";
	cin >> number;

	return number;
}

int enterday() {

	int number;
	cout << "enter a day  ";
	cin >> number;

	return number;
}
int addingday() {

	int number;
	cout << "enter how many days to add ";
	cin >> number;

	return number;
}

struct dates {

	int year;
	int month;
	int day;
};
dates ask() {

	dates d;

	d.year = enteryear();
	d.month = chosemonth();
	d.day = enterday();


	return d;
}

bool  checkleapyear(int num) {

	return num % 400 == 0 ? true : num % 100 == 0 ? false : num % 4 == 0 ? true : false;
}



int returndayofmonth(int year, int month) {

	return (month == 2) ? (checkleapyear(year) ? 29 : 28) : (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31;
}


int totaldaysofyear(int year, int month, int day) {

	int totaldays = 0;
	for (int i = 1; i < month; i++) {

		totaldays += returndayofmonth(year, i);
	}

	return totaldays + day;
}

dates increseoneday(dates da) {
	
	
	int monthhh = returndayofmonth(da.year, da.month);  


	if (da.day == monthhh) {

		da.day = 1;

		if (da.month == 12) {
		
			da.month = 1;
			da.year++;
		}
		else {
			da.month++;
		}

	}
	else {
	
		da.day++;
	}

	return da;  
}

int main()
{

	
	dates da = ask();

	dates d = increseoneday(da); 
	cout << "date after adding one day is: " << d.day << "/" << d.month << "/" << d.year << endl;

	return 0;
}

