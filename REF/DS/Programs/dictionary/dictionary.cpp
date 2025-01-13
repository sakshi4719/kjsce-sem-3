#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string,long long int> PhoneBook;
    cout << "Enter number of names in Phone Book: ";
    int number;
    cin >> number;
    string name;
    long long num;
    for(int i = 0; i < number; i++)
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter number: ";
        cin >> num;
        PhoneBook[name] = num;
    }

    while(true)
    {
        cout << "\nEnter the name of person to be searched for or 0 to exit: ";
        cin >> name;
        if(name == "0")
            break;
        else if(PhoneBook.find(name) != PhoneBook.end())
        {
            cout<<"\nName: " << name << "\nPhone number: " << PhoneBook[name];
            cout << "\n";
        }
        else
            cout << "\nName not found!\n";
    }
}
