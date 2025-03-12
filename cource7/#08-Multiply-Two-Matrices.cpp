
#include <iostream>
#include <iomanip> // for setw() 
using namespace std; 






int random(int from, int to) {

    int r = rand() % (from - to + 1) + from;

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

void martix2fill(int arr2[3][3]) { 

    int counter = 1;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr2[i][j] = random(1,10); 
        }
    }
}

void multipule2matrix(int arr1[3][3], int arr2[3][3], int arrM[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arrM[i][j] = arr1[i][j] * arr2[i][j];
        }
    }
}



int main()
{
   srand(time(0));

   int arr1[3][3], arr2[3][3], arrM[3][3];
     
   martix1fill(arr1);  

   cout << "matrix 1 \n";
   printmatrix(arr1); 

   martix2fill(arr2); 

   cout << "\nmatrix 2 \n";

   printmatrix(arr2);
    
   multipule2matrix(arr1, arr2, arrM); 

   cout << "\nresult \n";
   printmatrix(arrM);
    
    return 0;













}

