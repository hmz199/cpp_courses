
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

            arr1[i][j] = random(1, 10);
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

void martix2fill(int arr2[3][3]) {


    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr2[i][j] = random(1, 10); 
        }
    }
}

bool isnuminmatrix(int arr[3][3], int num) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (num == arr[i][j]) {
                return true;
           }
        }
    }
    return false;
}
bool numisduplcate(int arr[3][3], int num) {
    int co = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (num == arr[i][j]) {
                co++;
            }
        }
    }
    return co > 1;
}

void intersectedNum(int arr[3][3], int arr2[3][3]) {
    int num;
    bool printed[10] = { false };
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            num = arr2[i][j];
            if (isnuminmatrix(arr, num) && !printed[num]) {

                cout << setw(3) << num << " ";
                printed[num] = true;
           }
        }
    }
}



int main()
{
   srand(time(0));
  
   vector<int>vnums;
   int arr1[3][3];
   int arr2[3][3];
   int arr[100];
  
   martix1fill(arr1);   

   cout<< setw(3) << "\nmatrix 1 \n";
   printmatrix(arr1); 
   cout << endl; 
   martix2fill(arr2);

   cout << setw(3) << "\nmatrix2\n";
   printmatrix(arr2);

   cout << "\nintersected numbers are\n";
   intersectedNum(arr1, arr2);
    
    
    return 0;













}

