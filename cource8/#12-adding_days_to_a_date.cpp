#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 



int chosenumber() {

	int number;
	cout << "enter a year ";
	cin >> number;

	return number;
}

int chosemonth() { 

	int number;
	cout << "enter a number of month ";
	cin >> number;

	return number;
}

int enterday() {

	int number;
	cout << "enter a day of day ";
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

bool  checkleapyear(int num) {

	return num % 400 == 0 ? true : num % 100 == 0 ? false : num % 4 == 0 ? true : false;
}



int returndayofmonth(int year,int month) {

	return (month == 2) ? (checkleapyear(year) ? 29 : 28) : (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31; 
}


int totaldaysofyear(int year,int month,int day) {

	int totaldays = 0;
	for (int i = 1; i < month; i++) {

		totaldays += returndayofmonth(year, i);
	}

	return totaldays + day;  
}

dates bringbackdateafteradd_days(int year,int month , int days, int addingdays) {

	dates d;

	int totaldays = totaldaysofyear(year, month, days) + addingdays;

	d.year = year;
	d.month = 1;

	while (true) {

		int checkmonths = returndayofmonth(d.year, d.month);

		if (totaldays > checkmonths) {

			totaldays -= checkmonths;
			d.month++;

			if (d.month > 12) {
				d.year++;
				d.month = 1;
			}
		}
		else {
			d.day = totaldays;
			break;
		}
	}

	return d;
}




int main() 
{	

	int y = chosenumber(); 
	int m = chosemonth();   
	int d = enterday();  
	int a = addingday();  
	dates da;

	da = bringbackdateafteradd_days(y, m, d, a);

	cout << "date after adding [" << d << "] days is: " << da.day << "/" << da.month << "/" << da.year;

	return 0;
}

