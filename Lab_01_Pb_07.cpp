#include <iostream>
#include <string>
using namespace std;

int main()
{
    string firstName, lastName;
    cout<<"----------------------------------------------"<<endl;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;
    cout<<endl;

    string fullName = firstName + " " + lastName;

    cout << "Full Name = " << fullName<<endl;
    cout<<"----------------------------------------------"<<endl;

    return 0;
}