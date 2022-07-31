#include <iostream>
#include <climits> // for INT_MAX limits
#include <time.h>
using namespace std;
/* For cin >> int type if input has a foreign char
if (cin.fail()) {
    cin.clear(); // clear input buffer to restore cin to a usable state
    cin.ignore(INT_MAX, '\n'); // ignore last input
    createLoanAmount();
}
*/
const int totalUsers = 5; // Max Users this should be easily changeable and would not break anything
int userNumber;

const int minAgeLoan = 20;

const int maxLoanMultiplier = 2;
const int loanBracketAmount[2] = {50000, 100000};
const int loanMaxDuration = 24; // Was 24, Trying 5 Years || 60 Months
const int loanDurations[3] = {12,18,24};

const float loanInterestRate = 0.05;
const int loanInterestRateDisplay = 5;

struct userInfo {
    int loanUserNumber;
    bool userGenerated; // This is needed

    string firstName;
    string lastName;
    int age;
    int monthlySalary;

    int loanMaxPossibleLoan;
    int loanUserAmount;
    int loanUserDuration;
    int loanTotalWithInterest;

    int loanUserMonthlyDue;
    string loanUserStatus; // Paid, Ongoing
    bool loanNumberMonthsPaid[loanMaxDuration];
    int loanMonthRemaining;
    int loanAmountRemaining;
} users[totalUsers];

void setAllUserNumber()
{
    for (int i=0; i < totalUsers; i++)
    {
        users[i].loanUserNumber = i;
        //cout << users[i].loanUserNumber << endl;
    }
}

void blankLine() { cout << "===========================================================" << endl; }

void setUserNumber()
{
    users[userNumber].userGenerated = true;
    cout << "Your User Number is: " << users[userNumber].loanUserNumber + 1<< endl;
    blankLine();
}

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
    if (cin.fail()) { // If the value creates an infinite loop
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input

        cout << "Please enter a valid Age, where it just contains numbers." << endl ;
        cout << "You are to go back to entering your User Details." << endl;
        blankLine();
        enterUserDetails();
    }
    if (users[userNumber].monthlySalary < 0) { // if negative
        cout << "Please enter a valid Age not negative and above age requirements (" << minAgeLoan << ")." << endl ;
        cout << "You are to go back to entering your User Details." << endl;
        blankLine();
        enterUserDetails();
    }
    if (users[userNumber].age < minAgeLoan) { // To enter Details again if age requirement is not met
        cout << "You have not met the age requirements for a loan." << endl;
        cout << "The minimum age that can loan is " << minAgeLoan << "." << endl;
        cout << "Please enter your Personal Details again." << endl;
        blankLine();
        enterUserDetails();
    }
}

