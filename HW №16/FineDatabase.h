#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class FineDatabase
{
private:
    map<string, vector<Violation>> database;

public:
    void addViolation(string carNumber, Violation violation)
    {
        database[carNumber].push_back(violation);
    }

    void printDatabase() const
    {
        for (auto i : database)
        {
            cout << "Номер машини: " << i.first << endl;

            for (auto violation : i.second)
            {
                violation.printViolation();
            }
        }
    }

    void printByCarNumber(string carNumber) const
    {
        auto it = database.find(carNumber);

        if (it != database.end())
        {
            cout << "Номер машини: " << it->first << endl;

            for (auto violation : it->second)
            {
                violation.printViolation();
            }
        }

        else
        {
            cout << "Немає даних для машини з номером: " << carNumber << endl;
        }
    }

    double totalFines(string carNumber) const
    {
        auto it = database.find(carNumber);

        if (it != database.end())
        {
            double total = 0;

            for (auto violation : it->second)
            {
                total += violation.getFine();
            }
            return total;
        }

        else
        {
            cout << "Немає даних для машини з номером: " << carNumber << endl;
            return 0;
        }
    }

    void payFine(string carNumber)
    {
        auto it = database.find(carNumber);

        if (it != database.end())
        {
            it->second.clear();
            cout << "Штрафи для машини " << carNumber << " сплачено." << endl;
        }

        else
        {
            cout << "Немає даних для машини з номером: " << carNumber << endl;
        }
    }

    void searchByDate(string startDate, string endDate) const
    {
        cout << "Правопорушення з " << startDate << " по " << endDate << ":\n";

        for (auto i : database)
        {

            for (auto violation : i.second)
            {
                if (violation.getDate() >= startDate && violation.getDate() <= endDate)
                {
                    cout << "Номер машини: " << i.first << endl;
                    violation.printViolation();
                }
            }
        }
    }
};