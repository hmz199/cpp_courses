
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
using namespace std; 




void fibseries() {
	
	int term1 = 0;
	int term2 = 1;
	int total = 0;
	cout << "1 ";
	for (int i = 1; i < 10; i++) {

		total = term1 + term2; 
		cout << total << " ";

		term1 = term2;
		term2 = total;
	}

}



int main()
{
   srand(time(0));
  
   int arr[10];
   fibseries();
  
    return 0;













}

