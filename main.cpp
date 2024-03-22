// main.cpp
#include <iostream>
#include <iomanip>
#include "Calculator.h"
#include "History.h"
#include <limits>
#include <sstream>
#include <locale>
#include <cmath>

std::string formatWithCommas(double value) {
    std::stringstream ss;
    ss.imbue(std::locale(""));  // Use the user's locale to insert thousand separators
    if (std::fmod(value, 1.0) == 0.0) { // Check if the value is an integer
        ss << std::noshowpoint << value;
    }
    else {
        ss << std::fixed << std::setprecision(2) << value; // For non-integers, show two decimal places
    }
    return ss.str();
}

int main() {
    Calculator calc;
    History history;
    double a, b;
    char operation;
    bool running = true;

    // Message to the user on how to use the program
    std::cout << "Welcome to the Simple Calculator!\n"
        << "\nInstructions:\n"
        << "1. Enter the first number.\n"
        << "2. Enter an operation (+, -, *, /).\n"
        << "3. Enter the second number.\n"
        << "4. After the result is displayed, you can perform another calculation.\n"
        << "5. Enter 'q' at the first prompt to exit the program and view the calculation history.\n\n";

    while (running) {
        std::cout << "Enter first number (or 'q' to quit): ";
        std::string input;
        std::cin >> input;

        if (input == "q" || input == "Q") {
            running = false;
            break;
        }

        std::stringstream ss(input);
        if (!(ss >> a)) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        do {
            std::cout << "Enter operation ( +, -, *, / ): ";
            std::cin >> operation;
            if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
                std::cout << "Invalid operation. Please select a valid operation." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        } while (true);

        std::cout << "Enter second number: ";
        while (!(std::cin >> b)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        try {
            double result = 0;
            switch (operation) {
            case '+': result = calc.add(a, b); break;
            case '-': result = calc.subtract(a, b); break;
            case '*': result = calc.multiply(a, b); break;
            case '/': result = calc.divide(a, b); break;
            default: continue;
            }

            std::string formattedResult = formatWithCommas(result);
            history.add(a, operation, b, formattedResult);
            std::cout << "Result: " << formattedResult << std::endl;

        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Print the calculation history before exiting the program.
    std::cout << "\nCalculation History:" << std::endl;
    history.print();

    return 0;
}
