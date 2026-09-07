#include <iostream>
using namespace std;

class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Processing UPI payment of Rs. " << amount << endl;

        cout << "UPI payment successful." << endl;
        return true;
    }
};