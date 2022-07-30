#include <iostream>
#include <climits> // for INT_MAX limits
using namespace std;

/*
if (cin.fail()) {
    cin.clear(); // clear input buffer to restore cin to a usable state
    cin.ignore(INT_MAX, '\n'); // ignore last input
    createLoanAmount();
}
*/

const int loanBracketAmount[2] = {50000, 100000};
const int loanDurations[3] = {12,18,24};
const int loanMaxDuration = 24; // Was 24, Trying 5 Years || 60 Months
const int totalUsers = 5; // Max Users this should be easily changeable and would not break anything

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

// To add Called Again Variable if User wants to go back to this function; bool funcCalledAgain = False;
void createLoanAmount()
{
    cout << "Please write your Monthly Salary to determine the " << endl;
    cout << "highest possible amount of loan we can loan you in PHP: ";
    cin >> users[userNumber].monthlySalary;
    blankLine();

    if (cin.fail()) { // If the value creates an infinite loop
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input

        cout << "Please enter a valid Monthly Salary in PHP." << endl ;
        cout << "You are to go back to entering your Monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
    if (users[userNumber].monthlySalary < 0) { // if negative
        cout << "The Monthly Salary of " << users[userNumber].monthlySalary << " PHP that you have entered is invalid since it is negative." << endl;
        cout << "Please enter a valid Monthly Salary in PHP." << endl ;
        cout << "You are to go back to entering your Monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }

    users[userNumber].loanMaxPossibleLoan = users[userNumber].monthlySalary * maxLoanMultiplier;
    cout << "Based on your given monthly Salary of, " << users[userNumber].monthlySalary << " PHP the maximum amount of loan possible is " << users[userNumber].loanMaxPossibleLoan << " PHP." << endl;
    cout << "How much would you like to loan in PHP? ";
    cin >> users[userNumber].loanUserAmount;
    blankLine();

    if (cin.fail()) {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input

        cout << "You have entered an invalid character." << endl;
        cout << "Please enter a valid Loan Amount in PHP." << endl ;
        cout << "You are to go back to entering your Monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
    if (users[userNumber].loanUserAmount <= users[userNumber].loanMaxPossibleLoan && users[userNumber].loanUserAmount > 0) {
        cout << "You can now proceed to the next step." << endl;
        blankLine();
    }
    if (users[userNumber].loanUserAmount > users[userNumber].loanMaxPossibleLoan) {
        cout << "The amount of loan of " << users[userNumber].loanUserAmount << " PHP that you have entered is not qualified." << endl;
        cout << "Since it is above the maximum possible loan of " << users[userNumber].loanMaxPossibleLoan << " PHP which is twice your salary." << endl;
        cout << "Please enter a valid loan amount that is below your maximum possible." << endl;
        cout << "You are to go back to entering your Monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
    if (users[userNumber].loanUserAmount <= 0) {
        cout << "The amount of loan of " << users[userNumber].loanUserAmount << " PHP that you have entered is invalid since it is negative." << endl;
        cout << "Please enter a valid loan amount." << endl ;
        cout << "You are to go back to entering your Monthly Salary." << endl;
        blankLine();
        createLoanAmount();
    }
}

void printLoanChart() // will also be called in the list of the options in first part of the system
{
    cout << "Loan Duration Chart based on Loan Amount List" << endl;
    cout << "Format = Loan Amount : Maximum Number of Months " << endl;
    cout << "Loan >= 100000 PHP             : 24 Months" << endl;
    cout << "50000 PHP <= Loan < 100000 PHP : 18 Months" << endl;
    cout << "Loan < 50000 PHP               : 12 Months" << endl;
}

void createLoanDuaration()
{
    cout << "You are to base your loan in these chart." << endl;
    printLoanChart();
    blankLine();

    cout << "The Loan Amount you have entered is " << users[userNumber].loanUserAmount << " PHP." << endl;
    cout << "Please enter your Loan Duration in Months: ";
    cin >> users[userNumber].loanUserDuration;
    blankLine();

    if (cin.fail()) {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input

        cout << "You have entered an invalid character." << endl;
        cout << "Please enter a valid Loan Duration." << endl;
        cout << "You are to go back to entering your Loan Duration." << endl;
        blankLine();
        createLoanDuaration();
    }
    if (users[userNumber].loanUserDuration < 0) { // Error Handling if Negative int is entered
        cout << "Please enter a valid Loan Duration." << endl;
        cout << "You are to go back to entering your Loan Duration." << endl;
        blankLine();
        createLoanDuaration();
    }
    if (users[userNumber].loanUserDuration > 24) {
        cout << "You have entered a Loan Duration that is more than 24 Months." << endl;
        cout << "Please enter a valid Loan Duration and it is within the Loan Chart." << endl;
        cout << "You are to go back to entering your Loan Duration." << endl;
        blankLine();
        createLoanDuaration();
    }
    // error handling solutions
    // loan duration & amount is zero: solved
    // loan duration > 24: solved
    // loan dur & amt is not int: solved
    // max amount of loan bound: solved
}

void evaluateLoanDuration()
{
    if (users[userNumber].loanUserAmount >= loanBracketAmount[1] && users[userNumber].loanUserDuration <= loanDurations[2]) {
        cout << "apple" << endl;
        cout << "Your loan of " << users[userNumber].loanUserAmount << " PHP for " << users[userNumber].loanUserDuration << " Months is possible." << endl;
        cout << "You are now set for you loan to be computed." << endl;
        blankLine();
    }
    else if (users[userNumber].loanUserAmount < loanBracketAmount[1] && users[userNumber].loanUserAmount >= loanBracketAmount[0] && users[userNumber].loanUserDuration <= loanDurations[1]) {
        cout << "banana" << endl;
        cout << "Your loan of " << users[userNumber].loanUserAmount << " PHP for " << users[userNumber].loanUserDuration << " Months is possible." << endl;
        cout << "You are now set for you loan to be computed." << endl;
        blankLine();
    }
    else if (users[userNumber].loanUserAmount < loanBracketAmount[0] && users[userNumber].loanUserDuration <= loanDurations[0]) {
        cout << "carrot" << endl;
        cout << "Your loan of " << users[userNumber].loanUserAmount << " PHP for " << users[userNumber].loanUserDuration << " Months is possible." << endl;
        cout << "You are now set for you loan to be computed." << endl;
        blankLine();
    }else {
        cout << "The Loan Duration you have entered is not possible." << endl;
        cout << "It is beyond what is stated in the Loan Duration Chart." << endl;
        cout << "You are to go back to entering your Loan Duration." << endl;
        blankLine();
        createLoanDuaration();
    }
}

void evaluateLoan()
{


    // This function will add the interest
}

void printLoanTotalWithList() // Second
{
    // Output of this needs to be in fucntion form
    cout << "Loan Total is " << users[userNumber].loanUserAmount + (users[userNumber].loanUserAmount* 0.15) << endl;
}

void confirmLoan() // Third
{

}

void createPayment()
{}

void confirmPayment()
{}

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
    // If int entered is not a number or int; use (isdigit())

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
    createLoanDuaration();
    evaluateLoanDuration();
    printLoanTotalWithList();
    confirmLoan();

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
