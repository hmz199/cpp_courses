
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

void printmiddelrow(int arr[3][3], int row,int col) {

    short middelrow = row / 2;
    for (int i = 0; i < col; i++) {

        cout << arr[middelrow][i] << " ";
    }
}

void printmiddelcol(int arr[3][3],int row,int col) {

    int middelcol = col / 2;

    for (int i = 0; i < row; i++) { 

        cout << arr[i][middelcol] << " "; 
    }
}


int main()
{
   srand(time(0));

   int arr1[3][3];
     
   martix1fill(arr1);  

   cout << "\nmatrix 1 \n";
   printmatrix(arr1); 

   cout << "\nmiddel row\n";
   printmiddelrow(arr1,3,3); 

   cout << "\nmiddel col \n";
   printmiddelcol(arr1,3,3);
    
    return 0;













}

