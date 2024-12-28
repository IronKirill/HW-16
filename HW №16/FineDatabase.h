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
            cout << "����� ������: " << i.first << endl;

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
            cout << "����� ������: " << it->first << endl;

            for (auto violation : it->second)
            {
                violation.printViolation();
            }
        }

        else
        {
            cout << "���� ����� ��� ������ � �������: " << carNumber << endl;
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
            cout << "���� ����� ��� ������ � �������: " << carNumber << endl;
            return 0;
        }
    }

    void payFine(string carNumber)
    {
        auto it = database.find(carNumber);

        if (it != database.end())
        {
            it->second.clear();
            cout << "������ ��� ������ " << carNumber << " ��������." << endl;
        }

        else
        {
            cout << "���� ����� ��� ������ � �������: " << carNumber << endl;
        }
    }

    void searchByDate(string startDate, string endDate) const
    {
        cout << "�������������� � " << startDate << " �� " << endDate << ":\n";

        for (auto i : database)
        {

            for (auto violation : i.second)
            {
                if (violation.getDate() >= startDate && violation.getDate() <= endDate)
                {
                    cout << "����� ������: " << i.first << endl;
                    violation.printViolation();
                }
            }
        }
    }
};