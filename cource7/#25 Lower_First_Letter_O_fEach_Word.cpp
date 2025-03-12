
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

string smallfristletter(string word) {

    bool frist = true;
    for (int i = 0; i < word.length(); i++) {

        if (word[i] != ' ' && frist) {

            word[i] = tolower(word[i]);
            frist = false;
        }
        if (word[i] == ' ') {

            frist = true;
        }
    }
    return word;
}








int main()
{
    string x = readstring();
    
    cout << smallfristletter(x);
    return 0;










}

