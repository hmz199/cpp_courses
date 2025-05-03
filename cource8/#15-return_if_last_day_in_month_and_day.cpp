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

string statusday( int day,int y,int m) {

	int month = returndayofmonth(y, m);

	return day == month ? "yes, month is last month in year " : "no, the month is not the last month ";
	
	}

string statusmonth(int month) { 

	if (month == 12) { 
		return "yes, month is last month in year ";
	}
	else {
		return "no, the month is not the last month ";
	}

}

int main()
{
	int y = enteryear();
	int d = enterday();
	int m = chosemonth();

	cout << statusday(d,y,m) << endl;  
	cout << statusmonth(m) << endl;  

	return 0;
}

