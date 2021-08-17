#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Account
{
public:
    int Balance = 0;
    string Name;
    string Password;
};
int number = 0;
int GetInfo()
{
    Account object;
    ifstream num("num.txt");
    if (num.is_open())
    {
        num >> number;
    }
    else
    {
        cout << "num.txt is missing";
    }
    num.close();
    remove("num.txt");
    ifstream info(to_string(number) + ".txt");
    if (info.is_open())
    {
        info >> object.Name;
        info >> object.Password;
        info >> object.Balance;
    }
    else
    {
        cout << to_string(number) + ".txt is missing";
    }
    info.close();
    return object.Balance;
}
int show_balance()
{
    Account object;
    ifstream num("num.txt");
    if (num.is_open())
    {
        num >> number;
    }
    else
    {
        cout << "num.txt is missing";
    }
    num.close();
    ifstream info(to_string(number) + ".txt");
    if (info.is_open())
    {
        info >> object.Name;
        info >> object.Password;
        info >> object.Balance;
    }
    else
    {
        cout << to_string(number) + ".txt is missing";
    }
    info.close();
    cout << object.Balance <<endl;
    return 0;
}
int modify_balance()
{

    Account object;
    ifstream num("num.txt");
    if (num.is_open())
    {
        num >> number;
    }
    else
    {
        cout << "num.txt is missing";
    }
    num.close();
    ifstream info(to_string(number) + ".txt");
    if (info.is_open())
    {
        info >> object.Name;
        info >> object.Password;
        info >> object.Balance;
    }
    else
    {
        cout << to_string(number) + ".txt is missing";
    }
    info.close();
    int fk;
    cout << "Add or withdraw money:\n1.Add money\n2.Withdraw money:";
    cin >> fk;
    switch (fk)
    {
    case 1:
    {
        int jk;
        cout << "How many do you want to add:";
        cin >> jk;
        object.Balance = object.Balance + jk;
        string file = to_string(number) + ".txt";
        ofstream mod;
        mod.open(to_string(number) + ".txt");
        mod << object.Name << endl
            << object.Password << endl
            << object.Balance;
        mod.close();
        break;
    }
    case 2:
    {
        int gk;
        cout << "How many do you want to withdraw:";
        cin >> gk;
        object.Balance = object.Balance - gk;
        string file = to_string(number) + ".txt";
        ofstream mod;
        mod.open(to_string(number) + ".txt");
        mod << object.Name << endl
            << object.Password << endl
            << object.Balance;
        mod.close();
        break;
    }
    default:
    {
        cout << "There is no function like that yet";
        break;
    }
    }
    return 0;
}
int modify_account()
{
    Account object;
    int j;
    string FID;
    string FPASS;
    string NID;
    string NPASS;
    string array[2];
    ifstream num("num.txt");
    if (num.is_open())
    {
        num >> number;
    }
    else
    {
        cout << "num.txt is missing";
    }
    num.close();
    ifstream info(to_string(number) + ".txt");
    if (info.is_open())
    {
        info >> object.Name;
        info >> object.Password;
        info >> object.Balance;
    }
    else
    {
        cout << to_string(number) + ".txt is missing";
    }
    info.close();

    cout << "Which parameter do you want to modify\n1.Name\n2.Password\n:";
    cin >> j;
    switch (j)
    {
    case 1:
    {
        cout << "Write new name:";
        cin >> NID;
        ofstream md;
        md.open(to_string(number) + ".txt");
        md << NID << endl
           << object.Password << endl
           << object.Balance;
        break;
    }
    case 2:
    {
        cout << "Write new password:";
        cin >> NPASS;
        ofstream modi;
        modi.open(to_string(number) + ".txt");
        modi << object.Name << endl
             << NPASS << endl
             << object.Balance;
        break;
    }
    default:
    {
        cout << "We don't have this type of function(maybe later:))";
        break;
    }
    }
    return 0;
}
int LogOut()
{
    string prgrm = "Authentication.exe";
    ShellExecuteA(NULL, "open", prgrm.c_str(), NULL, NULL, SW_SHOWNORMAL);
    remove("num.txt");
    return 0;
}

int main()
{
    Account object;
    printf("1.Balance\n2.Add or Withdraw Money\n3.Modify Account\n4.Log out\n");
    printf("Welcome choose operation:");
    int k;
    cin >> k;
    switch (k)
    {
    case 1:
    {
        show_balance();
        int as;
        cout << "1.Back\n2.Exit\n:";
        cin >> as;
        switch (as)
        {
        case 1:
        {
            main();
            break;
        }
        case 2:
        {
            remove("num.txt");
            system("exit");
            break;
        }
        default:
        {
            cout << "We don't have this type of function(maybe later:))";
            break;
        }
        }
        break;
    }
    case 2:
    {
        modify_balance();
        int fs;
        cout << "1.Back\n2.Exit\n:";
        cin >> fs;
        switch (fs)
        {
        case 1:
        {
            main();
            break;
        }
        case 2:
        {
            remove("num.txt");
            system("exit");
            break;
        }
        default:
        {
            cout << "We don't have this type of function(maybe later:))";
            break;
        }
        }
        break;    
    }
    case 3:
    {
        modify_account();
        int gs;
        cout << "1.Back\n2.Exit\n:";
        cin >> gs;
        switch (gs)
        {
        case 1:
        {
            main();
            break;
        }
        case 2:
        {
            remove("num.txt");
            system("exit");
            break;
        }
        default:
        {
            cout << "We don't have this type of function(maybe later:))";
            break;
        }
        }
        break;
    }
    case 4:
    {
        LogOut();
        break;
    }
    default:
    {
        cout << "We don't have this type of function(maybe later:))";
        break;
    }
    }

    
    return 0;
}