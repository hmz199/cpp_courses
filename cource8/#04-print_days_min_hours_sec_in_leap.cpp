#include <iostream>
#include <string>
using namespace std; 


int enteryear() {

	int number;
	cout << "enter a year to check: ";
	cin >> number;

	return number;
}

bool leapyear(int num){

	return num % 400 == 0 ? true : (num % 100 == 0) ? false : num % 4 == 0;

}

short numberofdaysinyear(short num) {

	return leapyear(num) ? 366 : 365;
}

short numberofhoursinyear(short num) {

	return numberofdaysinyear(num) * 24;
}

int numberofminutesinyear(short num) {

	return numberofhoursinyear(num) * 60;
}

int numberofsecondesinyear(short num) {

	return numberofminutesinyear(num) * 60;
}

void printleapyears(int num) {


	cout << "number of days in year [" << num << "] is " << numberofdaysinyear(num) << endl; 
	cout << "number of hours in year [" << num << "] is " << numberofhoursinyear(num) << endl; 
	cout << "number of minutes in year [" << num << "] is " << numberofminutesinyear(num) << endl; 
	cout << "number of sec in year [" << num << "] is " << numberofsecondesinyear(num) << endl; 

}



int main()
{

	int read = enteryear();

	printleapyears(read);
	
   
}

