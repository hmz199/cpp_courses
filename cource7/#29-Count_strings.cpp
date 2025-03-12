
#include <iostream>
#include <iomanip>  
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

void countSTRING(string word) {

    short coupper = 0;
    short colower = 0;

    for (int i = 0; i < word.length(); i++) {
        
        if (iswupper(word[i])) {
            coupper++;

        }
        if (iswlower(word[i])) {

            colower++;
        }
    }
    cout << "string length" << word.length() << endl;
    cout << "cpital letter count " << coupper << endl;
    cout << "small letter count " << colower << endl;
}






int main()
{
   
    countSTRING(readstring()); 
    return 0;

 








}

