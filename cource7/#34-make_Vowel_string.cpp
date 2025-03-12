
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



bool chackvowel(char c) {

    c = tolower(c);

    return ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')); 
}

void makeVowelstring(string word) { 

    
    int co = 0;

   

    for (int i = 0; i < word.length(); i++) {


        if (chackvowel(word[i])) {
                
            cout << word[i] << " ";
        }
    }
    
}



int main()
{
    
    string s = readstring();
    
    cout << "vowel in string are : ";
    makeVowelstring(s);
   
    
    
    
    
    
    
    
    
    
    return 0;
}

