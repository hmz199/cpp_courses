
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



string readstring() {

    string word;
    cout << "enter a fill name: ";
    getline(cin, word);

    return word;
}

string remove_punctuations(string s1) {

    for (int i = 0; i < s1.length(); i++) {

        if (ispunct(s1[i]) ){ 
            
            s1.erase(i, 1);
        }
    }
    return s1;
}



int main()
{
    string read = readstring();
    cout << remove_punctuations(read); 
    return 0;
}

