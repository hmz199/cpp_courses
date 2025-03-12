
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



string readstring() {

    string word;
    cout << "enter a fill : ";
    getline(cin, word);

    return word;
}

void cutwords(string s1) {

    string delm = " ";
    string word;
    
    while ((s1.find(delm)) != string::npos) { 

        word = s1.substr(0, s1.find(delm)); // substar doent take the space with it 

        if (word != "") {

            cout << word << endl;
        }

        s1.erase(0, s1.find(delm) + delm.length()); // here we add the space to delete it 
      
    }if (s1 != "") {
        cout << s1 << endl; 
    }
}


int main()
{
    
    cutwords(readstring()); 

 
    return 0;
}

