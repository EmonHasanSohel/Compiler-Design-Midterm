#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int count = 0;
    cout<<"--------------------------------"<<endl;
    cout << "Enter expression: ";
    cin >> str;

    for(int i =0;  i < str.length();  i++) 
    {
        if(str[i] ==  '+' || str[i] == '-' ||
           str[i] == '*' ||  str[i]  == '/' ||
           str[i]  == '%' || str[i] == '=') 
        {

            count++;
            cout << "Operator" << count << ": " << str[i] << endl;
        }
    }

    if(count == 0)
    {
        cout << "No Operator Found!" << endl;
    }
    cout <<endl;
    cout<<"--------------------------------" <<endl;

    return 0;
}