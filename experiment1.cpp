#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void checkNumericConstant()
{
    string str;
    bool flag = true;

    cout << "\n-------------------------\n";
    cout << "Enter input: ";
    cin >> str;

    for(char ch : str)
    {
        if(ch < '0' || ch > '9')
        {
            flag = false;
            break;
        }
    }

    if(flag)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric Constant!" << endl;

    cout << "-------------------------\n";
}


void findOperators()
{
    string str;
    int count = 0;

    cout << "\n--------------------------------\n";
    cout << "Enter expression: ";
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+' || str[i] == '-' ||
           str[i] == '*' || str[i] == '/' ||
           str[i] == '%' || str[i] == '=')
        {
            count++;
            cout << "Operator " << count << ": " << str[i] << endl;
        }
    }

    if(count == 0)
        cout << "No Operator Found!" << endl;

    cout << "--------------------------------\n";
}


void checkComment()
{
    string str;

    cin.ignore();

    cout << "\n---------------------------\n";
    cout << "Enter comment: ";
    getline(cin, str);

    if(str.substr(0, 2) == "//")
        cout << "Single Line Comment" << endl;

    else if(str.substr(0, 2) == "/*")
        cout << "Multi Line Comment" << endl;

    else
        cout << "Not a Comment" << endl;

    cout << "---------------------------\n";
}


void checkIdentifier()
{
    string id;
    bool valid = true;

    cout << "\n----------------------------------------\n";
    cout << "Enter Identifier: ";
    cin >> id;

    if(!(isalpha(id[0]) || id[0] == '_'))
        valid = false;

    for(int i = 1; i < id.length(); i++)
    {
        if(!(isalnum(id[i]) || id[i] == '_'))
        {
            valid = false;
            break;
        }
    }

    if(valid)
        cout << id << " is a Valid Identifier" << endl;
    else
        cout << id << " is Not a Valid Identifier!" << endl;

    cout << "----------------------------------------\n";
}

void averageValue()
{
    int n;
    cout<<"--------------------------------"<<endl;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    double avg = (double)sum / n;

    cout << "Average Value = " << avg<<endl;
    cout<<"--------------------------------"<<endl;

   
}

void maxiMini()
{
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int min = arr[0];
    int max = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max<<endl;


}

void concatenate()
{
    string firstName, lastName;
    cout<<"----------------------------------------------"<<endl;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;

    cout << "Full Name = " << fullName<<endl;
    cout<<"----------------------------------------------"<<endl;

}

int main()
{
    int choice;

    do
    {
       
        cout<<"-------------------------------------------"<<endl;
        cout << "Main Function:"<< endl;
        cout << "1. Check Numeric Constant"<< endl;;
        cout << "2. Find Operators" <<endl;
        cout << "3. Check Comment" <<endl;
        cout << "4. Check Identifier"<< endl;
        cout << "5. Calculate Average Value"<< endl;
        cout << "6. Find Maximum/Minimum" <<endl;
        cout << "7. Find Concatenate" <<endl;
        cout << "8. Exit"<<endl;
        cout<< endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                checkNumericConstant();
                break;

            case 2:
                findOperators();
                break;

            case 3:
                checkComment();
                break;

            case 4:
                checkIdentifier();
                break;
            case 5:
                averageValue();
                break;

            case 6:
                maxiMini();
                break;
            
            case 7:
                concatenate();
                break;


            case 8:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } 
    while(choice != 8);

    cout<<"-------------------------------------------"<<endl;

    return 0;
}