void confirmUserDeatails() // Still need char error handling if entered is not Y || N
{
    cout << "These are your Pesonal Details you have entered:" << endl;
    cout << "First Name: " << users[userNumber].firstName << endl;
    cout << "Last Name: " << users[userNumber].lastName << endl;
    cout << "Age: " << users[userNumber].age << endl;
    blankLine();

    string userAnswerUserDeatails;
    cout << "Please confirm that you have entered your correct Personal Details"<< endl;
    cout << "based on what is printed above? (Y/N) [Y for Yes while N for No]: ";
    cin >> userAnswerUserDeatails;

    if (userAnswerUserDeatails == "Y") {
        blankLine();
        cout << "Thank you for confirming your Personal Details. You may now proceed on the loaning process." << endl;
        blankLine();
    }
    else if (userAnswerUserDeatails == "N") {
        cout << "You are to return to entering your Personal Details." << endl;
        cout << "Please make sure that they are correct this time." << endl;
        blankLine();
        enterUserDetails();
        confirmUserDeatails();
    }else {
        cout << "The character/s you have inputted does not represent an UPPER CASE Y or N." << endl;
        cout << "You are to confirm your User Details again." << endl;
        blankLine();
        confirmUserDeatails();
    }
}

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
    cout << "Take note that interest is still not included which is " << loanInterestRateDisplay << "% added to your desired Loan Amount." << endl;
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
        cout << "Your loan of " << users[userNumber].loanUserAmount << " PHP for " << users[userNumber].loanUserDuration << " Months is possible." << endl;
        cout << "You are now set for you loan to be computed." << endl;
        blankLine();
    }
    else if (users[userNumber].loanUserAmount < loanBracketAmount[1] && users[userNumber].loanUserAmount >= loanBracketAmount[0] && users[userNumber].loanUserDuration <= loanDurations[1]) {
        cout << "Your loan of    " << users[userNumber].loanUserAmount << " PHP for " << users[userNumber].loanUserDuration << " Months is possible." << endl;
        cout << "You are now set for you loan to be computed." << endl;
        blankLine();
    }
    else if (users[userNumber].loanUserAmount < loanBracketAmount[0] && users[userNumber].loanUserDuration <= loanDurations[0]) {
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

void evaluateLoanTotal()
{
    cout << "Based on the details you have given us." << endl;
    cout << "Loan Amount: " << users[userNumber].loanUserAmount << " PHP" << endl;
    cout << "Loan Duration: " << users[userNumber].loanUserDuration << " Months" << endl;

    users[userNumber].loanTotalWithInterest = users[userNumber].loanUserAmount + (users[userNumber].loanUserAmount * loanInterestRate);
    cout << "The total amount of the loan we can give with interest is " << users[userNumber].loanTotalWithInterest << " PHP."<< endl;
    blankLine();
}

void evaluateLoanMonthly()
{
    users[userNumber].loanUserMonthlyDue = users[userNumber].loanTotalWithInterest / users[userNumber].loanUserDuration;
    cout << "This is the amount you need to pay each month: " << users[userNumber].loanUserMonthlyDue << endl;
    cout << "To pay your monthly due use Option #2 in the Main Menu." << endl;
    blankLine();

    for (int i=0; i < users[userNumber].loanUserDuration; i++) // sets nummonthsPaids arr to all false up to loan user duration
    {
        users[userNumber].loanNumberMonthsPaid[i] = false;
        //cout << users[userNumber].loanNumberMonthsPaid[i] << endl; // to delete upon done; used for debugging purpose
    }
}

void printLoanDetails()
{
    cout << "User Number: " << users[userNumber].loanUserNumber + 1<< endl;
    cout << "Personal Details" << endl;
    cout << "First Name: " << users[userNumber].firstName << endl;
    cout << "First Name: " << users[userNumber].lastName << endl;
    cout << "Age: " << users[userNumber].age << endl;
    blankLine();

    cout << "Loan Details" << endl;
    cout << "Monthly Salary: " << users[userNumber].monthlySalary << " PHP" << endl;
    cout << "Loan Amount with Interest: " << users[userNumber].loanTotalWithInterest << " PHP" << endl;
    cout << "Loan Duration: " << users[userNumber].loanUserDuration << " Months" << endl;
    cout << "Monthly Due: " << users[userNumber].loanUserMonthlyDue << " PHP" << endl;
    blankLine();

    // if loan is ongoing will call the void function that handles number of months paid
}

void confirmLoan()
{
    cout << "You are now here to confirm your Loan" << endl;
    cout << "So please check you Personal and Loan Details presented above" << endl;
    blankLine();

    cout << "Remember once a loan is confirmed, it is not possible to delete it." << endl;
    cout << "Only then it can be deleted once the loan is fully paid." << endl;
    cout << "Please Remember the User Number that was assigned to you." << endl;
    blankLine();

    cout << "If there are details you have inputted wrong this is the time to correct it." << endl;
    cout << "Choose what step in taking the loan would you like to go back to." << endl;
    cout << "Take note that after you selected where you want to return." << endl;
    cout << "You are to repeat the process after the one you selected." << endl;
    cout << "Please just choose the number: " << endl;
    blankLine();

    cout << "[1] Entering Personal Details" << endl;
    cout << "[2] Entering Loan Amount includes your Monthly Salary" << endl;
    cout << "[3] Entering Loan Duration" << endl;
    blankLine();

    cout << "Press Y to confirm your loan or the number one of the choice above if you wish to change something: ";

    string userAnswerConfirmLoan;
    getline(cin >> ws, userAnswerConfirmLoan);
    blankLine();

    if (userAnswerConfirmLoan == "Y") {
        users[userNumber].loanUserStatus = "Ongoing"; // This essentially confirms the loan
        cout << "Thank you for confirming you loan." << endl;
        blankLine();
    }else if (userAnswerConfirmLoan == "1") {
        blankLine();
        cout << "You are to go back to entering your Personal Details." << endl;
        blankLine();
        enterUserDetails();
    }else if (userAnswerConfirmLoan == "2") {
        blankLine();
        cout << "You are to go back to entering your Monthly Salary and Loan Amount." << endl;
        blankLine();
        createLoanAmount();
    }else if (userAnswerConfirmLoan == "3") {
        blankLine();
        cout << "You are to go back to entering your Loan Duration." << endl;
        blankLine();
        createLoanDuaration();
    }else {
        cout << "The character/s you have inputted does not represent an UPPER CASE Y or one of the numbers presented above." << endl;
        cout << "You are to confirm your User Details again." << endl;
        blankLine();
        confirmUserDeatails();
    }
}

void printLoanStatus()
{
    cout << "Your Loan Status is currently: " << users[userNumber].loanUserStatus << endl;
    blankLine();
}

void printLoanBalanceList() // prints all monthly payments to be maid
{
    // Prints Loan Status per month
    // False: Month is not Paid || True: Month is Paid
    // Prints Amount Remaining

    cout << "Here is the list of Months in the Loan that had been paid and not." << endl;
    blankLine();

    for (int i=0; i < users[userNumber].loanUserDuration; i++)
    {
        if (users[userNumber].loanNumberMonthsPaid[i] == false) {
            cout << "Month " << i+1 << ": No Payment Found" << endl;
        }
        if (users[userNumber].loanNumberMonthsPaid[i] == true) {
            cout << "Month " << i+1 << ": Payment Found" << endl;
        }
    }
    blankLine();
    cout << "You have " << users[userNumber].loanAmountRemaining << " PHP left in your loan." << endl;
    blankLine();
}

// For Option 2
void clearUserDetails() // Will be called once loan stautus is set to paid
{

}

void selectUser() // userNumber is alway -1
{
    int inputSelectUser;
    cout << "Please enter the User Number that was assigned to you: ";
    cin >> inputSelectUser;
    blankLine();

    userNumber = inputSelectUser - 1;

    if (inputSelectUser < totalUsers && inputSelectUser > 0 && users[userNumber].userGenerated == true) {
        cout << "You have selected User " << inputSelectUser << endl;
        blankLine();

    }else if (users[userNumber].userGenerated == false && inputSelectUser < totalUsers && inputSelectUser > 0) {
        cout << "The user number you have inputted is not yet generated." << endl;
        blankLine();
        selectUser();
    }
    else if (inputSelectUser > totalUsers) {
        cout << "Your input is greater than the maximum users available, therefore it is not valid." << endl;
        blankLine();
        selectUser();
    }else {
        cout << "The number you have inputted is invalid." << endl;
        blankLine();
        selectUser();
    }
}

void evaluateRemainingDue()
{
    int evalMonthRemaining = users[userNumber].loanUserDuration;
    int evalLoanRemaining = users[userNumber].loanTotalWithInterest;

    for (int i=0; i < users[userNumber].loanUserDuration; i++) { //true is paid; false is not
        if (users[userNumber].loanNumberMonthsPaid[i] == true) {
            evalMonthRemaining--; // for month
            evalLoanRemaining =  evalLoanRemaining - users[userNumber].loanUserMonthlyDue; // for amount
        }
    }
    users[userNumber].loanAmountRemaining = evalLoanRemaining;
    users[userNumber].loanMonthRemaining = evalMonthRemaining;
}

int loanPayment;
int loanChange;

void createMonthlyDue()
{
    cout << "Based on data represented above" << endl;
    cout << "You have " << users[userNumber].loanMonthRemaining <<" Months remaining on your loan" << endl;
    cout << "Your Monthly Due: " << users[userNumber].loanUserMonthlyDue << " PHP" << endl;
    blankLine();
    cout << "You can only pay just one month worth of due for your loan." << endl;
    cout << "If you are to pay two or more months off of your loan you are to use this option again." << endl;

    // Make Payment: Receipt System
    cout << "How much would you like to pay: ";
    cin >> loanPayment;
    blankLine();

    if (cin.fail()) { // If the value creates an infinite loop
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX, '\n'); // ignore last input

        cout << "Please enter a valid amount, where it just contains numbers." << endl ;
        cout << "You are to go back to paying you monthly due." << endl;
        blankLine();
        createMonthlyDue();
    }

    if (loanPayment >= users[userNumber].loanUserMonthlyDue) {
        cout << "You are now to confirm your monthly payment for just one month." << endl;
        blankLine();
    } else if (loanPayment < users[userNumber].loanUserMonthlyDue && loanPayment > 0) {
        cout << "The amount you have entered is below the required monthly due." << endl;
        cout << "You are to go back to paying you monthly due." << endl;
        blankLine();
        createMonthlyDue();
    } else if (loanPayment <= 0) {
        cout << "The amount you have entered is below or equal to zero." << endl;
        cout << "You are to go back to paying you monthly due." << endl;
        blankLine();
        createMonthlyDue();
    }
}

