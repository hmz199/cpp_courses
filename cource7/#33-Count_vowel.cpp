
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


char inverleeter(char l) {
    return iswupper(l) ? tolower(l) : toupper(l);
}


bool chackvowel(char c) {

    c = tolower(c);

    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')); 
}

short countvowel(string word) { 

    
    int co = 0;

    for (int i = 0; i < word.length(); i++) {

        if (chackvowel(word[i])) {
            co++;
        }
    }
    
    return co;
}



int main()
{
    
    string s = readstring();
    
    cout << " number of vowel is : " << countvowel(s);
   
    
    
    
    
    
    
    
    
    
    return 0;
}

