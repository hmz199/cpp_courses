
#include <iostream>
#include <iomanip> // for setw() 
using namespace std; 





int random(int from, int to) {

    int r = rand() % (to - from + 1) + from;

    return r;
}

void makerandommatric(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr[i][j] = random(1, 100);
        }
    }
}

void printmatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << " ";  
        }

        cout << endl; 
    }
}

void printrowsum(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {

            sum += arr[i][j];

        }
       
        cout << "row" << i + 1 << "sum = " << sum << endl;
         
    }

}


int main()
{
   srand(time(0));

   
   
   int arr[3][3];

makerandommatric(arr);

cout << setw(3) <<"Matrix: 3x3" << endl;
printmatrix(arr);
	
cout << endl; 
	
cout << "the following are the sum of each row: \n";
printrowsum(arr);
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;













}