void confirmMonthlyDue()
{
    cout << "User " << users[userNumber].loanUserNumber + 1<< ", named " << users[userNumber].firstName << " " << users[userNumber].lastName << "," << endl;
    cout << "Your monthly due of " << users[userNumber].loanUserMonthlyDue << " PHP is to be paid off with " << loanPayment << " PHP." << endl;
    cout << "Do you confirm this or you want to enter your loan payment again [Y for Yes or N for No]? ";

    string answerConfirmMonthlyDue;
    getline(cin >> ws, answerConfirmMonthlyDue);
    blankLine();

    if (answerConfirmMonthlyDue == "Y") {
        cout << "We are to print your receipt for your payment, this includes your change if you paid higher than your loan due." << endl;
        loanChange = loanPayment - users[userNumber].loanUserMonthlyDue;

        for (int i=0; i < users[userNumber].loanUserDuration; i++)
        {
            if (users[userNumber].loanNumberMonthsPaid[i] == false) {
                users[userNumber].loanNumberMonthsPaid[i] = true;
                break;
            }
        }
        blankLine();
    }
    else if (answerConfirmMonthlyDue == "N") {
        cout << "You are to go back to paying your monthly due." << endl;
        blankLine();
        createMonthlyDue();
    } else {
        cout << "You have entered an invalid answer." << endl;
        cout << "You are to confirm your loan payment again." << endl;
        blankLine();
        confirmMonthlyDue();
    }
}

