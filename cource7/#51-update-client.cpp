
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std; 


struct clientdata
{
    string acountnumber;
    string pincode;
    string name;
    string phone;
    double balance;
    bool markuser = false;
};

const string filename = "testfile.txt";

clientdata askclient() {

    clientdata client;

    cout << "plese enter client data: \n\n";
    
    cout << "enter account number: ";
    getline(cin >> ws, client.acountnumber);

    cout << "enter pincode: ";
    getline(cin, client.pincode);

    cout << "enter name: ";
    getline(cin, client.name);

    cout << "enter phone: ";
    getline(cin, client.phone);

    cout << "enter balance: ";
    cin >> client.balance;

    return client;
}

clientdata updateuser(string acountnumber) {

    clientdata client;

    client.acountnumber = acountnumber;

    cout << "\n\nenter pincode: ";
    getline(cin >> ws, client.pincode);  

    cout << "enter name: ";
    getline(cin, client.name);

    cout << "enter phone: ";
    getline(cin, client.phone);

    cout << "enter balance: ";
    cin >> client.balance;

    return client;
}

string makedataoneline(clientdata cd,string spreator = "#//#") {

    string line;

    line += cd.acountnumber + spreator;
    line += cd.pincode + spreator;
    line += cd.name + spreator;
    line += cd.phone + spreator;
    line += to_string(cd.balance);

    return line;
}

vector<string> split(string line, string spreator = "#//#") {

    vector<string> cd;
    string word;
    while (line.find(spreator) != string::npos) {

        word = line.substr(0, line.find(spreator));

        if (word != " ") {

            cd.push_back(word);
        }

        line.erase(0, line.find(spreator) + spreator.length());

    }if (line != " ") {

        cd.push_back(line);
    }

    return cd;
}


clientdata makerecordtodata(string line) {

    vector<string> cd;
    clientdata client;
    cd = split(line,"#//#");

    client.acountnumber = cd[0];
    client.pincode = cd[1];
    client.name = cd[2];
    client.phone = cd[3];
    client.balance = stod(cd[4]); 

    return client;

}

void printclient(clientdata Client) {

    cout << "\n\nThe following is the  client record:\n";
    cout << "\nAccout Number: " << Client.acountnumber;
    cout << "\nPinCode : " << Client.pincode;
    cout << "\nName : " << Client.name;
    cout << "\nPhone : " << Client.phone;
    cout << "\nAccount Balance: " << Client.balance << endl; 
}

void addclientTofile(string line, string filename) {

    fstream myfile;

    myfile.open(filename, ios::out | ios::app);

    if (myfile.is_open()) {

        myfile << line << endl;

    }myfile.close();

}


void addclient() {
    clientdata cd;
    cd = askclient();

    addclientTofile(makedataoneline(cd, "#//#"), filename);  
}

void addclients() {

    char answer;

    do
    {
        system("cls");

        addclient();

        cout << "\n\nclient add successfully ,do you want to add more clients: y/n ";
        cin >> answer; 

    } while (answer =='y');
}

vector<clientdata> readusersfromfile(string filename) {

    fstream myfile;
    clientdata c;
    vector<clientdata> client;
    string line;
    myfile.open(filename, ios::in);

    if (myfile.is_open()) {
        
        while (getline(myfile, line)) { 

            c = makerecordtodata(line);
            client.push_back(c);

    }
    }myfile.close();

    return client; 
}

void printrecord(clientdata Client) {

    cout << "| " << setw(15) << left << Client.acountnumber;
    cout << "| " << setw(10) << left << Client.pincode;
    cout << "| " << setw(40) << left << Client.name;
    cout << "| " << setw(12) << left << Client.phone;
    cout << "| " << setw(12) << left << Client.balance;

}

void printallclientdata(vector<clientdata> vClients) {

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
   
    
    for (clientdata Client : vClients)
    {
        printrecord(Client);
        cout << endl;
    }
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

bool findclient(vector<clientdata> client,string acountnumber,clientdata& cd) {

    for (clientdata& c : client) {

        if (acountnumber == c.acountnumber) {
            cd = c;
            return true;
        }
    }
    return false;
}

string readuser() {

    string user;

    cout << "please enter account number: ";
    cin >> user;


    return user;
}

bool markuser(vector<clientdata>& cd, string acountnumber) {

    for (clientdata& c : cd)
    {
        if (acountnumber == c.acountnumber) {

            c.markuser = true;
            return true;
        }
    }
    return false;
}

vector<clientdata> savedatatofile(string filname,vector<clientdata> cd) {

    fstream myfile;

    myfile.open(filename, ios::out);

    if (myfile.is_open()) {
        string line;
        for (clientdata c : cd) {

            if (c.markuser == false) {

                line = makedataoneline(c); 
                myfile << line << endl;
            }
        }
        myfile.close();
    }
    return cd;
}

void deleteuser(vector<clientdata> &cd, string acountnumber) {

    clientdata client;
    char answer;

    if (findclient(cd, acountnumber, client)) {
        
        printclient(client);


        cout << "\n\nare you sure you want to delete this client? y/n ";
        cin >> answer;
        
        if (answer == 'y') {

            markuser(cd, acountnumber);

            savedatatofile(filename, cd);

            //we make refresh becuase old data still inside the vector
            cd = readusersfromfile(filename);

            cout << "\n\nclient delete sucsessfully.";
        }
    }
    else {
        cout << "client not found.";
    }

}

bool updateclient(vector<clientdata> &cd, string acountnumber) {


    clientdata client;
    char answer;
    if (findclient(cd, acountnumber, client)) {

        printclient(client);


        cout << "\n\nare you sure you want to update this client? y/n ";
        cin >> answer;

        if (answer == 'y')
        {

            for (clientdata &c : cd)
            {

                if (c.acountnumber == acountnumber) 
                {

                    c = updateuser(acountnumber);
                    break;
                }

            }

            savedatatofile(filename, cd);

            cout << "\nclient update sucessfully";
            return true;
        }
    }
    else {
        cout << "\n client not found ";
        return false;
    }
}

int main()
{
    //addclients();
 
    
    /*vector<clientdata>c;
    c = readusersfromfile(filename); 
    clientdata client;
    string acount = readuser();

    if (findclient(c, acount, client)) {

        printclient(client);
    }
    else {

        cout << "acount not found: ";
    }*/

  vector<clientdata>c;  
    string read = readuser();  


    c = readusersfromfile(filename); 
     
    updateclient(c, read);  
    
    return 0;
}

