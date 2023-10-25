#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

int
main()
{

    string carMake, carModel;

    double annualInterestRate, monthlyInterestRate, price, downPayment,
        tradeIn;

    double principal, monthlyPayment, salesTaxRate, salesTax,
        totalPaid;
    double totalInterestPaid = 0;

    int numYears, numMonths;

    double monthlyPrincipal, monthlyInterest, loanBalance;

    // get inputs

    cout << "Vehicle Loan Payment Calculator\n";

    cout << "-------------------------------\n";

    cout << "Please provide the following information.\n\n";

    cout << "Vehicle make: ";

    cin >> carMake;

    cout << "Vehicle model: ";

    cin >> carModel;

    cout << "Price of the vehicle ($): ";

    cin >> price;

    while (price < 0)
    {

        cout << "Invalid input, please input a positive number" << endl;

        cout << "Price of the vehicle ($): ";

        cin >> price;

    }

    cout << "Sales tax rate (%): ";

    cin >> salesTaxRate;

    while (salesTaxRate < 0 or salesTaxRate > 100)
    {

        cout << "Invalid input, please input a number between 0 and 100" <<
            endl;

        cout << "Sales tax rate (%): ";

        cin >> salesTaxRate;

    }

    cout << "Down payment amount ($): ";

    cin >> downPayment;

    while (downPayment > price or downPayment < 0)
    {

        cout <<
            "Invalid input, please input a number greater than 0, and less than "
            << price << endl;

        cout << "Down payment amount ($): ";

        cin >> downPayment;

    }

    cout << "Trade-in value ($): ";

    cin >> tradeIn;

    while (tradeIn < 0)
    {

        cout << "Invalid input, please input a positive number or zero" <<
            endl;

        cout << "Trade-in value ($): ";

        cin >> tradeIn;

    }

    cout << "Annual interest rate (%): ";

    cin >> annualInterestRate;

    while (annualInterestRate < 0 or annualInterestRate > 100)
    {

        cout << "Invalid input, please input a number between 0 and 100" <<
            endl;

        cout << "Annual interest rate (%): ";

        cin >> annualInterestRate;

    }

    cout << "Number of years of the loan: ";

    cin >> numYears;

    // calculate monthly payment

    salesTax = price * (salesTaxRate / 100);

    principal = price + salesTax - downPayment - tradeIn;

    monthlyInterestRate = annualInterestRate / 12 / 100;

    numMonths = numYears * 12;

    monthlyPayment =
        (principal * monthlyInterestRate) / (1 -
            pow(1 + monthlyInterestRate,
                -numMonths));

    // format numbers to two decimal points

    cout.setf(ios::fixed);

    cout.setf(ios::showpoint);

    cout.precision(2);

    // display results

    cout << endl << endl;

    cout << "Summary of Loan\n";

    cout << "---------------\n";

    cout << "Vehicle:             \t" << carMake << " " << carModel << endl;

    cout << "Price:               \t$" << price << endl;

    cout << "Sales Tax:           \t$" << salesTax << " @" << salesTaxRate <<
        "%" << endl;

    cout << "Down payment:        \t$" << downPayment << endl;

    cout << "Trade-in value:      \t$" << tradeIn << endl;

    cout << "Loan principal:      \t$" << principal << endl;

    cout << "Annual Interest Rate:\t" << annualInterestRate << "%" << endl;;

    cout << "Term (years):        \t" << numYears << endl;

    cout << "Monthly Payment:     \t$" << monthlyPayment << endl;

    cout << endl << endl;

    cout << "Payoff Summary for the first twelve months\n";

    cout << "------------------------------------------\n\n";

    cout << setw(5) << "Month";

    cout << setw(18) << "Payment Amt ($)";

    cout << setw(18) << "Principal ($)";

    cout << setw(15) << "Interest ($)";

    cout << setw(18) << "Loan Balance ($)" << endl;

    cout << setw(5) << "-----";

    cout << setw(18) << "---------------";

    cout << setw(18) << "-------------";

    cout << setw(15) << "------------";

    cout << setw(18) << "----------------" << endl;

    // calcaulte monthly principal and interest contributions and balance

    loanBalance = principal;

    for (int i = 1; i <= numMonths; ++i)
    {

        monthlyInterest = loanBalance * monthlyInterestRate;


        totalInterestPaid += monthlyInterest;
        monthlyPrincipal = monthlyPayment - monthlyInterest;

        loanBalance = loanBalance - monthlyPrincipal;

        cout << setw(5) << i;

        cout << setw(18) << monthlyPayment;

        cout << setw(18) << monthlyPrincipal;

        cout << setw(15) << monthlyInterest;

        cout << setw(18) << loanBalance << endl;

    }
    cout << endl << endl;
    totalPaid = price + totalInterestPaid + salesTax;
    cout << "The total interest paid over the loan duration is " << totalInterestPaid << "\n";
    cout << "The total amount paid over the loan duration is " << totalPaid;

    return 0;

}
