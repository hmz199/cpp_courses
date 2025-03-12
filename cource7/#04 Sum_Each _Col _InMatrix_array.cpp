
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

void putcolsuminarray(int arr[3][3], int row, int col, int arr2[3]) {

    for (int i = 0; i < col; i++) {

        arr2[i] = sumcol(arr, row, i);
    }
}

void printarray(int arr2[3]) {

    for (int i = 0; i < 3; i++) {

        printf("col %d sum = %d\n", i + 1, arr2[i]);
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
    
   putcolsuminarray(arr, 3, 3, arr2);

   cout << "the following cols sum from 1D array \n";

   printarray(arr2);
    
    
    
    
    
    
    
    
    return 0;













}

