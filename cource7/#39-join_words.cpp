
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


string join(vector<string>& names , string delem) {

    string words = "";
    for (string& g : names) {

        words = words + g + delem;
    }

    return words.substr(0, words.length() - delem.length());
}




int main()
{

    vector<string> names = { "hazim","zedan" }; 

    cout << join(names, " ");

    return 0;
}

