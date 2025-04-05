
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

//frist way 


string reverse(string st) { 

    string words = "";
    string delem = " ";
    for (int i = st.length() -1 ; i >= 0; i--) {
        
        if (st[i] == ' ') {

           words += st.substr(i + 1 , st.length() -1) + " "; 
            st.erase(i, st.length() -1);  
        }
        
    }
    if (st != " ") {

        words += st.substr(0, st.length());
    }

    return words;
}
 //-----------------------------------------------------------------------------------------------------

//second way
vector<string> split(string s1, string delem) {

    vector<string> vstring;
    string word = "";
    while (s1.find(delem) != string::npos) {
        
        word = s1.substr(0, s1.find(delem));

        if (word != delem) {

            vstring.push_back(word);
            s1.erase(0, s1.find(delem) + delem.length());
        }
           

    }if (s1 != delem) {

        vstring.push_back(s1);
    }
    return vstring;
}

string reverse_words(string s1) {

    vector<string>vstring;
    vstring = split(s1, " ");

    string word = "";
    vector<string>::iterator iter = vstring.end(); 

    while (iter != vstring.begin()) {  

        iter--;
        word += *iter + " ";
        
    }
    word = word.substr(0, word.length() - 1);
   
    return word;

}







int main()
{
    vector<string>vstring;
    string entername = readstring(); 

    cout << "\nstring after reverse" << endl; 
    cout << reverse(entername);  

    cout << "\n\nstring after reverse of second way " << endl;
    cout << reverse_words(entername) << endl; 

  

    return 0;
}