time_t my_time = time(NULL);

void printMonthyDueReceipt()
{
    cout << "Date: " << ctime(&my_time);
    cout << "User #"<< users[userNumber].loanUserNumber << endl;
    cout << "Month Due: " << users[userNumber].loanUserMonthlyDue << " PHP" << endl;
    cout << "Amount Paid: " << loanPayment << " PHP" << endl;
    cout << "Change: " << loanChange << " PHP" << endl;
    blankLine();
}


int main()
{
    cout << "Welcome to Micro Lending Services" << endl;
    blankLine();
    userNumber = 0;

    /*
    // There will be 2 options here
    // Create a loan & Pay one month off a loan
    // If Possible Cancel a Loan; will be included in Option 2
    // Third Option will be show what months are already paid
    // Fourth Option is how much money the Service Maid
    // Message that will appear when the loan is fully paid upon the final payment paid
    // If possible create a way to create, read, update, delete data
    // Create a Minimum amount of loan
    */

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

    setAllUserNumber(); // Sets a numbered id for every user

    // Mock User Details for Option #2
    users[1].userGenerated = true;

    users[1].firstName = "Jenloke";
    users[1].lastName = "Magbojos";
    users[1].age = 31;
    users[1].monthlySalary = 20000;

    users[1].loanUserDuration = 10;
    users[1].loanTotalWithInterest = 5000;

    users[1].loanUserMonthlyDue = 500;
    users[1].loanUserStatus = "Ongoing"; // Paid, Ongoing
    //loanNumberMonthsPaid[loanMaxDuration];
    users[1].loanNumberMonthsPaid[0] = true; // two months paid
    users[1].loanNumberMonthsPaid[1] = true;

    //for (int i=0; i < users[1].loanUserDuration; i++ ) {
    //    users[1].loanNumberMonthsPaid[i] = true;
    //}

    string userChoice;

    while(true) {
        cout << "Select from one of the services offered below" << endl;
        cout << "[1] Create New Loan" << endl;
        cout << "[2] Pay Monthly Due" << endl;
        cout << "[3] Check Users Loan Status" << endl;
        cout << "[4] Print " << endl;
        cout << "[5] Exit" << endl;
        blankLine();

        cout << "You can just go back to the main menu on the" << endl; cout << "confirmation or finalization part of certain options." << endl;
        cout << "Just select the corresponding number: ";
        getline(cin >> ws, userChoice);
        blankLine();

        if (userChoice == "1") {
            for (int i=0; i < totalUsers; i++)
            {
                if (users[i].userGenerated == false) {
                    setUserNumber();

                    enterUserDetails();
                    confirmUserDeatails();

                    createLoanAmount();
                    createLoanDuaration();
                    evaluateLoanDuration();
                    evaluateLoanTotal();
                    evaluateLoanMonthly();
                    evaluateRemainingDue();

                    printLoanDetails();
                    confirmLoan(); // need continue statement to go back to menu
                    printLoanStatus();
                    printLoanBalanceList();

                    blankLine();
                }
                userNumber++;
            }

        }else if (userChoice == "2") {
            selectUser();
            printLoanDetails();
            printLoanStatus();

            evaluateRemainingDue();
            printLoanBalanceList();

            createMonthlyDue();
            confirmMonthlyDue();
            printMonthyDueReceipt();

            evaluateRemainingDue();
            printLoanBalanceList();

            blankLine();

        }else if (userChoice == "5") {
            cout << "Thank you for using our services." << endl;
            cout << "See you again." << endl;
            break;

        }else {
            cout << "You have entered invalid character/s." << endl;
            cout << "Please enter a valid number." << endl;
            cout << "You are to go back to choosing a service." << endl;
            blankLine();
        }
    }

    /*
    // for confirm monthlyDue
    // Checks array if all members of it is true, this will be a function
    int j = 0;
    for (int i=0; i < users[userNumber].loanUserDuration; i++)
    {
        if (users[userNumber].loanNumberMonthsPaid[i] == true) {
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
    */

    //userNumber++;

    return 0;
}