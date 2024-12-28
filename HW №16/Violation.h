#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Violation
{
private:
    string description;
    double fine;
    string date;

public:
    Violation(string description, double fine, string date)
        : description(description), fine(fine), date(date) {
    }

    string getDescription() const { return description; }
    double getFine() const { return fine; }
    string getDate() const { return date; }

    void printViolation() const
    {
        cout << "Опис: " << description << endl;
        cout << "Сума штрафу: " << fine << endl;
        cout << "Дата: " << date << endl;
    }
};