// History.cpp
#include "History.h"
#include <iostream>

void History::add(double operand1, char operation, double operand2, const std::string& result) {
    entries.push_back({ operand1, operation, operand2, result });
}

void History::print() const {
    for (const auto& entry : entries) {
        std::cout << entry.operand1 << " "
            << entry.operation << " "
            << entry.operand2 << " = "
            << entry.result << std::endl;
    }
}