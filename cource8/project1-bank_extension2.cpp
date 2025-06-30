#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;


enum emainmenue { show = 1, add = 2, del = 3, update = 4, finduser = 5, transaction = 6, manage_users =7 , logout=8 };

struct sclient {

    string accountnumber;
    string pincode;
    string name;
    string phone;
    double balance;
    bool markuser = false; 
};




enum emanage_users { list_user = 1, add_user = 2, del_user = 3, update_user = 4, find_user = 5, mainmenue_user = 6 };
enum user_permission { pall = -1, plist = 1, padd = 2, pdel = 4, pupdate = 8, pfind = 16, ptrans = 32, pmanage_users = 64 };

struct login {

    string username;
    string password;
    int permission;
    bool deleteuser = false;

};


login currentuser;
bool checklogin(login enterduser);

bool permissionaccess(user_permission per) {

    if (currentuser.permission == user_permission::pall) {
        return true;
    }

    if ((currentuser.permission & per) == per) {
        return true;
    }
    else {
        return false;
    }

}

void gobacktomainmenue();

vector<login> bringusersfromfile(string filename);

const string filename_users = "users.txt";


vector<sclient> bringdatafromfile(string filename);

const string filename = "project.txt";

void accessdeniedmassage() {

    cout << "Access denied !";
}

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

    while (clientexist(client.accountnumber, vclient)) {

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

void addclientrecordtofile(string line, string filename) {

    fstream myfile;

    myfile.open(filename, ios::out | ios::app);

    if (myfile.is_open()) {

        myfile << line << endl;

    }myfile.close();
}

void addclient() {
    sclient client;
    client = readclient();
    addclientrecordtofile(makeclinerecord(client), filename);

}

void addclients() {

    if (!permissionaccess(user_permission::padd)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
  
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
            vstring.push_back(client);
        }

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

    if (!permissionaccess(user_permission::plist)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
   

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

bool searchclient(string account, vector<sclient>& vstring, sclient& clientdata) {

    for (sclient& c : vstring) {

        if (account == c.accountnumber) {

            clientdata = c;
            return true;
        }
    }
    return false;
}

void searchclient_() {

    if (!permissionaccess(user_permission::pfind)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
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

vector<sclient> saveallinfile(vector<sclient> client, string filename) {

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

bool deleteuser(vector<sclient>& client, string account) {


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

    if (!permissionaccess(user_permission::pdel)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
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

void updateclientdata(vector<sclient>& vclient, string acountnumber) {
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

    if (!permissionaccess(user_permission::pupdate)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
   
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

enum etransmenue { Deposit = 1, Widthsraw = 2, totalbalance = 3, mainmenue = 4 };

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
            saveallinfile(client, filename);
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

    if (!permissionaccess(user_permission::ptrans)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
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


//main menu 

emainmenue chosenum() {

    int num;
    cout << "choose what do you want to do ? [1 to 8] ? ";
    cin >> num;

    return (emainmenue)num;
}

void gobacktomainmenue() {

    cout << "\n\n\npress any key to go back to main menue...";
    system("pause>0");
    mainmenu();
}



//-----------------------------------------------------------------------------------------------------
//login

void loginscreen() {

    cout << "----------------------------\n";
    cout << "         login screen        \n";
    cout << "----------------------------\n";

}
login loginaccess() {

    login l;

    cout << "enter you username ";
    getline(cin >> ws, l.username);
    cout << "enter you password ";
    getline(cin, l.password);

    return l; 
}

bool checklogin(login enterduser) {
    vector<login> user;

    user = bringusersfromfile(filename_users);

    for (login& u : user) {

        if (u.username == enterduser.username && u.password == enterduser.password) {

            enterduser = u;
            ::currentuser = enterduser;
            return true;
        }
    }

    return false;
}

vector<login> bringusersfromfile(string file);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//manage users

bool findmange_user(string user, vector<login>& users, login& l);
 
void startmanageuser(emanage_users users);  

emanage_users chosenumfomanageusers() {

    int num;
    cout << "choose what do you want to do ? [1 to 6] ? ";
    cin >> num;

    return (emanage_users)num;
}

void manageusers() {

    if (!permissionaccess(user_permission::pmanage_users)) {

        accessdeniedmassage();
        gobacktomainmenue();
    }
    system("cls");
    cout << "==========================================\n";
    cout << "              main menue screen              \n";
    cout << "==========================================\n";
    cout << "\t[1] List users\n";
    cout << "\t[2] add new user \n";
    cout << "\t[3] delete user \n";
    cout << "\t[4] update user \n";
    cout << "\t[5] find user \n";
    cout << "\t[6] main menue \n";
    cout << "==========================================\n";
    startmanageuser((emanage_users)chosenumfomanageusers());
    
}

void gobacktomanageuser() {

    cout << "\n\npress any key to go back to manage menue... ";
    system("pause>0");
    manageusers();
}

// list user

void printuserlist(login l) {

    cout<< "|"<< setw(20) << left  << l.username;
    cout<< "|"<< setw(20) << left  << l.password;
    cout << "|" << setw(10) << left << l.permission << endl; 

}

void mangeuserlist() {

    vector<login> l;

    l = bringusersfromfile(filename_users);

    cout << "                     users List (" << l.size() << ") user(s)     \n" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout<<"|"<< setw(20)<< left  << "user name"    ;
    cout<<"|"<< setw(20)<< left  << "password"     ;
    cout<<"|"<< setw(10)<< left  << "permissions"  ;
    cout << "\n--------------------------------------------------------------------------------------------------\n";

    for (login& u : l) {

        printuserlist(u); 
    }
    cout << "\n--------------------------------------------------------------------------------------------------\n";


}

//adduser

int readpermissionstoset() { 
    
    int pnum = 0;
    char answer;

    cout << "\n whar permission you want to give? \n\n"; 

    cout << "do you want to give all permission? y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        return -1;
    }

    cout << "\ndo you want to give list client y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::plist;
    }

    cout << "\ndo you want to give add client y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::padd;
    }

    cout << "\ndo you want to give delete client y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::pdel;
    }

    cout << "\ndo you want to give find client y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::pfind;
    }

    cout << "\ndo you want to give manage users y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::pmanage_users; 
    }
     
    cout << "\ndo you want to give transaction client y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::ptrans;
    }
    cout << "\ndo you want to give update client y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {

        pnum += user_permission::pupdate; 
    }

    return pnum; 
}

login adduser() {

    login l;

    cout << "enter username? ";
    getline(cin >> ws, l.username);

    vector<login> users;
    users = bringusersfromfile(filename_users);
    login u; 
    while(findmange_user(l.username,users,u)) {

        cout << "user [" << l.username << "] is exist \n enter another user ";
        getline(cin >> ws, l.username);
    }

    cout << "enter password? ";
    getline(cin >> ws, l.password);

    l.permission = readpermissionstoset();

    return l;
}

string makeusersrecord(login l,string sperator = "#//#") {

    string users ;

    users += l.username + sperator;
    users += l.password + sperator;
    users += to_string(l.permission);

    return users;
}

void addusertofile(string userrecord,string filename_users) {

    fstream myfile;

    myfile.open(filename_users,ios::app);

    if (myfile.is_open()) {

        myfile << userrecord << endl;
    }
    myfile.close();

}

void adduser_inmange() {

    char answer;
    do
    {

    login adduser_m = adduser();
    string user = makeusersrecord(adduser_m);
    addusertofile(user, filename_users);

    cout << "\n\n user addess succsessfully do you want to add more user? y/n? ";
    cin >> answer;

    } while (answer == 'y');
}

//find user

bool findmange_user(string user,vector<login>& users, login& l) {

    for (login& u : users) {

        if (user == u.username) {
            l = u;
            return true;
        }
    }
    return false;
}

void printuser(login l) {

    cout << "the following are the user details: \n";
    cout << "--------------------------------------\n";
    cout << "username :" << l.username << endl;
    cout << "password :" << l.password << endl;
    cout << "permissions: " << l.permission << endl;
    cout << "--------------------------------------\n\n\n";

}

void finduserscreen() { 

    cout << "----------------------------\n";
    cout << "         find user        \n";
    cout << "----------------------------\n";

}

string enteruser() {
    string name;
    cout << "enter user name ? ";
    getline(cin >> ws, name);

    return name;
}

void searchforuser() {

    vector<login> l;
    login user;

    l = bringusersfromfile(filename_users);
    finduserscreen();

    string usertosearch = enteruser();
    if (findmange_user(usertosearch,l,user)){

        printuser(user);  
    }
    else {

        cout << "user not found ";
    }
}

//deleteuser

vector<string> splitinusers(string line , string sperator = "#//#") {

    vector<string> records;
    string r = "";
    while (line.find(sperator) != string::npos) {

        r = line.substr(0, line.find(sperator));

        records.push_back(r);

        line.erase(0, line.find(sperator) + sperator.length());
        
    }if (!line.empty()) {

        records.push_back(line);
    }

    return records;
}

login makerecordstouserdata(string records) {

    vector<string> vrecords;
    login usersdata;

    vrecords = splitinusers(records); 

    usersdata.username = vrecords[0];
    usersdata.password = vrecords[1];
    usersdata.permission = stoi(vrecords[2]);

    return usersdata; 

}

vector<login> bringusersfromfile(string filename) {

    fstream myfile;
    vector<login> users;
    myfile.open(filename, ios::in);//read node

    if (myfile.is_open()) {

        string line;
        login user;

        while (getline(myfile, line)) {

            user = makerecordstouserdata(line);
            users.push_back(user);
        }
    }myfile.close();

    return users;
}

bool markusers_mange(string user,vector<login>& users) {

    for (login& u : users) {

        if (user == u.username) {
            u.deleteuser = true;
            return true;
        }
    }
    return false;
}

void saveuserstofile(vector<login> v,string filename_users) {

    fstream myfile;
    myfile.open(filename_users, ios::out); 

    if (myfile.is_open()) {

        string line;

        for (login& l : v) {

            if (l.deleteuser == false) {

                line = makeusersrecord(l);

                myfile << line << endl;


            }
        }
        
    }myfile.close();

}

bool deleteuser() {

    vector<login> users;
    login l;
    users = bringusersfromfile(filename_users);   


    string user;
    cout << "plsese enter user name? ";
    cin >> user;

    if (findmange_user(user, users, l)) { 

        printuser(l);

        char answer;
        cout << "are you sure you want to delete user? y/n";
        cin >> answer;

        if (answer == 'y') {

            markusers_mange(user, users);
            saveuserstofile(users, "users.txt");
            return true;
        }
    }
    else {
        cout << "\n\nuser not found ";
        return false;
    }


}

// update user-----------------------------------------------------

login updateU(string acountname) {

    login user;
    user.username = acountname;

    cout << "enter new password plese ";
    cin >> user.password;

    user.permission = readpermissionstoset();


    return  user;
}

bool updateuser() {

    vector<login> l;
    login user;

    l = bringusersfromfile(filename_users);

    string username = enteruser();

    if (findmange_user(username, l, user)) {

        printuser(user);

        char answer;
        cout << "\n\nare you sure you want to update this user? y/n ? ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {

            for (login& u : l) {
                if (u.username == username) {

                    u = updateU(username);
                    break;
                }
            }

            saveuserstofile(l, filename_users);
            cout << "\n\nuser updated sucsessfully";
            return true;
        }

    }
    else {
        cout << "user not found ";
    }

    return false;
}

// start manage user
void startsystem();
void startmanageuser(emanage_users users) {

    switch (users)  
    {
    case list_user:
        system("cls");
        mangeuserlist();
        gobacktomanageuser();
        break;
    case add_user:
        system("cls");
        adduser_inmange();
        gobacktomanageuser();
        break;
    case del_user:
        system("cls"); 
        deleteuser();
        gobacktomanageuser();
        break;
    case update_user:
        system("cls");
        updateuser();
        gobacktomanageuser();
        break;
    case find_user:
        system("cls");
        searchforuser();
        gobacktomanageuser();
        break;
    case mainmenue_user:
        system("cls");
        mainmenu();
        break;
    default:
        break;
    }
}

//--------------------------------------------------------------------------------
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
            case manage_users:
                system("cls");
                manageusers();
                break;
            case logout:
                system("cls");
                startsystem(); 
            default:
                break;
            }
    

}

void login_user() {

    short attemp = 3; 
    bool loginSuccessful = true;
    do
    {
        system("cls");
        loginscreen();

        if (!loginSuccessful) {

            cout << "invalid username/or password\n";
        }

        login l =loginaccess(); 
        loginSuccessful=checklogin(l);

        if (loginSuccessful) {

            cout << "\nwelcome [" << l.username << "] loged in successfully\n";
            system("pause");
        }
        else {
            attemp--;
        }

    } while (!loginSuccessful && attemp >= 1);
  
    if (!loginSuccessful) {

        cout << "your trys finish to login";
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
  cout << "\t[7] Manage Users \n";
  cout << "\t[8] logout\n";
  cout << "==========================================\n";

   startprogram((emainmenue)chosenum()); 
   
}

void startsystem() {

    login_user();
    mainmenu();
}

int main() 
{

    startsystem(); 



    return 0;
}




