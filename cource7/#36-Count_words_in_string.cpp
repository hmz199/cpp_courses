
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



string readstring() {

    string word;
    cout << "enter a fill name:f ";
    getline(cin, word);

    return word;
}

short countwordsinstring(string s1) { 

    string delm = " ";
    string word;
    short count = 0;
    while ((s1.find(delm)) != string::npos) {

        word = s1.substr(0,s1.find(delm));

        if (word != "") {
            count++;
        }
        s1.erase(0, s1.find(delm) + delm.length());
    }
    if (s1 != "") {
        count++;
    }
    return count;
}



int main()
{
    
    cout << "the number in the string is \n" << countwordsinstring(readstring());  
   
    
  
    
    return 0;
}

