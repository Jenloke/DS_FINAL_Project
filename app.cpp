#include <iostream>
using namespace std;

int loanBracket[2] = {5000, 10000};
int loanDurations[2] = {6,12};
const int loanMaxDuration = 24;
const int totalUsers = 5;

const int minAgeLoan = 20;

int userNumber = 0;

struct userInfo {
    //bool userGenerated;

    string firstName;
    string lastName;
    int age;
    int monthlySalary;

    int loanUserAmount;
    int loanUserDuration;
    int loanUserMonthlyDue;
    string loanUserStatus; // Paid, Ongoing & None
    bool loanNumberMonthsPaid[loanMaxDuration];
} users[totalUsers];

void blankLine() { cout << endl; }

void enterUserDetails()
{
    cout << "Enter your Pesonal Details" << endl;

    cout << "First Name: ";
    getline(cin >> ws, users[userNumber].firstName);

    cout << "Last Name: ";
    getline(cin >> ws, users[userNumber].lastName);

    cout << "Age: ";
    //getline(cin, users[userNumber].age);
    cin >> users[userNumber].age;

    blankLine();

    if (users[userNumber].age < minAgeLoan) {
        cout << "Have you entered your age correctly." << endl;
        cout << "The minimum age that can loan is " << minAgeLoan << "." << endl;
        cout << "Please enter your Personal Details again." << endl;
        blankLine();

        enterUserDetails();
    }
}

void confirmUserDeatails()
{
    cout << "These are your Pesonal Details you have entered:" << endl;
    cout << "First Name: " << users[userNumber].firstName << endl;
    cout << "Last Name: " << users[userNumber].lastName << endl;
    cout << "Age: " << users[userNumber].age << endl;
    blankLine();

    string userAnswer;
    cout << "Please confirm that you have entered your correct Personal Details \nbased on what is printed above? (Y/N) [Y for Yes while N for No]: ";
    cin >> userAnswer;

    if (userAnswer == "Y") {
        blankLine();
        cout << "Thank you for confirming your Personal Details. You may now proceed on the loaning process." << endl;
        blankLine();
    }
    if (userAnswer == "N") {
        cout << "You are to return to entering your Personal Details." << endl;
        cout << "Please make sure that they are correct this time." << endl;
        blankLine();
        enterUserDetails();
        confirmUserDeatails();
    }
    // Still Needs Error Handling
}

int main()
{
    cout << "Welcome to Micro Lending Services" << endl;
    blankLine();

    // There will be 2 options here
    // Create a loan & Pay one month off a loan
    // If Possible Cancel a Loan; will be included in Option 2
    // Third Option will be show what months are already paid
    // Fourth Option is how much money the Service Maid

    enterUserDetails();
    confirmUserDeatails();

    cout << "Monthly Salary: ";
    cin >> users[userNumber].monthlySalary;

    // Based on your given monthly salary of users[userNumber].monthlySalary the highest amount in PHP you could loan is x
    // To add more based on bracket

    // Still Needed; Computes if monthly salary is eligible for desired loan
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

    // Computes for Monthly Due for userNumber = amount needed to pay
    users[userNumber].loanUserMonthlyDue = (users[userNumber].loanUserAmount + (users[userNumber].loanUserAmount* 0.15)) / users[userNumber].loanUserDuration;
    cout << "Amount needed to pay per month: " << users[userNumber].loanUserMonthlyDue << endl;

    users[userNumber].loanUserStatus = "Ongoing";
    cout << "Your Loan Status is currently: " << users[userNumber].loanUserStatus << endl;

    for (int i=0; i < users[userNumber].loanUserDuration; i++)
    {
        users[userNumber].loanNumberMonthsPaid[i] = true; // must be true, false is just for testing function below
        //cout << users[userNumber].loanNumberMonthsPaid[i] << endl;
    }

    // Make Payment: Receipt System
    int loanPayment;
    cout << "How much would you like to pay: ";
    cin >> loanPayment;

    if (users[userNumber].loanUserMonthlyDue == loanPayment) {
        for (int i=0; i < users[userNumber].loanUserDuration; i++)
        {
            if (users[userNumber].loanNumberMonthsPaid[i] == true) {
                users[userNumber].loanNumberMonthsPaid[i] = false;
                cout << "Month " << i+1 << ": Payment Found of " << users[userNumber].loanUserMonthlyDue << " PHP" << endl;
                break;
            }
        }
    }

    cout << endl;

    // Prints Loan Status per month
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
    for (int i=0; i < users[userNumber].loanUserDuration; i++)
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
    // return a value if equal to loanUserDuration will turn loanUserStatus = Paid

    //userNumber++;

    return 0;
}
