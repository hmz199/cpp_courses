
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



char readchar() { 

    char word;

    cout << "please enter char ? ";
    cin >> word;

    return word;    
}

char invertChar(char letter) {

    return isupper(letter) ? tolower(letter) : toupper(letter);
}







int main()
{
   
    cout << invertChar(readchar());  
    return 0;

 








}

