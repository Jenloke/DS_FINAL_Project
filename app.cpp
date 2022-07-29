#include <iostream>
using namespace std;

//int loanBracket[2] = {5000, 10000};
//int loanDurations[2] = {6,12};
const int loanMaxDuration = 24;
const int totalUsers = 5;

const int minAgeLoan = 20;
const int maxLoanMultiplier = 2;

int userNumber = 0;

struct userInfo {
    //bool userGenerated; // This is needed

    string firstName;
    string lastName;
    int age;
    int monthlySalary;

    int loanMaxPossibleLoan;
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
    cin >> users[userNumber].age;

    blankLine();

    if (users[userNumber].age < minAgeLoan) { // To enter Details again if age requirement is not met
        cout << "You have not met the age requirements for a loan." << endl;
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
    cout << "Please confirm that you have entered your correct Personal Details"<< endl;
    cout << "based on what is printed above? (Y/N) [Y for Yes while N for No]: ";
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

void createLoanAmount()
{
    cout << "Please write your Monthly Salary to determine what is the " << endl;
    cout << "highest possible amount of loan we can loan you in PHP: ";
    cin >> users[userNumber].monthlySalary;
    blankLine();

    if (users[userNumber].monthlySalary < 0) {
        cout << "The Monthly Salary of " << users[userNumber].monthlySalary << " PHP that you have entered is invalid since it is negative." << endl;
        cout << "Please enter a valid Monthly Salary in PHP." << endl ;
        cout << "You are to go back to entering your monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
    // Add error handling if not int also if negative

    users[userNumber].loanMaxPossibleLoan = users[userNumber].monthlySalary * maxLoanMultiplier;
    cout << "Based on your given monthly Salary of, " << users[userNumber].monthlySalary << " PHP the maximum amount of loan possible is " << users[userNumber].loanMaxPossibleLoan << " PHP." << endl;
    cout << "How much would you like to loan in PHP? ";
    cin >> users[userNumber].loanUserAmount;
    blankLine();

    if (users[userNumber].loanUserAmount <= users[userNumber].loanMaxPossibleLoan && users[userNumber].loanUserAmount > 0) {
        cout << "You can now proceed to the next step." << endl;
        blankLine();
    }
    if (users[userNumber].loanUserAmount >= users[userNumber].loanMaxPossibleLoan) {
        cout << "The amount of loan of " << users[userNumber].loanUserAmount << " PHP that you have entered is not qualified since it is above the maximum possible loan based on your salary." << endl;
        cout << "Please enter a valid loan amount that is below your maximum possible loan which is ." << endl;
        cout << "You are to go back to entering your monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
    if (users[userNumber].loanUserAmount < 0) {
        cout << "The amount of loan of " << users[userNumber].loanUserAmount << " PHP that you have entered is invalid since it is negative." << endl;
        cout << "Please enter a valid loan amount." << endl ;
        cout << "You are to go back to entering your monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
    // Error Handling for value if the value entered is not int should be a function that can be used by other void functions
}

//void

int main()
{
    cout << "Welcome to Micro Lending Services" << endl;
    blankLine();

    // There will be 2 options here
    // Create a loan & Pay one month off a loan
    // If Possible Cancel a Loan; will be included in Option 2
    // Third Option will be show what months are already paid
    // Fourth Option is how much money the Service Maid
    // Message that will appear when the loan is fully paid upon the final payment paid
    // If possible create a way to create, read, update, delete data

    /*
    Program Structure
    Option 1: Create a new Loan;
        Condition if there is an available slot in struct array,
        else it is not possible unless a loan from the list turned to fully paid
    Option 2: Pay a month off a loan

        A compromise would be user will write off how many months is to be paid off
        based on what amount and month the user wrote

        Will print a receipt after payment and prints all months that have been paid

        If possible to pay off multiple months off a loan

        Also loan is to be deleted when all bool is turned to false then print like congrats on paying your loan, hope we see you again here

    Option 3: Show your Loan; Simple Seacrh and Print Part
    Option 4: Show How much the Micro Lending Service Made; Simple Print
    Option 5: Exit

    Will Return to this part after the process of each option
    */

    // TO DO: 29/07/2022
    // Finish the System without error handling yet

    //enterUserDetails();
    //confirmUserDeatails();

    createLoanAmount();

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
