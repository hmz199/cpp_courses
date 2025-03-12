
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


string upperfristletter(string &word) {

    bool fristletter = true;
    for (int i = 0; i < word.length(); i++) {

        if (word[i] != ' ' && fristletter) {

            word[i] = toupper(word[i]);
            fristletter = false;
        }
        if (word[i] == ' ')
        {
            fristletter = true;
            
        }
       
        
    }
    return word;
}






int main()
{
    string x = readstring();
    cout << upperfristletter(x);  
 
    return 0;










}

