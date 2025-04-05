

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;




int readnum() {

	int num;
	do
	{
		cout << "enter postive number";
		cin >> num;

	} while (num <= 0);

	return num;
}

bool checkperfect(int num) {

	int sum = 0;
	for (int i = 1; i < num; i++) {

		if (num % i == 0)
			sum += i;

	}
	return sum == num;

}

void print(int num) {

	for (int i = 1; i <= num; i++) {
		if (checkperfect(i)) {

			cout << i << " perfect" << endl;
		}
		else
		{
			cout << i << " not perfect" << endl;
		}
	}
}


int main()
{
	print(readnum());


    return 0;
}








