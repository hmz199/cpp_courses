
#include <iostream>
#include <iomanip> // for setw() 
using namespace std; 



// #1

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

int sumrow(int arr[3][3], short row, short col) {

    int sum = 0;
    for (int i = 0; i < col; i++) { 

        sum += arr[row][i];

    }
    return sum; 
}

void putsuminarray(int arr[3][3], short row, short col,int arr2[3]) {

    int sum = 0;
    for (int i = 0; i < row; i++) { 

        arr2[i] = sumrow(arr, i, col);

    }
}

void printarray(int arr2[3]) {

    for (int i = 0; i < 3; i++) {

        cout << "row " << i + 1 << " sum = " << arr2[i] << endl;  
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
    
   putsuminarray(arr, 3, 3, arr2);

   cout << "the sum from 1 diminshinal array\n";
   printarray(arr2); 
    
    
    
    
    
    
    
    
    return 0;













}

