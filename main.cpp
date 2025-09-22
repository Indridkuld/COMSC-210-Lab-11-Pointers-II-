// COMSC-210 | Lab 11: Pointers II | Aidan Woodcock | 2025-09-21
// IDE used: Visual Studio Code

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int REGISTRY_SIZE = 3, CARMAKE_SIZE = 5;

struct carRegistry {
    string ownerName;
    string licensePlate;
    int numofCar;
    string *carMake;

    ~carRegistry() {
        if(carMake) {
            delete[] carMake;
        }
        carMake = nullptr;
};

// Function prototypes
void inputRegistryData(carRegistry *regPtr);
void displayRegistryData(carRegistry *regPtr);

int main() {
    carRegistry *registry = new carRegistry[REGISTRY_SIZE];

    return 0;
}

// Function definitions
// inputs data for a car registry entry using pointers and dynamic memory allocation
void inputRegistryData(carRegistry *regPtr) {
    for(int i = 0; i < REGISTRY_SIZE; i++) {
        cout << "Enter details for owner #" << (i + 1) << ":\n";
        cout << "Owner's Name: ";
        cin.ignore();
        getline(cin, regPtr->ownerName);
        cout << "License Plate: ";
        getline(cin, regPtr->licensePlate);
        cout << "Number of Cars: ";
        cin >> regPtr->numofCar;
        regPtr->carMake = new string[regPtr->numofCar];
        cin.ignore();
        for(int j = 0; j < regPtr->numofCar; j++) {
            cout << "Car Make #" << (j + 1) << ": ";
            getline(cin, regPtr->carMake[j]);
        }
    }
}