// COMSC-210 | Lab 11: Pointers II | Aidan Woodcock | 2025-09-21
// IDE used: Visual Studio Code
// Program to manage a car owner's registry using structures, pointers, and dynamic memory allocation, this could be useful for a car dealership or rental service.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int REGISTRY_SIZE = 3; 
// Structure to represent a car owner's registry
struct carRegistry {
    string ownerName;    // Name of the car owner
    string licensePlate; // License plate number, could have also been dynamic but kept it simple
    int numofCar;        // Number of cars owned
    string *carMake;     // Dynamic array to store car makes

    // Destructor to clean up dynamically allocated memory
    ~carRegistry() {
        if(carMake) {
            delete[] carMake;
        }
        carMake = nullptr;
    }
};


// Function prototypes
void inputRegistryData(carRegistry *regPtr);
void displayRegistryData(carRegistry *regPtr);

int main() {
    // Create a dynamic array of carRegistry structs
    carRegistry *registry = new carRegistry[REGISTRY_SIZE];
    
    // Input data for each registry entry
    for (int i = 0; i < REGISTRY_SIZE; i++) {
        inputRegistryData(&registry[i]);
    }
    
    // Display all registry data
    for (int i = 0; i < REGISTRY_SIZE; i++) {
        displayRegistryData(&registry[i]);
    }
    
    // Clean up memory by deleting the dynamic array
    delete[] registry;
    
    return 0;
}

// Function definitions
// Function to input data for a car registry entry using pointers and dynamic memory allocation
void inputRegistryData(carRegistry *regPtr) {
    static int ownerCount = 1; // Static variable to track owner number
    cout << "Enter details for owner #" << ownerCount << ":\n";
    cout << "Owner's Name: ";
    cin.ignore(); 
    getline(cin, regPtr->ownerName);
    cout << "License Plate: ";
    getline(cin, regPtr->licensePlate);
    cout << "Number of Cars: ";
    cin >> regPtr->numofCar;
    // Create dynamic array for car makes based on number of cars
    regPtr->carMake = new string[regPtr->numofCar];
    cin.ignore(); 
    for(int j = 0; j < regPtr->numofCar; j++) {
        cout << "Car Make #" << (j + 1) << ": ";
        getline(cin, regPtr->carMake[j]);
    }
    cout << endl << endl;
    ownerCount++;
}

void displayRegistryData(carRegistry *regPtr) {
        static int i = 0;
        cout << "Summary of Car Registry Entry: #" << (i + 1) << endl;
        cout << "Owner #" << (i + 1) << ": " << endl;
        cout << "Owner's Name: " << regPtr->ownerName << endl;
        cout << "License Plate: " << regPtr->licensePlate << endl;
        cout << "Number of Cars: " << regPtr->numofCar << endl;
        for(int j = 0; j < regPtr->numofCar; j++) {
            cout << "Car Make #" << (j + 1) << ": " << regPtr->carMake[j] << endl;
        }
        cout << endl << endl;
        i++;
}