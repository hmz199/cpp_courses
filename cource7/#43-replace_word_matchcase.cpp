
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

string replace_word(string s1, string old_word, string new_word) {

    while (s1.find(old_word) != string::npos) { 

        s1.replace(s1.find(old_word), old_word.length(), new_word); // in replcase frist feild take postion 
    }

    return s1; 

}

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

string lowerall(string s1) {

    for (int i = 0; i < s1.length(); i++) {

        s1[i] = tolower(s1[i]);
    }

    return s1;
}
string replace_anotherway(string s1 , string old_word, string new_word,bool matchcase) {

    vector<string> vstring;
    string word = "";
    vstring = split(s1, " ");

    for (string& g : vstring) {

        if (matchcase) {

            if (g == old_word) {

                g = new_word;
            }
        }
        else {
                
               if ( lowerall(g) == lowerall(old_word)) {

                   g = new_word;
            }
        }
        word += g + " ";
        
    }
    return word; 
}


int main()
{
    string s1 = readstring();

    //cout << replace_word(s1, "jordan", "usa");
    cout << endl;

    cout << replace_anotherway(s1, "Jordan", "usa",true);
    return 0;
}

