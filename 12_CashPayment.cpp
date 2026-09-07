#include <iostream>
using namespace std;

class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Processing Cash payment of Rs. " << amount << endl;

        cout << "Cash payment successful." << endl;
        return true;
    }
};