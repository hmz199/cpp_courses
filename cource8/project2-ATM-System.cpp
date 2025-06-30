#include <iostream>
#include <iomanip> // for setw() 
#include <vector>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;


struct sclient {

	string accountnumber;
	string pincode;
	string name;
	string phone;
	double balance;
	bool markuser = false;
};

enum atmmenuenumchoice { Quick_widthdraw = 1, Normal_widthdraw = 2, Deposit = 3, check_balance = 4, Logout = 5 };
enum quickwithdraw{twinty=1,fifty=2,onehundred=3,twohundred=4,fouhundred=5,sixhundred=6,eighthundred=7,onethousen=8,exitofprogram=9};
const string filename = "project.txt";
sclient currentuser;

void showbalnce();

string makesclientrecord(sclient client,string sepreator = "#//#") {

	string line;

	line += client.accountnumber + sepreator;
	line += client.pincode + sepreator;
	line += client.name + sepreator;
	line += client.phone + sepreator;
	line += to_string(client.balance);

	return line;
}

vector<string> split(string line,string delmeter = "#//#") {
	vector<string> l;
	string s;
	
	while (line.find(delmeter) != string::npos) {

		s = line.substr(0, line.find(delmeter));

		if (s != "") {

			l.push_back(s);
		}

		line.erase(0, line.find(delmeter) + delmeter.length()); 
	}
	if (line != "") {

		l.push_back(line);
	}

	return l;
}

sclient makerecordstoData(string line) {

	vector<string> s;
	sclient l;
	s = split(line);

	l.accountnumber = s[0];
	l.pincode = s[1];
	l.name = s[2];
	l.phone = s[3];
	l.balance = stoi(s[4]); 
	
	return l; 
} 

vector<sclient> bringdatafromfile(string filename) {

	fstream myfile;
	vector<sclient>l;
	myfile.open(filename,ios::in);

	if (myfile.is_open())
	{
		string line;
		sclient info; 

		while (getline(myfile, line)) {

			info = makerecordstoData(line);
			l.push_back(info);

		}
	}
	else {

		cout << "file have problem ";
	}
	myfile.close();

	return l;
}

bool savedatatofile(vector<sclient> client) {
	
	fstream myfile;

	myfile.open(filename,ios::out);

	if (myfile.is_open()) {

		string line;

		for (sclient& c : client) {

			line = makesclientrecord(c);

			myfile << line << endl;
		}
		myfile.close();
		return true;
	}
	else {
		cout << "error in opreation! ";
		return false;
	}
	

}

void startsystem();

// pause and exit

void atmmainmenue(); 

void pauseandexit() {

	cout << "press any key to exit.... ";
	system("pause>0");
	atmmainmenue();
}

// deposit -----------------------------------

void depositscreen() {

	cout << "-----------------------\n";
	cout << "     deposit screen   \n";
	cout << "-----------------------\n";

}

bool depositopreation() {

	vector<sclient> client; 

	client = bringdatafromfile(filename);
	
	int amount;

	do
	{

	cout << "\nenter postive Amount? ";
	cin >> amount;

	} while (amount <= 0);

	char answer;
	cout << "\nare you sure you want to preform this tranaction? y/n ? ";
	cin >> answer;
	
	if (answer == 'y') {

		for (sclient& c : client) {

			if (c.accountnumber == currentuser.accountnumber) {

				c.balance += amount;
				currentuser.balance = c.balance;
				savedatatofile(client);
				cout << "Done successfully. new balance is: " << currentuser.balance << endl;
				return true;
			}
		}
	}
	return false;
}

void deposit() {

	depositscreen();
	depositopreation();
}

//normal withdra

void normalwithdrawscreen() { 

	cout << "-----------------------\n";
	cout << "     normal withdraw    \n";
	cout << "-----------------------\n";

}

bool withdrawopreation() {

	vector<sclient> client;

	client = bringdatafromfile(filename);

	int num;
	do
	{
		cout << "\nenter en amount  multiple of 5' s ?";
		cin >> num;

	} while (num % 5 != 0);


	char answer;
	cout << "\nare you sure you want to make this transaction? y/n ?";
	cin >> answer;

	if (answer == 'y') {

		for (sclient& c : client) {

			if (c.accountnumber == currentuser.accountnumber) {

				if (c.balance > num) {

					c.balance -= num;
					currentuser.balance = c.balance;
					savedatatofile(client);
					cout << "done successfully. new balance is : " << currentuser.balance << endl;
					return true;

				}
				else {
					cout << "you dont have enough balance ";
				}
			}
		}

	}
	return false;
	 
}

void withdraw() {

	normalwithdrawscreen();
	withdrawopreation();
}


//qiuck widthdraw-----------------------------------------------------------------------
int getbalance();

quickwithdraw chosewithdraw() {

	int num;
	cout << "choose what to withdraw from[1] to [8] ?";
	cin >> num;

	return (quickwithdraw)num; 
}

