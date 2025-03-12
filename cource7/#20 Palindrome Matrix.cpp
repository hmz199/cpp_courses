
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

bool martix1palindrom(int arr1[3][3],int row,int col) { 

    int max = arr1[0][0];
    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col /2; j++) {

            if (arr1[i][j] == arr1[i][col - j -1]) { 
                return true;

           }
        }
    }
    return false;
}




int main()
{
   srand(time(0));
  
   int matrix[3][3] = 
   {
       {1,2,1},
       {5,5,5},
       {7,3,7}
   };

   int arr1[3][3];
  
   martix1fill(arr1);    

   cout<< setw(3) << "\nmatrix 1 \n";
   printmatrix(arr1);  

   if (martix1palindrom(arr1, 3, 3)) {  
       cout << "its plindrom";
   }
   else {
       cout << "not plindrom";
   }
    return 0;













}

