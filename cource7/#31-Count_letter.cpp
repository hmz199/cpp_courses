
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

char inverleeter(char l) {
    return iswupper(l) ? tolower(l) : toupper(l);
}

void countCharInString(char c, string word) {

    short co = 0;
    short coall = 0;
    for (int i = 0; i < word.length(); i++) {

        if (word[i] == c) { 
            co++;
        }
        if (tolower(word[i]) == tolower(c)) {
            coall++;  
        }
    }

    cout << "letter " << c << " count= " << co << endl; 
    cout << "letter " << c << " or '" << inverleeter(c) << "' count = " << coall; 
}



int main()
{
   
    countCharInString(readchar(), readstring()); 

   
    return 0;

 








}

