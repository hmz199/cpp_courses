
#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std; 


enum emainmenue {show =1 , add =2, del=3, update=4, finduser=5,transaction=6,endf=7};  

struct sclient {
     
    string accountnumber;
    string pincode;
    string name;
    string phone;
    double balance;
    bool markuser = false;
};

vector<sclient> bringdatafromfile(string filename);

const string filename = "project.txt";

// add client ----------------------------------------------------------------

bool clientexist(string account, vector<sclient>& vstring) {

    for (sclient& c : vstring) {

        if (account == c.accountnumber) {

            return true;
        }
    }
    return false;
}

sclient readclient() {  

    sclient client;
    cout << "--------------------------\n";
    cout << "    add new client        \n";
    cout << "--------------------------\n";
    cout << "adding new Client\n\n";

    vector<sclient>vclient;
    vclient = bringdatafromfile(filename);  
    
   
    cout << "enter account number? ";
    getline(cin >> ws, client.accountnumber);

    while(clientexist(client.accountnumber, vclient)) { 

        printf("\n\nclient %s is exist entar other account", client.accountnumber.c_str()); 
        getline(cin >> ws, client.accountnumber);   
    }
     

    cout << "enter pin code? ";
    getline(cin, client.pincode);

    cout << "enter name? ";
    getline(cin, client.name);

    cout << "enter phone? ";
    getline(cin, client.phone);

    cout << "enter balance ";
    cin >> client.balance;

    return client;

}

string makeclinerecord(sclient client, string spreator = "#//#") {

    string record;

    record += client.accountnumber + spreator;
    record += client.pincode + spreator;
    record += client.name + spreator;
    record += client.phone + spreator;
    record += to_string(client.balance);

    return record;
}

void addclientrecordtofile(string line,string filename) {

    fstream myfile;

    myfile.open(filename, ios::out | ios::app);

    if (myfile.is_open()) {

        myfile << line << endl;

    }myfile.close();
}
 
void addclient() { 
    vector<sclient>vclisnt;
    sclient client;
    client = readclient();
    addclientrecordtofile(makeclinerecord(client), filename);
     
}

void addclients() {
    char answer;

    do
    {
        system("cls");
        addclient();
        cout << "\nclient add it susessfully, do you want to add more client? y/n ";
        cin >> answer;

    } while (answer == 'y');


}

// show client -----------------------------------------------------------------
vector<string> split(string line, string sperator = "#//#") { 

    vector<string> vstring;
    string word;
    while (line.find(sperator) != string::npos) {
        word = line.substr(0, line.find(sperator));

        if (word != " ") {

            vstring.push_back(word);

        }

        line.erase(0, line.find(sperator) + sperator.length());

    }if (line != " ") {

        vstring.push_back(line);
    }

    return vstring;

} 

sclient makerecordClient(string line) {

    vector<string> vstring;
    sclient client;

    vstring = split(line, "#//#");

    client.accountnumber = vstring[0];
    client.pincode = vstring[1];
    client.name = vstring[2];
    client.phone = vstring[3];
    client.balance = stod(vstring[4]); 

    return client;

}

vector<sclient> bringdatafromfile(string filename) {  

    fstream myfile; 
    vector<sclient> vstring;

    myfile.open(filename, ios::in);

    if (myfile.is_open()) {
        string line;
        sclient client;
        while (getline(myfile, line)) {

            client = makerecordClient(line);
            vstring.push_back(client);        }

    }myfile.close();

    return vstring; 
    
}

void showclients(sclient client) {

    cout << "| " << setw(15) << left << client.accountnumber;
    cout << "| " << setw(10) << left << client.pincode;
    cout << "| " << setw(20) << left << client.name;
    cout << "| " << setw(15) << left << client.phone;                     
    cout << "| " << setw(15) << left << client.balance; 
}

