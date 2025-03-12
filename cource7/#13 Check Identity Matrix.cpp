
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

            arr1[i][j] = random(1, 10);
        }
    }
}

void printmatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}



bool checkmatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if ((i == j && arr[i][j] != 1) || (i != j && arr[i][j] != 0))  { 
                return false;
            }
        }
    }
    return true;  
}

int main()
{
   srand(time(0));

   int arr1[3][3];

   /*int matrix[3][3] =
   {
       {1,0,0},
       {0,1,0},
       {0,0,1 }
   };*/
      
   martix1fill(arr1);   

   cout << "\nmatrix 1 \n";
   printmatrix(arr1);  
     
  

   if (checkmatrix(arr1)) { 

       cout << "\nyes : matrix identity \n";
   }
   else {
       cout << "no : not identity ";
   }
    
    return 0;













}

