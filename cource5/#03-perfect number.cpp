

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;




enum enperfectornot{perfet=1,notperfect=2};

int readnum(string mass) {
	int num;
	cout << mass;
	cin >> num;

	return num; 
}

enperfectornot check(int num) {

	int sum = 0;
	for (int i = 1;i < num;i++) {        //perfect number is number % numbers == 0  ,then sum the numbers that eqaual the zeroz if the, number and sum eqaul this are perfect

		if (num % i == 0) {          // the num not divsible by it self that why we make < only
			sum += i;
		}
	}
	if (sum == num)
		return enperfectornot::perfet;
	else
		return enperfectornot::notperfect;

}

void print(int num) {

	if (check(num) == enperfectornot::perfet)
		cout << "perfect " << num;
	else
		cout << "not perfect ";
			

}


int main()
{ 
    
    print(readnum("enter to check if perfect or not "));

    return 0;
}








