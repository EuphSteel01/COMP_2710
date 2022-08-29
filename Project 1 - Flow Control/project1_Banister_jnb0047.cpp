//  FILE NAME: project1_Banister_jnb0047.cpp
//  AUTHOR: Jess Banister
//
// SOURCES: Used StackOverflow to learn how to use and impliment it in the peoject.
// Used StackOverflow to learn how to use .clear() and .ignore().
//
//

#include <iostream>
using namespace std;
int main() {
    //Variable Initialization

    int currentMonth = 0;
    double interestTest = 0;
    double interest = 0;
    double loan = 0;
    double interestRate = 0;
    double interestRateC = 0;
    double monthlyPaid = 0;
    double interestTotal = 0;
    double principle = 0.0;
    double principleTest = 0.0;

    // CURRENCY FORMATTING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // USER INPUT
    cout << "\nLoan Amount: ";
    cin >> loan;
    if (loan < 0 || !cin) {
        cout << "Invalid loan" << endl;
        cout.clear();
        cin.ignore(20, '\n');
        return 0;
    }
    // Fix because hint says that code will not advance
    // until a "positive loan"is entered.
    cout << "Interest Rate (% per year): ";
    cin >> interestRate;
    if (interestRate < 0 || !cin) {
        cout << "Invalid interest rate" << endl;
        cout.clear();
        cin.ignore(20, '\n');
        return 0;
    }
    // Fix because hint says that code will not advance
    // until a "positive intrest rate"is entered.
    // GET PROPER INTEREST RATES FOR CALCULATIONS
    interestRate /= 12;
    interestRateC = interestRate / 100;
    
    cout << "Monthly Payments: ";
    cin >> monthlyPaid;
    if (monthlyPaid < 0 || !cin) {
        cout << "Invalid payment" << endl;
        cout.clear();
        cin.ignore(20, '\n');
        return 0;
    }

    //Won't move forward until monthly payment is sufficient.
    interestTest = interestRateC * loan;
    principleTest = monthlyPaid - interestTest;
    if (principleTest <= 0) {
        cout << "Insufficient payment" << endl;
        cout.clear();
        cin.ignore(20, '\n');
        return 0;

    }
    
    // AMORTIZATION TABLE
    cout << "*****************************************************************\n"
    << "\tAmortization Table\n"
    << "*****************************************************************\n"
    << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

    // LOOP TO FILL TABLE
    while (loan > 0) {
    if (currentMonth == 0) {
    cout << currentMonth++ << "\t$" << loan;
    if (loan < 1000) cout << "\t"; // Formatting MAGIC
    cout << "\t"  <<"N/A\tN/A\tN/A\t\tN/A\n";
    }
    else {
        while (loan * (1 + interestRateC) > monthlyPaid) {
            interest = interestRateC * loan;
            principle = monthlyPaid - interest;
            loan = loan - principle;
            interestTotal = interest + interestTotal;
            cout << currentMonth++ << "\t$" << loan;
            cout << "\t\t$" << monthlyPaid << "\t";
            cout << interestRate << "\t$" << interest;
            cout << "\t\t$" << principle << endl;
        }
        
        if (loan * (1 + interestRateC) <= monthlyPaid) {
            interest = interestRateC * loan;
            monthlyPaid = interest + loan;
            principle = loan;
            loan = loan - principle;
            interestTotal = interest + interestTotal;
            cout << currentMonth++ << "\t$" << loan;
            cout << "\t\t$" << monthlyPaid << "\t";
            cout << interestRate << "\t$" << interest;
            cout << "\t\t$" << principle << endl;
        }
    }
    }
    
    cout << "****************************************************************\n";
    cout << "\nIt takes " << --currentMonth << " months to pay off "
    << "the loan.\n"
    << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    return 0;
    
}
