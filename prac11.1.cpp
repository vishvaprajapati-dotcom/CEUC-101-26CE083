#include <iostream>
#include <fstream>

using namespace std;

int globalValue = 100;

int main() {
    cout << "********************************************\n";
    cout << "PROGRAM EXECUTION & ERROR HANDLING ANALYZER\n";
    cout << "********************************************\n\n";

    // Part A: Global, local, and dynamically allocated memory
    cout << "Compile-time and Run-time Memory\n";

    int localValue = 200;
    int* dynamicValue = new int(300);

    cout << "Global Variable Value : " << globalValue << '\n';
    cout << "Local Variable Value : " << localValue << '\n';
    cout << "Dynamic Memory Value : " << *dynamicValue << '\n';

    delete dynamicValue;
    dynamicValue = nullptr;

    cout << "--------------------------------------------\n";

    // Part B: Signed integer overflow demonstration
    cout << "Low-level Error Demonstration\n";

    int largeNumber = 2147483647;
    int overflowResult = largeNumber + 1;

    cout << "Arithmetic Overflow Demonstrated\n";
    cout << "Result : " << overflowResult << '\n';
    cout << "--------------------------------------------\n";

    // Pointer aliasing
    cout << "Pointer Aliasing\n";

    int value = 50;
    int* firstAddress = &value;
    int* secondAddress = &value;

    cout << "Original Value : " << *secondAddress << '\n';
    *firstAddress = 75;
    cout << "Updated Value : " << *secondAddress << '\n';
    cout << "Both address variables refer to the same memory location\n";
    cout << "--------------------------------------------\n";

    // Allocate memory and release it to avoid a memory leak
    cout << "Memory Leak Demonstration\n";

    int* allocatedValue = new int(500);
    cout << "Dynamic Memory Allocated\n";

    delete allocatedValue;
    allocatedValue = nullptr;

    cout << "Memory Released Successfully\n";
    cout << "--------------------------------------------\n";

    // Part C: Input validation and division
    cout << "Arithmetic Operation\n";

    double dividend;
    double divisor;

    cout << "Enter Dividend : ";
    if (!(cin >> dividend)) {
        cout << "Error: Invalid numerical input for the dividend.\n";
        return 1;
    }

    cout << "Enter Divisor : ";
    if (!(cin >> divisor)) {
        cout << "Error: Invalid numerical input for the divisor.\n";
        return 1;
    }

    if (divisor == 0) {
        cout << "Error: Division by zero is not allowed.\n";
    } else {
        cout << "Result : " << dividend / divisor << '\n';
    }

    cout << "--------------------------------------------\n";

    // Try opening a file that does not exist
    cout << "File Operation\n";

    ifstream inputFile("file_that_does_not_exist.txt");

    if (!inputFile) {
        cout << "Unable to open file.\n";
    } else {
        cout << "File opened successfully.\n";
        inputFile.close();
    }

    cout << "--------------------------------------------\n";
    cout << "Program Executed Successfully\n";
    cout << "--------------------------------------------\n";

    return 0;
}

