

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;






int readnum() {
	int num;
	cout << "enter num to reversed";
	cin >> num;

	return num;
}

void print(int num) {
	int re = 0;
	while (num > 0) {
		re = num % 10;
		num = num / 10;

		cout << re << endl;  

	}

}


int main()
{ 
    
	print(readnum());

    return 0;
}








