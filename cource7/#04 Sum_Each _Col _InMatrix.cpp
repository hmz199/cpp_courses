
#include <iostream>
#include <iomanip> // for setw() 
using namespace std; 





int random(int from, int to) {

    int r = rand() % (to - from + 1) + from;

    return r;
}

void makerandommatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr[i][j] = random(1, 100);
        }
    }
}

void printmatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl; 
    }
}

int sumcol(int arr[3][3], int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; i++) {

        sum += arr[i][col];

    }
    return sum;
}

void printcol(int arr[3][3], int row, int col) {

    for (int i = 0; i < col; i++) {

        cout << "col " << i + 1 << " sum =" << sumcol(arr, row, i) << endl;
    }
}

int main()
{
   srand(time(0));

   int arr[3][3];
   int arr2[3];
 
   makerandommatrix(arr);
   cout << " the following matrix" << endl;  
   printmatrix(arr);
    
   cout << "the sum of each col\n";
   printcol(arr, 3, 3);
    
    
    
    
    
    
    
    
    return 0;













}

