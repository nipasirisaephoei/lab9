#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
    double loan, rate, pay;
    int year = 1;

    cout << "Enter initial loan: ";
    cin >> loan;

    cout << "Enter interest rate per year (%): ";
    cin >> rate;

    cout << "Enter amount you can pay per year: ";
    cin >> pay;

    // table header
    cout << setw(13) << left << "EndOfYear#"; 
    cout << setw(13) << left << "PrevBalance"; 
    cout << setw(13) << left << "Interest"; 
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";
    
    cout << fixed << setprecision(2);

    // loop until loan is fully paid
    while (loan > 0) {
        double prevBalance = loan;
        double interest = prevBalance * rate / 100.0;
        double total = prevBalance + interest;

        // last year payment check
        double payment = (pay > total) ? total : pay;
        double newBalance = total - payment;

        cout << setw(13) << left << year;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        loan = newBalance;
        year++;
    }

    return 0;
}
