
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

string trimleft(string s1) {

    for (int i = 0 ; i < s1.length(); i++) {

        if (s1[i] != ' ') {

            return s1.substr(i, s1.length() - i);
        }

    }
    return "";
}
string trimright(string s1) {

    for (int i = s1.length() ; i > 0; i++) { 

        if (s1[i] != ' ') {

            return s1.substr(0, i);
        }

    }
    return "";
}

string trim(string s1) {

    string s;

    s = trimleft(s1);
    s = trimright(s1);

    return s;
}

int main()
{
    string name = "   mohammed abu-hahdoud    ";
    cout << "tirm left=" << trimleft(name) << endl; 
    cout << "tirm left=" << trimright(name) << endl; 
    cout << "tirm left=" << trim(name) << endl; 

    return 0;
}

