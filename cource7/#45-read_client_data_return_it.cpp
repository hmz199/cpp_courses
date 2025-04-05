
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
using namespace std; 



struct clientdata {
    string acountnum;
    string pincode; 
    string name;
    string phone;
    double acountbalance;
};

clientdata userenterdetails() {
    
    clientdata cd;
    cout << "enter account number? ";
    cin >> cd.acountnum;

    cout << "enter pincode? ";
    cin >> cd.pincode;

    cin.ignore();

    cout << "enter name? ";
    getline(cin, cd.name);

    cout << "enter phone ";
    cin >> cd.phone;

    cout << "enter account balance ";
    cin >> cd.acountbalance;

    return cd; 
}

string oneline(clientdata cd , string sperator) { 


    string data = "";
    
    data += cd.acountnum + sperator;
    data += to_string(cd.acountbalance) + sperator;
    data += cd.name + sperator;
    data += cd.phone + sperator;
    data += cd.pincode + sperator;  

    return data;

    
}




int main()
{
   
    clientdata cd;
    cd = userenterdetails();

    cout << "\n\nclient record for svaing\n"; 
    cout << oneline(cd,"#//#");
    
    return 0;
}

