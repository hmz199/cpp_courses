
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



string readstring() {

    string word;

    cout << "please enter string ? ";
    getline(cin, word);

    return word;   
}

string smallfristletter(string word) {


    for (int i = 0; i < word.length(); i++) {

        word[i] = toupper(word[i]);
        
    }
    return word;
}

string tosmall(string word) {

    char check;

    do
    {
        cout << "\ndo you want to lower the string : y or n ";
        cin >> check;

        if (check == 'n') {

            exit(0);
        }

    } while (check != 'y' && check != 'Y'); 

    for (int i = 0; i < word.length(); i++) {

        word[i] = tolower(word[i]);

    }
    return word;
}







int main()
{
    string x = readstring();
    
    cout << smallfristletter(x);

    cout << tosmall(x);
    return 0;










}

