#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 


int readyear() {

	int year;


	cout << "plese enter a year to check ";
	cin >> year;


	return year;
}

int readmonth() {

	int month;
	short times = 3;

	do
	{
	cout << "\n\nplese enter a month to check from 1 - 12 ";
	cin >> month;

	if (month < 1 || month > 12) {

	--times;
	}
	
	if (times == 0){

		exit(0);
	}

	} while ((month < 1 || month > 12) && times != 0);


	return month; 
}

bool leapyear(int year) {

	return year % 400 == 0 ? true : year % 100 == 0 ? false : year % 4 == 0;
}

int numbermonth(int month,int year) {

	return month == 2 ? (leapyear(year) ? 29 : 28) : month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31;
}

short dayorder(short year, short month, short day) {

	short a, y, m, d;

	a = (14 - month) / 12;
	y = year - a;
	m = month + (12 * a) - 2;
	d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}
string bringmonthname(int month) {
	string monthwechose[] = { "","jan","feb","mar","april","may","jun","juli","aguest","sep","oct","nov","dec" };

	return monthwechose[month];
}

void printcalender(int month, int year) {

	int days = numbermonth(month, year);
	int dayorderfrom1 = dayorder(year, month, 1);

	string monthdays[] = { "sun","mon","tue","wed","thu","fri","sat" };

	cout << "\n\n------------" << bringmonthname(month) << "------------------\n\n";
	for (int k = 0; k < 7; k++) {

		cout << " " << monthdays[k] << " ";
	}
	cout << "\n";
	int i;
	for ( i = 0; i < dayorderfrom1; i++) {
		cout << "     ";
	}
	for (int j = 1; j <= days; j++) { 
		// Print day number with consistent width 
		cout << setw(3)  << j << "  "; 

		// Break line after Saturday
		if (++i == 7) {   
			i = 0; 
			cout << "\n"; 
		}
	}
	printf("\n----------------------------------");
}

int main()
{	
	int num = (1 + 13) % 7 == 0;
	cout << num << endl; 
	int ready = readyear();
	int readm = readmonth();

	printcalender(readm, ready);

}

