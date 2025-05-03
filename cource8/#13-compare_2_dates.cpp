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
	cout << "enter a month ";
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
dates ask() { 

	dates d;

	d.year =chosenumber();
	d.month =chosemonth();
	d.day = enterday(); 
	

	return d;
}

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

bool checkbiggeryear(dates d1, dates d2) {

	return (d1.year < d2.year) ? true 
			: (d1.year == d2.year && d1.month < d2.month) ? true
			: (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) ? true : false;
}

bool checkequal(dates d1, dates d2) {
	return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day); 
}


int main() 
{	

	/*int y = chosenumber();
	int m = chosemonth(); 
	int d = enterday();
	int a = addingday();*/

	dates d1 = ask(); 
	cout << "\n--------------------\n";
	dates d2 = ask(); 

	if (checkbiggeryear(d1,d2))
		cout << "yea date1 its less than";
	else if (checkequal(d1, d2))
		cout << "its equal"; 
	else
		cout << "not its not less than";

	return 0;
}

