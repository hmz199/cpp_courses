
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

            cout << setw(3) << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool checknumber(int arr[3][3],int num,int row,int col) {

    for (int i = 0; i < row; i++) {

        for (int j = 0; j < col; j++) { 

            if (arr[i][j] == num) {
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
       {0,0,0},
       {0,0,0},
       {1,1,1}
   };

   int arr1[3][3];

  
   martix1fill(arr1);   

   cout<< setw(3) << "\nmatrix 1 \n";
   printmatrix(arr1); 
     
   if (checknumber(arr1,5, 3, 3)) {
       cout << "yes its there";
   }
   else {
       cout << "no not there ";
   }
  


    
    return 0;













}

