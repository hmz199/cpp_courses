
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
using namespace std; 



string readstring() {

    string word;

    cout << "please enter string ? ";
    getline(cin, word);

    return word;   
}

void printfristletter(string word) {

    bool fristletter = true;
    for (int i = 0; i < word.length(); i++) {

        if (word[i] != ' ' && !fristletter) {

            cout << word[i] << " " << endl;
            fristletter = false;
        }
         if (word[i] == ' ')  
        {
            fristletter = true;
        }

    }
}




int main()
{
  
    //printFristletterfromword(readstring());
    printfristletter(readstring());
 
    return 0;










}

