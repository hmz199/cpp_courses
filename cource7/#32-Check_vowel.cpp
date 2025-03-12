
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



char readchar() { 
     
    char word;

    cout << "please enter string ? ";
    cin >> word;

    return word;    
}


char inverleeter(char l) {
    return iswupper(l) ? tolower(l) : toupper(l);
}

bool checkvowel(char word) { 

    word = tolower(word);

    return ((word == 'a') || (word == 'e') || (word == 'i') || (word == 'o') || (word == 'u'));
    
}



int main()
{
    
    char c = readchar();
    
    
    if (checkvowel(c)) {

        cout << "yes its '" << c << "' a vowel";
    }
    else
    {
        cout << "no its '"<< c <<"' not a vowel";
    }
    
    
    
    
    
    
    
    
    
    
    return 0;
}

