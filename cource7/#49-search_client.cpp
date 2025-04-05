
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
    double acountbalance;
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

string makedataOneLine(clientdata cd , string sperator = "#//#"){ 

    string dataline = "";
    dataline += cd.acountnum + sperator;
    dataline += cd.pincode + sperator;
    dataline += cd.name + sperator;
    dataline += cd.phone + sperator;
    dataline += to_string(cd.acountbalance);  

    return dataline;
}

void addtofile(string data,string filename) {

    fstream myfile;

    myfile.open(filename, ios::app | ios::out); 

    if (myfile.is_open()) {

        myfile << data << endl;

    }
    myfile.close();

}

vector<string> split(string s1,string delem) {

    vector<string> vstring;
    string word = "";

    while (s1.find(delem) != string::npos) {
        word = s1.substr(0, s1.find(delem));

        vstring.push_back(word);

        s1.erase(0, s1.find(delem) + delem.length());
    }if (s1 != " ") {
        vstring.push_back(s1);
    }

    return vstring;
}

clientdata converdatatorecord(string line , string spreeator = "#//#") {  

    vector<string> vstring;
    clientdata cd;

    vstring = split(line, spreeator);

    cd.acountnum = vstring[0];
    cd.pincode = vstring[1];
    cd.name = vstring[2];
    cd.phone = vstring[3];
    cd.acountbalance= stod(vstring[4]); 

    return cd;
}

vector<clientdata> loadclientdatafromfile(string filename) {
    
    vector<clientdata> vstring;
    vector<string> s;
    clientdata cd;
    fstream myfile;

    myfile.open(filename, ios::in);

    if (myfile.is_open()) {

        string line;
        while (getline(myfile, line)) {


            cd = converdatatorecord(line);

            vstring.push_back(cd);

            


        }myfile.close();



    }

    return vstring;
}

void searchaccount(vector<clientdata> cd) {

    string searchaccount;
    bool found = false;
    cout << "please enter account number? ";
    cin >> searchaccount;

    for (clientdata &c : cd) {

        if (searchaccount == c.acountnum) {

            cout << "\nthe following details of client is: \n" << endl;

            cout << "account number " << c.acountnum << endl; 
            cout << "ping code " << c.pincode << endl; 
            cout << "name " << c.name << endl; 
            cout << "phone " << c.phone << endl; 
            cout << "account balance " << c.acountbalance << endl;
            found = true;
            break;
        }
        

    }
    if (!found) {
        cout << "\nnot found client with " << searchaccount << endl; 
    }
}


int main()
{
    vector<clientdata> vclient;
    vclient = loadclientdatafromfile(Clint_filename);

    searchaccount(vclient);
    
  
    
    return 0;
}

