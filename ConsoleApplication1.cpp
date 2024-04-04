#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<pair<int, string>> trans;
static long tbal = 10000000;
const int atmid = 108;
const int atmpass = 10540;
static bool state = true;
const int bnkpass = 4947;

class user{
public:
    int accn;
    string name;
    long ifsc;
    string branch;
    int balance;
    int bankid;
    string bname;
    long cardno;
    int pin;
    void addusr(int p1, string p2, long p3, string p4, int p5, int p6, string p7, long p8, int p9) {
        accn = p1;
        name = p2;
        ifsc = p3;
        branch = p4;
        balance = p5;
        bankid = p6;
        bname = p7;
        cardno = p8;
        pin = p9;
    }
};

map<long,user> usrdet;

void usr() {
    int cn, ps;
    bool b = false;
    cout << "HELLO USER ;)" << endl;
    cout << "KINDLY ENTER CARD NUMBER : ";
    cin >> cn;
    cout << "ENTER PASSWORD : ";
    cin >> ps;
    auto &x=usrdet[cn];
    if (x.pin == ps) {
        b = true;
    }
    else {
        cout << "USERNAME OR PASSWORD IS INVALID";
        cout << "-----------------------------------------------------" << endl;
        return;
    }
    if (b) {
        int opt;
        cout << "1.CHECK BALANCE" << endl << "2.WITHDRAW" << endl << "3.DEPOSIT" << endl << "4.QUIT" << endl;
        cin >> opt;
        switch (opt) {
        case 1:
        {
            cout << "YOUR CURRENT BALANCE : " << x.balance << endl;
            cout << "-----------------------------------------------------" << endl;
            pair<int, string> p;
            p.first = x.accn;
            p.second = "CHECKED BALANCE";
            trans.push_back(p);
            break;
        }
        case 2:
        {
            int wam;
            cout << "ENTER AMOUNT TO WITHDRAW : ";
            cin >> wam;
            if (wam <= x.balance && wam<=tbal) {
                x.balance -= wam;
                tbal -= wam;
                cout << "CASH WITHDRAWN SUCCESSFULLY" << endl << "CURRENT AVAILABLE BALANCE : " << x.balance << endl;
                cout << "-----------------------------------------------------" << endl;
                pair<int, string> p;
                p.first = x.accn;
                p.second = ("WITHDRAWN AMOUNT OF RUPEES " + to_string(wam));
                trans.push_back(p);

            }
            else {
                cout << "INSUFFICIENT FUNDS" << endl;
                cout << "-----------------------------------------------------" << endl;
            }
            break;
        }
        case 3:
        {
            int dam;
            cout << "ENTER AMOUNT TO DEPOSIT : ";
            cin >> dam;
            x.balance += dam;
            tbal += dam;
            cout << "AMOUNT DEPOSITED SUCCSSFULLY" << endl << "CURRENT AVAILABLE BALANCE : " << x.balance << endl;
            cout << "-----------------------------------------------------" << endl;
            pair<int, string> p;
            p.first = x.accn;
            p.second = ("CREDITED AMOUNT OF RUPEES " + to_string(dam));
            trans.push_back(p);
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout << "INVALID OPTION" << endl;
            cout << "-----------------------------------------------------" << endl;
        }
        }

    }
}

void admn() {
    int ap;
    cout << "KINDLY ENTER PASSWORD : ";
    cin >> ap;
    if (ap == atmpass) {
        int on;
        cout << "HELLO ADMIN WHAT IS YOUR OPERATION ?" << endl;
        cout << "1.REFILL MONEY" << endl << "2.CHECK ATM BALANCE" << endl << "3.SHOW HISTORY" << endl << "4.FREEZE ATM" << endl << "5.QUIT" << endl;
        cin >> on;
        switch (on) {
        case 1:
        {
            int pz;
            cout << "ENTER AMOUNT TO FILL" << endl;
            cin >> pz;
            tbal = pz;
            cout << "ATM REFILLED SUCESSFULLY" << endl;
            cout << "-----------------------------------------------------" << endl;
            break;
        }
        case 2:
        {
            cout << "TOTAL BALANCE IN ATM : " << tbal;
            cout << "-----------------------------------------------------" << endl;
            break;
        }
        case 3:
        {
            cout << "HISTORY : " << endl;
            for (auto i : trans) {
                cout << i.first << "............." << i.second << endl;
            }
            cout << "-----------------------------------------------------" << endl;
            break;
        }
        case 4:
        {
            state = false;
            cout << "ATM FREEZED" << endl;
            cout << "-----------------------------------------------------" << endl;
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            cout << "INVALID OPTION" << endl;
            cout << "-----------------------------------------------------" << endl;
        }
        }
    }
}

void bnk() {
    int ibn;
    cout << "ENTER BANK SECRETE CODE : ";
    cin >> ibn;
    if (ibn == bnkpass) {
        int dd = 1;
        cout << "ALL ACCOUNT DETAILS : " << endl;
        for (auto j : usrdet) {
            auto k = j.second;
            cout << "CUSTOMER " << dd << " : " << endl;
            cout << "Account Number : " << k.accn << endl;
            cout << "Name : " << k.name << endl;
            cout << "IFSC code : " << k.ifsc << endl;
            cout << "Branch : " << k.branch << endl;
            cout << "Current Account Balance : " << k.balance << endl;
            cout << "Bank ID : " << k.bankid << endl;
            cout << "Bank Name : " << k.bname << endl;
            cout << "-----------------------------------------------------" << endl;
            dd++;
        }
    }
}

int main()
{
    user u1,u2,u3,u4,u5;
    u1.addusr(10001, "Hari", 9000001, "Tirupur",35000,1,"CBI",111111,2288);
    u2.addusr(10002, "Ajith", 9000002, "Tirupur", 70000,2,"KVB",222222,2288);
    u3.addusr(10003, "Vignesh", 9000003, "Coimbatore", 240000, 3, "TMB",333333,2288);
    u4.addusr(10004, "Abi", 9000004, "Erode", 90000, 4, "SBI",444444,2288);
    u5.addusr(10005, "Subha", 9000005, "Chennai", 21000, 2, "KVB",5555555,2288);
    usrdet[111111] = u1;
    usrdet[222222] = u2;
    usrdet[333333] = u3;
    usrdet[444444] = u4;
    usrdet[555555] = u5;
    int o;
    while (state) {
        cout << "WELCOME TO HARI PT ATM SERVICE :)" << endl;
        cout << "PLEASE SELECT YOUR ROLE FROM BELOW OPTIONS" << endl;
        cout << "1.CUSTOMER" << endl << "2.ADMIN" << endl << "3.BANK" << endl << "4.QUIT" << endl;
        cin >> o;
        switch (o) {
        case 1:
        {
            usr();
            break;
        }
        case 2:
        {
            admn();
            break;
        }

        case 3:
        {
            bnk();
            break;
        }
        case 4:
        {
            state = false;
            break;
        }
        default:
        {
            cout << "INVALID INPUT" << endl;
            cout << "-----------------------------------------------------" << endl;
        }
        }
    }
    cout << "ATM IS CLOSED"<<endl;
    return 0;
}
