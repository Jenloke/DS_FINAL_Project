/*
Final Project DSA: Micro Lending Services

Tips: 
Don't Over Complicate Things;
Keep it simple;
IDK pointers, dot operator & arrow operator;

TO DO:
1 Introduction of lendee
    provided by the user of this application
        First Name:
        Last Name:
        Age: 
        Monthly Salary (PHP):

    result / to be printed out:
        First Name:
        Last Name:
        Age:

        possible loan amount:


2 Lending Amount details:
    provided by the user of this application
        Amount to be loaned:
        Duration

    to be computed:
        amount total + interest
        amount to be paid per month

3 Adding First & Last Name, Age and Monthly Salary to be Iterable using a function

4 Status Check of Lend Money for Lendee that is to be approved, could be a queue

5 Lendee Status after lending is approved by lendor
    if paid or still paying
    and if x months is still needed to be paid

5 What will the UI look like

*/

#include <iostream>
using namespace std; 

/*
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
*/

int main() 
{
    string firstName, lastName;
    int age, monthlySalary;

    cout << "First Name: ";
    cin >> firstName;
    cout << firstName << endl; 

    cout << "Last Name: ";
    cin >> lastName;
    cout << lastName << endl; 
    
    cout << "Age: ";
    cin >> age;
    cout << age << endl; 

    cout << "Monthly Salary: ";
    cin >> monthlySalary;
    cout << monthlySalary << endl; 
}