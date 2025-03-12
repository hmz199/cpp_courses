
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
using namespace std; 






int random(int from, int to) {

    int r = rand() % (to - from + 1) + from;

    return r;
}

void martix1fill(int arr1[3][3]) {


    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr1[i][j] = random(1, 100);
        }
    }
}

void printmatrix(int arr1[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << setw(3) << arr1[i][j] << " ";
        }
        cout << endl;
    }
}

void martix1Max(int arr1[3][3]) { 

    int max = arr1[0][0];
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (arr1[i][j] > max) {

                max = arr1[i][j]; 
           }
        }
    }
    cout << "\nmax is\n" << max;
}
void martix1Min(int arr1[3][3]) {

    int min = arr1[0][0]; 
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (arr1[i][j] < min) {

                min = arr1[i][j]; 
            }
        }
    }
    cout << "\nmin is\n" << min; 
}



int main()
{
   srand(time(0));
  
   vector<int>vnums;
   int arr1[3][3];
  
   martix1fill(arr1);   

   cout<< setw(3) << "\nmatrix 1 \n";
   printmatrix(arr1);

   cout << endl; 
   martix1Max(arr1);
   martix1Min(arr1);
    
    return 0;













}

