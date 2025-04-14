#include <iostream>
#include <string>
using namespace std; 


unsigned long long enternumber() {

    unsigned long long number;
    cout << "enter a number plese to transfer it to texet ";
    cin >> number;

    return number;
}

string numbertotext(unsigned long long number) {

    if (number == 0) {
        
        return "";
    }
    if (number >= 1 && number <= 19) {

        string nums[] = { "","one" ,"two","three","four","five","six","saven","eight","nine","ten","eleven","twelv","thrten","fourten","sixten","seventen","eightten","nineten" };

        return nums[number];
    }
    if (number >= 20 && number <= 99) {

        string nums[] = { "","","twintey","thrty","forty","fivty","sixty","saventy","eightty","ninty" };

        return nums[number / 10] + " " + numbertotext(number % 10);

    }
    if (number >= 100 && number <= 999) {

        return numbertotext(number / 100) + " hundred " + numbertotext(number % 100);
    }
    if (number >= 1000 && number <= 99999) {

        return numbertotext(number / 1000) + " thousand " + numbertotext(number % 1000);
    }
    if (number >= 10000 && number <= 999999) {

        return numbertotext(number / 10000) + " thousand " + numbertotext(number % 10000);
    }
     if (number >= 1000000 && number <= 9999999) {

        return numbertotext(number / 1000000) + " million " + numbertotext(number % 1000000);
    }
     if (number >= 10000000 && number <= 999999999) {

         return numbertotext(number / 1000000) + " million " + numbertotext(number % 1000000);
     }
     if (number >= 1000000000 && number <= 199999999999) {

         return numbertotext(number / 1000000000) + " Billions " +numbertotext(number % 1000000000);
     }
     if (number >= 10000000000 && number <= 9999999999999) {

         return numbertotext(number / 1000000000) + "Billions " + numbertotext(number % 1000000000);
     }
   

}


int main()
{
    unsigned long long read = enternumber();

    cout << numbertotext(read);
    
}

