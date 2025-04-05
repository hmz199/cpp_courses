

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string> 

using namespace std;


void head() {
	cout << endl;
	cout << "\t\t\t" << "multiplication tableb from 1 to 10\n";

	for (int i = 1; i <= 10; i++) {

		cout << "\t" << i;
	}
	cout << "\n----------------------------------------------------------------------------------------------------------------\n";
}

string s(int num) {

	if (num > 9)
		return "  |";
	else
		return "   |";

}

void body() {

	head();

	for (int i = 1; i <= 10; i++) {

		cout << i << s(i) << "\t";
		for (int j = 1; j <= 10; j++) {
			cout << "" << i * j << "\t";
		}
		cout << endl;
	}

}


int main()
{
    body();



    return 0;
}








