#include <iostream>
using namespace std;

int main() {
    string str;
    bool flag = true;
    cout<< "-------------------------"<<endl;

    cout << "Enter input: ";
    cin >> str;

    for(char ch : str)
    {
        if(ch < 48 || ch > 57) 
        {  
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Numeric Constant"<< endl;

    }

    else{
        cout << "Not Numeric Constant!" << endl;
    }
    cout<< "-------------------------" <<endl;
    cout<<endl;

    return 0;
}