/*
Final Project DSA: Micro Lending Services

Tips:
Don't Over Complicate Things;
Keep it simple;
IDK pointers, dot operator & arrow operator;

TO DO:
1 Introduction of lendee (Somewhat Done)
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
    return 0;
}
*/

#include <iostream>
using namespace std;

int loanBracket[2] = {5000, 10000};
int loanDurations[2] = {6,12};
const int loanMaxDuration = 24;

struct userInfo {
    //bool userGenerated;

    string firstName;
    string lastName;
    int age;
    int monthlySalary;

    int loanUserAmount;
    int loanUserDuration;
    string loanUserStatus; // Paid, Ongoing & None
    bool loanNumberMonthsPaid[loanMaxDuration];
} users[5];

int userNumber = 0;
//int totalUser = 5

int main()
{
    cout << "Welcome to Micro Lending Services" << endl;
    /*
    cout << "First Name: ";
    getline(cin, users[userNumber].firstName);

    cout << "Last Name: ";
    getline(cin, users[userNumber].lastName);

    cout << "Age: ";
    cin >> users[userNumber].age;

    cout << "Monthly Salary: ";
    cin >> users[userNumber].monthlySalary;
    */
    // Based on your given monthly salary of users[userNumber].monthlySalary the highest amount in PHP you could loan is x
    // To add more based on bracket

    //if (users[userNumber].monthlySalary >= loanBracket[1]) {
    //    cout << "Based on your given monthly salary of " << users[userNumber].monthlySalary << " PHP the highest amount you could loan is " << loanBracket[1] << " PHP." << endl;
    //}

    // Error Handling for

    cout << "Loan Amount: ";
    cin >> users[userNumber].loanUserAmount;
    //cout << users[userNumber].loanUserAmount << endl;

    //cout << "Based on your given loan amount, your loan in " << users[userNumber].loanDuration << endl;

    cout << "Loan Duration (6 Months or 12 Months): ";
    cin >> users[userNumber].loanUserDuration;
    //cout << users[userNumber].loanUserDuration << endl;

    // Output of this needs to be in fucntion form
    cout << "Loan Total is " << users[userNumber].loanUserAmount + (users[userNumber].loanUserAmount* 0.15) << endl;
    cout << "Amount needed to pay per month: " << (users[userNumber].loanUserAmount + (users[userNumber].loanUserAmount* 0.15)) / users[userNumber].loanUserDuration << endl;

    users[userNumber].loanUserStatus = "Ongoing";
    cout << "Your Loan Status is currently: " << users[userNumber].loanUserStatus << endl;

    for (int i=0; i < users[userNumber].loanUserDuration; i++)
    {
        users[userNumber].loanNumberMonthsPaid[i] = false; // must be true, testing function below
        //cout << users[userNumber].loanNumberMonthsPaid[i] << endl;
    }

    //cin >> "Would you like to pay your monthly "

    // Prints
    for (int i=0; i < users[userNumber].loanUserDuration; i++)
    {
        if (users[userNumber].loanNumberMonthsPaid[i] == true) {
            cout << "Month " << i+1 << ": No Payment Found" << endl;
        }
        if (users[userNumber].loanNumberMonthsPaid[i] == false) {
            cout << "Month " << i+1 << ": Payment Found" << endl;
        }
    }

    // Checks array if all members of it is false, this will be a function
    int j = 0;
    for (int i=0; i < users[userNumber].loanUserDuration; i ++)
    {
        if (users[userNumber].loanNumberMonthsPaid[i] == false) {
            j++;
        }
    }

    if (j == users[userNumber].loanUserDuration) {
        cout << "Loan is Paid" << endl;
    }else {
        cout << "Loan is not yet Paid" << endl;
    }
    // return j;

    // return a value if equal t loanUserDuration will turn loanUserStatus = Paid


    //userNumber++;

    return 0;
}
