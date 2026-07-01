#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout <<"---------------------------"<< endl;
    cout << "Enter comment: ";
    getline(cin, str);

    if(str.substr(0, 2) == "//")
    {
        cout << "Single Line Comment" << endl;
    }

    else if(str.substr(0, 2) == "/*")
    {
        cout << "Multi Line Comment" << endl;
    }

    else
    {
        cout << "Not a Comment" << endl;
    }
    cout <<endl;
    cout<<"----------------------------" <<endl;

    return 0;
}