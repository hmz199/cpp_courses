

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;






int readnum(string mass) {

	int num;
	do
	{
		cout << mass;
		cin >> num;

	} while (num <= 0);
	return num; 
}

int count(int frq , int num) {
	int co = 0;
	int re = 0;
	while (num > 0) {
		re = num % 10;
		num = num / 10;
		if (frq == re) {
			co++;
		}
	}
	return co;
}

void printallfrq(int num) {

	for (int i = 0; i <= 9; i++)
	{
		int all = count(i, num); 

		if (all > 0) {
			cout << "diget is " << i << "frequncy is " << all << endl; 
		}
	}

}



int main()
{ 
    
	
	int num = readnum("enter postive num ");
	printallfrq(num); 


    return 0;
}








