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
int LogIn()
{
    string LId;
    string LPass;
    string list[150];
    int i = 0;
    int x = 0;
    cout << "Insert name:"; //Ad alma
    cin >> LId;
    cout << "Insert Password:"; //Parol alma
    cin >> LPass;
    ifstream da("count.txt");
    if (da.is_open()) //Hesabın sayını tapmaq
    {
        da >> i;
    }
    else
    {
        cout << "Count.txt is missing";
    }
    int f = 0; //list array-inə məlumatları yığmaq
    int g = 0;
    while (f < i - 1)
    {
        ifstream nam(to_string(f + 1) + ".txt");
        if (nam.is_open())
        {
            getline(nam, list[g]);
            getline(nam, list[g + 1]);
            nam.close();
        }
        else
        {
            cout << to_string(f + 1) + ".txt is missing";
            break;
        }
        f++;
        g = g + 2;
    }
    int c = 0;
    int y = 0;
    string program = "Base.exe";
    for (; y < i;)
    {
        if (LId == list[c] && LPass == list[c + 1])
        {
            cout << "You were succesfully loged in";
            c++;
            ofstream num;
            num.open("num.txt");
            num<<c;
            num.close();
            ShellExecuteA(NULL, "open", program.c_str(), NULL, NULL, SW_SHOWNORMAL);
            break;
        }
        else if (y == i - 1)
        {
            cout << "Invalid username or password";
            y++;
        }
        else if (y < i)
        {
            y++;
            c = c + 2;
            continue;
        }
    }

    return 0;
}
int Register()
{
    Account object;
    printf("Select name: \n");
    cin >> object.Name;
    printf("Select password: \n");
    cin >> object.Password;
    int count = 0;
    string name;
    ifstream ct("count.txt"); //Axırıncı hesabın indeksini almaq üçün
    if (ct.is_open())
    {
        ct >> count;
    }
    else
    {
        cout << "Count.txt is missing";
        system("exit");
    }
    ct.close();
    ofstream accounts;
    accounts.open(to_string(count) + ".txt", ios::app);
    accounts << object.Name << endl
             << object.Password << endl
             << object.Balance;
    accounts.close();
    count++;
    ofstream cot;
    cot.open("count.txt");
    cot << count << endl;
    cot.close();
    return 0;
}
int main()
{

    printf("1.Register\n2.Login\n:");
    int i;
    cin >> i;
    switch (i)
    {
    case 1:
    {
        Register();
        break;
    }
    case 2:
    {
        LogIn();
        break;
    }
    default:
    {
        printf("ERROR");
        system("exit");
    }
    }
    return 0;
}