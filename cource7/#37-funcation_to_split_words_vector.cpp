
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

vector<string> cutwords(string s1,string delem) { 

    vector<string>vstring;

    string word = "";
    while ((s1.find(delem)) != string::npos) {

        word = s1.substr(0, s1.find(delem));

        if (word != "") {

            vstring.push_back(word);
           
        }

        s1.erase(0, s1.find(delem) + delem.length());

    }
    if (s1 != "") {
        
        vstring.push_back(s1); 
    }

    return vstring; 
}



int main()
{

    vector<string>vstring;

    vstring = cutwords(readstring(), " ");

    cout << "tokens" << vstring.size() << endl;

    for (string &words : vstring) {

        cout << words << endl;
    }
   

    return 0;
}

