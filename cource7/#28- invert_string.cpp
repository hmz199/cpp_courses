
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

string invertstring(string word) {

    for (int i = 0; i < word.length(); i++) {

        word[i] = isupper(word[i]) ? tolower(word[i]) : toupper(word[i]);
    }
    return word;
}






int main()
{
   
    cout << invertstring(readstring());   
    return 0;

 








}

