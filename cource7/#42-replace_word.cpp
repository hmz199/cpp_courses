
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

//frist way splits words then loop inside them and make if to check if word = jordan then replace it 

vector<string> split(string s1, string delem) {

    vector<string> vstring;
    string word = "";

    while (s1.find(delem) != string::npos) {

        word = s1.substr(0, s1.find(delem));

        if (word != " ") {

            vstring.push_back(word);
        }
        s1.erase(0, s1.find(delem) + delem.length());

    }if (s1 != " ") {
        vstring.push_back(s1);
    }

    return vstring;
}


string replace_word(string s1,string old,string newword) {

    vector<string> vstring;
    string words = "";

    vstring = split(s1, " ");

    for (string& w : vstring) {

        if (w == old) {

            w = newword;
           
        }
        words += w + " ";   
    }
    
    return words;
}


// seconde use replace funcation 

string replace_word2(string s1, string oldword, string newword) {

    while (s1.find(oldword) != string::npos) { // replace funcation in the frist parameter take the postion 

        s1.replace(s1.find(oldword), oldword.length(), newword);
    }



    return s1;
}







int main()
{

    string read = readstring();
    cout << replace_word(read, "jordan" , "usa");


    cout << "\nthe string after reolace words \n" << replace_word2(read, "jordan", "usa");

    
    return 0;
}

