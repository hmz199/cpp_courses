
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



void checknummatrix(int arr[3][3]) { 
    int num;
    cout << "\nenter the number to count in matrix\n";
    cin >> num; 
    int co = 0;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (num == arr[i][j]) {
                co++;
           }
        }
    }
    cout << "number " << num << " count in matrix is : " << co;

}

int main()
{
   srand(time(0));

   int arr1[3][3];

  
   martix1fill(arr1);   

   cout<< setw(3) << "\nmatrix 1 \n";
   printmatrix(arr1);
     
   checknummatrix(arr1); 


    
    return 0;













}

