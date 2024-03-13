#include <iostream>
#include <list>
#include <vector>
#include <iomanip> 

using namespace std;

using Row = vector<int>;
using Spreadsheet = list<Row>;

void displaySpreadsheet(const Spreadsheet& spreadsheet) {
    cout << "Spreadsheet:" << endl;
    for (const auto& row : spreadsheet) {
        for (int cell : row) {
            cout << "+-----";
        }
        cout << "+" << endl;
        for (int cell : row) {
            cout << "| " << setw(3) << cell << " ";
        }
        cout << "|" << endl;
        for (int cell : row) {
            cout << "+-----";
        }
        cout << "+" << endl;
    }
}

void addRow(Spreadsheet& spreadsheet) {
    int numCols;
    cout << "Enter the number of columns: ";
    cin >> numCols;

    Row newRow(numCols);
    cout << "Enter data for the new row:" << endl;
    for (int i = 0; i < numCols; ++i) {
        cin >> newRow[i];
    }

    spreadsheet.push_back(newRow);
}

void deleteRow(Spreadsheet& spreadsheet) {
    int rowNum;
    cout << "Enter the row number to delete (0-based indexing): ";
    cin >> rowNum;

    if (rowNum < 0 || rowNum >= spreadsheet.size()) {
        cout << "Invalid row number!" << endl;
        return;
    }

    auto it = spreadsheet.begin();
    advance(it, rowNum);
    spreadsheet.erase(it);
}

int main() {
    Spreadsheet spreadsheet;


    displaySpreadsheet(spreadsheet);

    int choice;
    do {
        cout << "\nMenu:\n1. Add Row\n2. Delete Row\n3. Display Spreadsheet\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addRow(spreadsheet);
            break;
        case 2:
            deleteRow(spreadsheet);
            break;
        case 3:
            displaySpreadsheet(spreadsheet);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid choice." << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}