void showclientsmenue() {

 
    vector<sclient> vClients;

    vClients = bringdatafromfile(filename);
    

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(15) << "Phone";
    cout << "| " << left << setw(15) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (sclient Client : vClients)
    {
        showclients(Client); 
        cout << endl; 

    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;


}

string readuser() {

    string acount;
    cout << "plese enter acount number? ";
    cin >> acount;

    return acount;
}

void printuserdetils(sclient c) {

    cout << "\n\nthe following details of client is: \n";
    cout << "----------------------------------------------\n";

    cout << "account number " << c.accountnumber << endl;
    cout << "ping code " << c.pincode << endl;
    cout << "name " << c.name << endl;
    cout << "phone " << c.phone << endl;
    cout << "account balance " << c.balance << endl;
    cout << "----------------------------------------------\n";
}
// search client client ------------------------------------------------------------

bool searchclient(string account, vector<sclient>& vstring,sclient &clientdata) {

    for (sclient &c : vstring) {

        if (account == c.accountnumber) {
            
            clientdata = c;
            return true;
        }
    }
    return false;
}

void searchclient_() { 

    cout << "----------------------------\n";
    cout << "         search client        \n";
    cout << "----------------------------\n\n\n";

    vector<sclient> vstring;
    sclient clientdata;
    string read = readuser(); 

    vstring = bringdatafromfile(filename);  

    

    if (searchclient(read, vstring, clientdata)) {

        printuserdetils(clientdata);
    }
    else {
        cout << "\n\nclient not found! ";
    }
   
}

// delete client ------------------------------------------------------------------

bool markuser(string account, vector<sclient>& vstring) {

    for (sclient& c : vstring) {

        if (account == c.accountnumber) {

            c.markuser = true;
            return true;
        }
    }
    return false;
}

vector<sclient> saveallinfile(vector<sclient> client,string filename) {

    fstream myfile;

    myfile.open(filename, ios::out);

    if (myfile.is_open()) {
        string line;

        for (sclient& c : client) {

            if (c.markuser == false) {

                line = makeclinerecord(c);
                myfile << line << endl;
            }
        }
    }myfile.close();

    return client;
}

bool deleteuser(vector<sclient>& client,string account) {
    sclient c;
    char answer;

    if (searchclient(account, client, c)) {


        printuserdetils(c);

        cout << "\n\nyare you sure you want to delete this client? y/n ";
        cin >> answer;

        if (answer == 'y') {

            markuser(account, client);
            saveallinfile(client, filename);

            cout << "\n\nclient delete it susessfully";

            
            return true;
        }

    }
    else {
        cout << "\nacount with num " << account << " not found! ";
        return false;
    }


    
}

void deleteuserbaneer() {

    vector<sclient>client;
    client = bringdatafromfile(filename); 
    cout << "----------------------------\n";
    cout << "         delete user        \n";
    cout << "----------------------------\n\n\n";

    string read = readuser();
    deleteuser(client, read);
}

// update client -----------------------------------------------------------

sclient readupdateclient(string accountnumber) {

    sclient client;

    client.accountnumber = accountnumber;


    cout << "enter pin code? "; 
    getline(cin >> ws, client.pincode);  

    cout << "enter name? "; 
    getline(cin, client.name); 

    cout << "enter phone? "; 
    getline(cin, client.phone); 

    cout << "enter balance "; 
    cin >> client.balance; 

    return client;
}

void updateclientdata(vector<sclient>& vclient,string acountnumber) {
    char answer;
    sclient client;
    if (searchclient(acountnumber, vclient, client)) {

        printuserdetils(client);


        cout << "\n\nare you sure you want to update this client? y/n? ";
        cin >> answer;
        cout << endl;

        if (answer == 'y') {

            for (sclient& c : vclient) {

                if (c.accountnumber == acountnumber) {

                    c = readupdateclient(acountnumber);
                    break;
                    
                }
            }
            saveallinfile(vclient, filename);   
            cout << "\n\nclient update susccessfully ";

        }
        else {
            cout << "client not found ";
        }
    }
}

void updateclient() {

    cout << "----------------------------\n";
    cout << "         update user        \n";
    cout << "----------------------------\n\n\n";

    vector<sclient> client;
    client = bringdatafromfile(filename);  
    string read = readuser();
    updateclientdata(client, read); 
} 

//transaction

void transactionmenue(); 

enum etransmenue {Deposit=1,Widthsraw=2,totalbalance=3,mainmenue=4};

bool deposit() {  


    cout << "----------------------------\n";
    cout << "         deposit screen        \n";
    cout << "----------------------------\n\n\n";

    vector<sclient> client;
    client = bringdatafromfile(filename);

    sclient c;

    string read = readuser();
    if (searchclient(read, client, c)) { 

        printuserdetils(c);

        double num;
        cout << "plese enter deposit amout? ";
        cin >> num; 

        while (num < 0) {
            cout << "plese enter deposit amount bigger than zero? ";
            cin >> num;
        }

        char answer;
        cout << "\n\nare you sure you want to preform this tranaction? y/n ?";
        cin >> answer; 

        if (answer == 'y') {

            for (sclient& cd : client) {

                if (cd.accountnumber == read) {

                    cd.balance += num;
                    cout << "done sucssefully new balance " << cd.balance;
                    break;
                }
            }
            saveallinfile(client,filename);
            return true;
        }
    }
    else {
        cout << "client not found !";
        return false;
    }

}

void mainmenu();   

bool Widthdraw() { 


    cout << "----------------------------\n";
    cout << "         widthdraw screen       \n";
    cout << "----------------------------\n\n\n";
    vector<sclient> client;
    client = bringdatafromfile(filename);

    sclient c;

    string read = readuser();
    while (!searchclient(read, client, c)) {

        cout << "client with [" << read << "] dose not exist\n";
        read = readuser();
    }

        printuserdetils(c);

        double num;
        cout << "plese enter widthdraw? amount ";
        cin >> num;

        while (num > c.balance) {
            cout << "amount exeeds the balance , you can widthdraw up to :" << c.balance << endl;
            cout << "plese enter widthdraw? amount ";
            cin >> num;
        }

        char answer;
        cout << "\n\nare you sure you want to preform this tranaction? y/n ?";
        cin >> answer;

        if (answer == 'y') {

            for (sclient& cd : client) {

                if (cd.accountnumber == read) {

                    cd.balance -= num;
                    cout << "done sucssefully new balance " << cd.balance;
                    break;
                }
            }
            saveallinfile(client, filename);
            return true;
        }

        return false;
    }

void printbalances(sclient client) {

    cout << "| " << setw(15) << left << client.accountnumber;
    cout << "| " << setw(20) << left << client.name;
    cout << "| " << setw(15) << left << client.balance;
}

void printblanceslistmenue() {

    vector<sclient> vClients; 
    vClients = bringdatafromfile(filename);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ")Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(15) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (sclient Client : vClients)
    {
        printbalances(Client); 
        cout << endl;

    }
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

int transactionchoice() {

    int answer;
    cout << "choose what do you want to do? [1-4]? ";
    cin >> answer;

    return answer;
}

void gobacktomainmenuet() {

    cout << "\n\n\npress any key to go back to main menue...";
    system("pause>0");
    transactionmenue();
}

void transactionstart(etransmenue e) {

    switch (e)
    {
    case Deposit:
        system("cls");
        deposit();
        gobacktomainmenuet();
        break;
    case Widthsraw:
        system("cls");
        Widthdraw();
        gobacktomainmenuet();

        break;
    case totalbalance:
        system("cls");
        printblanceslistmenue();
        gobacktomainmenuet();
        break;
    case mainmenue:
        system("cls"); 
        mainmenu();
        break;
    default:
        break;
    }
}

void transactionmenue() {

    system("cls");
    cout << "==========================================\n";
    cout << "              main menue screen              \n";
    cout << "==========================================\n";
    cout << "\t[1] Deposit\n";
    cout << "\t[2] Widthdraw \n";
    cout << "\t[3] total blances\n";
    cout << "\t[4] main menue \n";
    cout << "==========================================\n";

    transactionstart((etransmenue)transactionchoice());

}

// exit program 

void endprogram() {

    cout << "----------------------------\n";
    cout << "         end program        \n";
    cout << "----------------------------\n\n\n";
}

//main menu 

emainmenue chosenum() {

    int num;
    cout << "choose what do you want to do ? [1 to 7] ? ";
    cin >> num;

    return (emainmenue)num;
}

void gobacktomainmenue() {

    cout << "\n\n\npress any key to go back to main menue...";
    system("pause>0");
    mainmenu();
}

void startprogram(emainmenue emenue) {

        switch (emenue)
        {
        case show:
            system("cls");
            showclientsmenue();
            gobacktomainmenue();


            break;

        case add:
            system("cls");

            addclients();
            gobacktomainmenue();

            break;

        case del:
            system("cls");
            deleteuserbaneer();
            gobacktomainmenue();

            break;

        case update:
            system("cls");
            updateclient();
            gobacktomainmenue();
            break;

        case finduser:
            system("cls");
            searchclient_();
            gobacktomainmenue();
            break;
        case transaction: 
            system("cls");
            transactionmenue();
            
            break;
        case endf: 
            system("cls");
            endprogram();
            break;
        default:
            break;
        }
    
}

void mainmenu() {

    system("cls");
    cout << "==========================================\n";
    cout << "              main menue screen              \n";
    cout << "==========================================\n";
    cout << "\t[1] show client list\n";
    cout << "\t[2] add new client \n";
    cout << "\t[3] deletet client\n";
    cout << "\t[4] update client\n";
    cout << "\t[5] find client \n";
    cout << "\t[6] transaction \n";
    cout << "\t[7] exit\n";
    cout << "==========================================\n";

    startprogram((emainmenue)chosenum());
}



int main()
{
    
    mainmenu();
    
    
    
    return 0;
}

