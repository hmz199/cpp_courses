
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
using namespace std; 



void fibrecursion(int num ,int term1,int term2) {

    

    int feb = 0;
    if (num > 0) {
    feb = term1 + term2;

    cout << feb << " ";
    term2 = term1;       // the change that term2 will equal term1 
    term1 = feb;   
    fibrecursion(num -1, term1, term2);
    }

}




int main()
{
  
  
   fibrecursion(10, 0, 1);
    return 0;










}

