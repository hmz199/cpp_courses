
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
    bool markuser = false;
};

const string Clint_filename = "clients_data.txt";

clientdata userenterdetails() {
    
    cout << "add client detals : \n\n";
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

bool searchaccount(clientdata &c,string accountnumber) {

    vector<clientdata> data;

    data = loadclientdatafromfile(Clint_filename); 
   

    for (clientdata &client : data) { 

        if (accountnumber == client.acountnum) {
              
            c = client;
            return true;
        }
        

    }
    return false;
}

void deleteclient(vector<clientdata> cd, string accounnum) {


    for (int i = 0; i < cd.size(); i++) {

        if (cd[i].acountnum == accounnum) {

            cd.erase(cd.begin() + i);
        }
    }

}

void printclient(clientdata c) {
    cout << "\nthe following details of client is: \n" << endl;

    cout << "account number " << c.acountnum << endl;
    cout << "ping code " << c.pincode << endl;
    cout << "name " << c.name << endl;
    cout << "phone " << c.phone << endl;
    cout << "account balance " << c.acountbalance << endl;
}

bool markuser(vector<clientdata> &cd, string accountnum,clientdata client) {

    
    for (clientdata& c : cd) {

        if (accountnum == c.acountnum) {

            c.markuser = true;
            return true;
        }
    }
    return false;
}

string readuser() {

    string name;
    cout << "plese enter account number: ";
    cin >> name;


    return name;
}

vector<clientdata> savedatatofile(string filename,vector<clientdata> cd) {

    fstream myfile;

    myfile.open(filename, ios::out);

    if (myfile.is_open()) {

        string line;

        for (clientdata c : cd) {

            if (c.markuser == false) {

                line = makedataOneLine(c);
                myfile << line << endl;
            }
        }
        myfile.close();
    }
    return cd;
}

bool deleteaccount(string acountnumber, vector<clientdata> cd) {

    clientdata client;
    char answer;
    if (searchaccount(client, acountnumber)) {

        printclient(client);


        cout << "\n\n are you sure you want to delete this clients y/n ? ";
        cin >> answer; 

        if (answer == 'y') {
            markuser(cd, acountnumber, client);

            savedatatofile(Clint_filename, cd);

            cout << "\n\nclient delete sucsses ";
            return true;
        }
    }
    else {
        cout << "\nclient with account number " << acountnumber << " is not found";
        return false;
    }

}




int main()
{
   

      

    vector<clientdata> cd; 
    clientdata c; 
    cd = loadclientdatafromfile(Clint_filename); 
    string read = readuser(); 

    deleteaccount(read, cd);

    return 0;
}

