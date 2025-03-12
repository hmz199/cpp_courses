
#include <iostream>
#include <iomanip> // for setw() 
using namespace std; 






int random(int from, int to) {

    int r = rand() % (to - from + 1) + from; 

    return r;
}

void martix1fill(int arr1[3][3]) {

    int counter = 1;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr1[i][j] = random(1,10);  
        } 
    }
}

void printmatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            printf("  %0*d  " ,2, arr[i][j]);
        }
        cout << endl;
    }
}

void summatrix(int arr1[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            sum += arr1[i][j];
        }
    }
    cout << "\nsum of matrix is :" << sum << endl;
}


int main()
{
   srand(time(0));

   int arr1[3][3];
     
   martix1fill(arr1);  

   cout << "\nmatrix 1 \n";
   printmatrix(arr1); 
    
   summatrix(arr1);
    
    return 0;













}

