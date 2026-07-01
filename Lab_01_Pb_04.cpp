#include <iostream>
#include<cctype>
#include <string>
using namespace std;

int main()
{
    cout<<"----------------------------------------"  <<endl;
    string id;
    cout << "Enter Identifier (input): ";
    cin >> id;

    bool valid = true;

    if (!(isalpha(id[0]) || id[0] == '_'))
    {
        valid = false;
    }

    for (int i=1; i<id.length(); i++)
    {
        if (!(isalnum(id[i]) || id[i] =='_'))
        {
            valid = false;
            break;
        }
    }

    if (valid)
    {
        cout << id <<" is a Valid Identifier";
    }
    else
    {
        cout << id<<" is Not a Valid Identifier!";
    }
    cout<<endl;
    cout<<"---------------------------------------"  <<endl;

    return 0;
}