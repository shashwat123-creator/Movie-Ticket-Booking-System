#include <iostream>
using namespace std;

class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Processing Card payment of Rs. " << amount << endl;

        cout << "Card payment successful." << endl;
        return true;
    }
};