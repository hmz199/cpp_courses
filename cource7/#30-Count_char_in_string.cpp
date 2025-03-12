
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



string readstring() { 
     
    string word;

    cout << "please enter string ? ";
    getline(cin, word);

    return word;    
}

char readchar() {

    char read;

    cout << "plese enter a character ";
    cin >> read;

    return read;
    
}

void countCharInString(char c, string word) {

    short co = 0;
    for (int i = 0; i < word.length(); i++) {

        if (word[i] == c) {
            co++;
        }

    }

    cout << "letter " << c << " count= " << co;
}





int main()
{
   
    countCharInString(readchar(), readstring()); 
    return 0;

 








}

