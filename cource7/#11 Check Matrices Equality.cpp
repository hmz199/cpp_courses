
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

void martix2fill(int arr2[3][3]) {

    int counter = 1;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr2[i][j] = random(1, 10);
        }
    }
}

int summatrix(int arr1[3][3],int row,int col) {

    int sum = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            sum += arr1[i][j]; 
        }
    }
    return sum;
} 

bool checkmatrix(int arr1[3][3], int arr2[3][3], int row, int col) {

    return summatrix(arr1, row, col) == summatrix(arr2, row, col);      
}

int main()
{
   srand(time(0));

   int arr1[3][3], arr2[3][3];
     
   martix1fill(arr1);  

   cout << "\nmatrix 1 \n";
   printmatrix(arr1); 
    
   martix2fill(arr2);

   cout << "\nmatrix2\n";
   printmatrix(arr2);

   if (checkmatrix(arr1, arr2,3,3)) {

       cout << "\nyes : they equal\n";
   }
   else {
       cout << "no : they not equal ";
   }
    
    return 0;













}