void widthdrawfromatm(quickwithdraw num) {

	int amount = 0;
	vector<sclient> client;
	client = bringdatafromfile(filename);

	switch (num)
	{
	case twinty:
		amount = 20;
		break;
	case fifty:
		amount = 50;
		break;
	case onehundred:
		amount = 100;
		break;
	case twohundred:
		amount = 200;
		break;
	case fouhundred:
		amount = 400;
		break;
	case sixhundred:
		amount = 600;
		break;
	case eighthundred:
		amount = 800;
		break;
	case onethousen:
		amount = 1000;
		break;
	case exitofprogram:
		system("cls");
		atmmainmenue(); 
		
		break;
	default:
		break;
	}

	char answer;
	cout << "are you sure you want to preform this transaction? y/n ? ";
	cin >> answer;

	if (answer == 'y') {
		for (sclient& c : client) {
			if (c.accountnumber == currentuser.accountnumber) {
				if (c.balance >= amount) {

					c.balance -= amount;
					currentuser.balance = c.balance;

					if (savedatatofile(client)) {

						cout << "done successfuly. new balance is: " << currentuser.balance << endl;
					}
					else {
						// Revert if save failed
						c.balance += amount;
						currentuser.balance = c.balance;
						cout << "Transaction failed - could not save!" << endl;
					}
					break;
				}
				else {
					cout << "\nnot funds in account soory";
				}
			}
		}
	}
}
	

void Quickwidthdrawmenue() {

	system("cls");
	cout << "=========================================================\n";
	cout << "                  Qucik withdraw                         \n";
	cout << "=========================================================\n";
	cout << "                [1] 20             [2] 50                \n";
	cout << "                [3] 100            [4] 200               \n";
	cout << "                [5] 400            [6] 600               \n";
	cout << "                [7] 800            [8] 1000              \n";
	cout << "                [9] Exit                                 \n";
	cout << "=========================================================\n";
	cout << "you balance is " << getbalance() << endl;
	widthdrawfromatm(chosewithdraw());
}

// check balance -------------------------------------------------------------------------

void checkbalancescreen() {

	cout << "-------------------------------------\n";
	cout << "     Check balance screen      \n";
	cout << "-------------------------------------\n";

}

int getbalance() {
	int balance = 0;
	vector<sclient> l;

	l = bringdatafromfile(filename);

	for (sclient& c : l) {


		if (c.accountnumber == currentuser.accountnumber) {

			balance = c.balance;
			break;
		}

	}

	return balance;  

}

void showbalnce() {

	checkbalancescreen();

	cout << "you balance is " << getbalance() << endl; 
}

// login screen --------------------------------------------------------------------------

bool checkuser(string filename) {

	vector<sclient> l;

	l = bringdatafromfile(filename);

	for (sclient& c : l) {

		if (c.accountnumber == currentuser.accountnumber && c.pincode == currentuser.pincode) {
			
			return true;
			break;
		}
		
	}
	return false;
	
}

void loginscreen() {

	cout << "-----------------------\n";
	cout << "     login screen      \n";
	cout << "-----------------------\n";

}

void EnterCredLoginScreen() {

	

	sclient log; 
	bool loginsuccessful = true;
	do
	{
		system("cls");
		loginscreen(); 
		if (!loginsuccessful) {

			cout << "invalid account number! \n";
		}

		cout << "enter account number? ";
		cin >> log.accountnumber; 
		 
		cout << "enter pin ";
		cin >> log.pincode;

		currentuser = log; 

		loginsuccessful = checkuser(filename);

		if (loginsuccessful) { 

			cout << "login successful , welcome [" << currentuser.accountnumber << "]" << endl; 
		}

	} while (!loginsuccessful);

}

// Atm main menue-------------------------------------------------------------------------

atmmenuenumchoice chosenum() {
	short num;
	cout << "Choose what do you want to do? [1 to 5]? ";
	cin >> num;


	return (atmmenuenumchoice)num;
}

void systemstruct(atmmenuenumchoice c);
void atmmainmenue() {

	system("cls");
	cout << "=========================================================\n";
	cout << "                  ATM main menue                         \n";
	cout << "=========================================================\n";
	cout << "                [1] Quick widthdraw.\n";
	cout << "                [2] Normal widthdraw.\n";
	cout << "                [3] Deposit.\n";
	cout << "                [4] check balance.\n";
	cout << "                [5] Logout.\n";
	cout << "=========================================================\n";
	systemstruct(chosenum());
}

void systemstruct(atmmenuenumchoice c) {

	switch (c)
	{
	case Quick_widthdraw:
		system("cls");
		Quickwidthdrawmenue();
		pauseandexit();
		break;
	case Normal_widthdraw:
		system("cls");
		withdraw();
		pauseandexit();
		break;
	case Deposit:
		system("cls");
		deposit();
		pauseandexit();
		break;
	case check_balance:
		system("cls");
		showbalnce();
		pauseandexit();
		break;
	case Logout:
		system("cls");
		startsystem();
		break;
	default:
		break;
	}
}

void startsystem() {
	
	EnterCredLoginScreen();
	atmmainmenue();
}




int main()  
{
	startsystem();
}