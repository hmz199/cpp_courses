
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std; 



struct clientdata {
    string acountnum;
    string pincode; 
    string name;
    string phone;
    int acountbalance;
};

const string Clint_filename = "clients_data.txt";

clientdata userenterdetails() {
    
    clientdata cd;

    cout << "enter account number? ";
    getline(cin >> ws, cd.acountnum);

    cout << "enter pincode? ";
    getline(cin, cd.pincode); 

    cout << "enter name? ";
    getline(cin, cd.name);

    cout << "enter phone ";
    cin >> cd.phone;

    cout << "enter account balance ";
    cin >> cd.acountbalance;

    return cd; 
}

string oneline(clientdata cd , string sperator = "#//#") {


    string data = "";
    
    data += cd.acountnum + sperator;
    data += cd.pincode + sperator; 
    data += cd.name + sperator;
    data += cd.phone + sperator;
    data +=  to_string(cd.acountbalance) + sperator;

    return data;

}

void addtofile(string s1,string filename) {

    fstream clienfile;

    clienfile.open(filename, ios::app); 

    if (clienfile.is_open()) {

        clienfile << s1 << endl; 
    }
    clienfile.close();
}

void addnewclient() {

    clientdata cd;

    cd = userenterdetails();
    addtofile(oneline(cd), Clint_filename); 

}

void addclient() {

    char check;

    do
    {
        system("cls");
        cout << "add new client \n\n";
        addnewclient();

        cout << "\nclient add succisfily , do you want to add new client ";
        cin >> check;

    } while (toupper(check) == 'y');
}


int main()
{
   
    addclient();
    
    return 0;
}

