#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>
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

	cout << "enter starsd date\n\n";
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


enum comparedates { before = -1, equal = 0, after = 1 };


comparedates compare(dates d1, dates d2) {

	if (datesequal(d1, d2))
		return comparedates::equal;
	else if (checkdate1less(d1, d2))
		return comparedates::before;
	else
		return comparedates::after;
}

string enterdate() {

	string date;
	cout << "plese enter date dd/mm/yyyy? ";
	cin >> date;

	return date;
}

// use if i want to change more than one word we use while
string replacewordinstring(string s1, string toreplace, string toreplacewith) {
	short pos = s1.find(toreplace);

	while (pos != string::npos) {
		s1 = s1.replace(pos, toreplace.length(), toreplacewith);
		pos = s1.find(toreplace, pos + toreplacewith.length());
	}

	return s1;
}

vector<string> splitstring(string date, string del) {

	dates d1;
	string d = "";
	vector<string> parts;


	while (date.find(del) != string::npos) {

		d = date.substr(0, date.find(del));
		parts.push_back(d);
		date.erase(0, date.find(del) + 1);
	}
	if (date != "") {
		parts.push_back(date);
	}

	return parts; 

}


dates  stringtodate(string s) {

	dates d;
	vector<string>vdate;

	vdate = splitstring(s,"/");

	d.day = stoi(vdate[0]);
	d.month = stoi(vdate[1]);
	d.year = stoi(vdate[2]);

	return d;

}

string datesformat(dates d, string format = "dd/mm/yyyy") {

	string f = "";

	f = replacewordinstring(format, "dd", to_string(d.day)); 
	f = replacewordinstring(format, "mm", to_string(d.month));
	f = replacewordinstring(format, "yyyy", to_string(d.year));

	return f;
}


int main()
{
	
	string dat = enterdate();
	
	dates d = stringtodate(dat);

	cout << "\n" << datesformat(d) << endl;

	cout << "\n" << datesformat(d, "yyyy/dd/mm") << endl;
	cout << "\n" << datesformat(d, "day:dd month:mm year:yyyy") << endl;



}
 