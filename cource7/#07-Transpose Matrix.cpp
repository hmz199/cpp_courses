
#include <iostream>
#include <iomanip> // for setw() 
using namespace std; 







void martixfill(int arr[3][3]) {

    int counter = 1;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            arr[i][j] = counter++;  
        } 
    }
}

void printmatrix(int arr[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            printf("   %d" , arr[i][j]);
        }
        cout << endl;
    }
}

void matrixtransposed(int arr[3][3], int trans[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            trans[i][j] = arr[j][i];
        }
    }
}

void printtrans(int trans[3][3]) {

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            cout << setw(3) << trans[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
   srand(time(0));

   int arr[3][3];
   int trans[3][3];
   martixfill(arr);   
   printmatrix(arr);
   
   matrixtransposed(arr, trans);
   cout << "the following are transpose matrix\n";
   printtrans(trans);

    
    
    
    return 0;













}

