/*
Final Project DSA: Micro Lending Services

TO DO:

*/

#include <iostream>
using namespace std; 

int interest_rate(int x)
{
    return x + (x*0.15);
}

int main()
{
    int a;
    //int arr[] = {};
    
    cout << "Enter the amount you wish to loan: ";
    cin >> a;
    a = interest_rate(a);

    float b;
    int duration = 12;
    b = a/duration;
    
    cout << b << endl; 
    cout << a << endl;

    return 0;
}