// COMSC-210 | Lab 11: Pointers II | Aidan Woodcock | 2025-09-21
// IDE used: Visual Studio Code

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct carRegistry {
    string ownerName;
    string licensePlate;
    int numofCar;
    string *carMake;
};

~carRegistry {
    if(carMake) {
        delete[] carMake;
    }

};

int main() {

    return 0;
}