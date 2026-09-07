#include <iostream>
#include <vector>
using namespace std;

class PriceCalculator {
public:
    double calculateTotal(vector<SeatType> seatTypes) {
        double total = 0;

        for (SeatType type : seatTypes) {
            if (type == SeatType::SILVER) {
                total += 150;
            }
            else if (type == SeatType::GOLD) {
                total += 250;
            }
            else if (type == SeatType::PLATINUM) {
                total += 400;
            }
        }

        return total;
    }
};