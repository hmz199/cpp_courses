
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


string join(string arr[],int length, string delem) {

    string word = "";
    for (int i = 0; i < length; i++) {

        word += arr[i] + delem;
    }

    return word;
}

string joinv(vector<string> vs, string delem) {

    string word = "";
    for (string& s : vs) {

        word += s + delem;

    }

    return word;
}



int main()
{

    vector<string> vs = { "yes","no","99" };
    string arr[] = { "yes","yes","99" };

    cout << "array words after join" << endl;
    cout << join(arr, 3, " ");

    cout << "\nvector words after join" << endl;
    cout << joinv(vs, " "); 
   

    return 0;
}

