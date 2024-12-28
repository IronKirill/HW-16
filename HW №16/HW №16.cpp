#include "Violation.h"
#include "FineDatabase.h"

int main()
{
    setlocale(0, "");


    FineDatabase database;

    database.addViolation("AA1234BB", Violation("Перевищення швидкостi", 500, "20.12.2024"));
    database.addViolation("AA1234BB", Violation("Проїзд на червоне свiтло", 800, "21.12.2024"));
    database.addViolation("BB5678CC", Violation("Паркування у забороненiй зонi", 300, "19.12.2024"));

    database.printDatabase();
    cout << endl;

    database.printByCarNumber("AA1234BB");
    cout << endl;

    double total = database.totalFines("AA1234BB");
    cout << "Сума штрафiв для машини AA1234BB: " << total << " грн\n";
    cout << endl;

    database.payFine("AA1234BB");
    database.printByCarNumber("AA1234BB");
    cout << endl;

    database.searchByDate("19.12.2024", "21.12.2024");
}