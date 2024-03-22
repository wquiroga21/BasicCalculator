// History.h
#ifndef HISTORY_H
#define HISTORY_H

#include <vector>
#include <string>

// A simple struct to hold individual history entries
struct HistoryEntry {
    double operand1;
    char operation;
    double operand2;
    std::string result;
};

class History {
public:
    void add(double operand1, char operation, double operand2, const std::string& result);
    void print() const;

private:
    std::vector<HistoryEntry> entries;
};
#endif