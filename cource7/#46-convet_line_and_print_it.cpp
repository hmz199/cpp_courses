
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
    int acountbalance;
};


 
vector<string> split(string s1, string delem) {

    string word = "";
    vector<string> vstring;
    while (s1.find(delem) != string::npos) {
        word = s1.substr(0, s1.find(delem));

         vstring.push_back(word);

        s1.erase(0, s1.find(delem) + delem.length());

    }if (s1 != "") {
        vstring.push_back(s1);
    }

    return vstring;
}

clientdata converlintodata(string line) {

    clientdata cd;
    vector<string> vstring;

    vstring = split(line, "#//#");
    
    cd.acountnum = vstring[0];
    cd.pincode = vstring[1];
    cd.name = vstring[2];
    cd.phone = vstring[3];
    cd.acountbalance = stod(vstring[4]); 

    return cd;
}
void printclientinfo(clientdata cd) {

    cout << "account num " << cd.acountnum << endl;
    cout << "pin code " << cd.pincode << endl;
    cout << "name " << cd.name << endl;
    cout << "phone " << cd.phone << endl;
    cout << "account balance " << cd.acountbalance << endl; 
}



int main()
{
    clientdata cd;
    string data = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.000000";
    cout << "the record is\n" << data << endl; 

    cd = converlintodata(data);

    cout << "\nthe foolowing is the extracted data\n";
    printclientinfo(cd);
    
    return 0;
}

