#include <iostream>
using namespace std;

int main()
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

    return 0;
}