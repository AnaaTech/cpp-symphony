#include <iostream>
#include <fstream>
using namespace std;

int main() {
    double budget;
    double totalExpense = 0, maxExpense = 0, minExpense = 9999999, dailyExpense;

    //  Input Weekly Budget
    cout << "Enter your weekly budget: ";
    cin >> budget;
    ofstream budgetFile("budget.txt");
    budgetFile << budget;
    budgetFile.close();

    //  Input Daily Expenses
    ofstream expensesFile("expenses.txt");
    for (int day = 1; day <= 7; day++) {
        do {
            cout << "Enter expense for Day " << day << ": ";
            cin >> dailyExpense;
            if (dailyExpense < 0) {
                cout << "Expense cannot be negative. Re-enter: ";
            }
        } while (dailyExpense < 0);
        
        expensesFile << dailyExpense << "\n";
        totalExpense += dailyExpense;
        if (dailyExpense > maxExpense) maxExpense = dailyExpense;
        if (dailyExpense < minExpense) minExpense = dailyExpense;
    }
    expensesFile.close();

    double averageExpense = totalExpense / 7;

    //  Read and Compare Budget
    ifstream budgetRead("budget.txt");
    budgetRead >> budget;
    budgetRead.close();
    
    //  Display Expenses from File
    ifstream expensesRead("expenses.txt");
    cout << "\nReading expenses from file...\n\n";
    int day = 1;
    while (expensesRead >> dailyExpense) {
        cout << "Day " << day << " expense: " << dailyExpense << "\n";
        day++;
    }
    expensesRead.close();

    cout << "\n========= Weekly Expense Summary =========\n";
    cout << "Total Expense: " << totalExpense << "\n";
    cout << "Average Daily Expense: " << averageExpense << "\n";
    cout << "Maximum Expense: " << maxExpense << "\n";
    cout << "Minimum Expense: " << minExpense << "\n\n";

    cout << "========== Budget Feedback ==========\n";
    if (totalExpense > budget) {
        cout << "You exceeded your budget by " << (totalExpense - budget) << " units.\n";
    } else if (totalExpense == budget) {
        cout << "You used exactly your budget. Well planned!\n";
    } else {
        cout << "You saved " << (budget - totalExpense) << " units this week. Great job!\n";
    }
    
    //  Generate Insightful Messages
    cout << "\n========== Insights ==========\n";
    if (maxExpense > 2000) {
        cout << "You had at least one large expense day (>2000).\n";
    }
    if (averageExpense < 1000) {
        cout << "Good job keeping your expenses low on average!\n";
    }
    
    cout << "\n============================================\n";
    cout << "      Thank you for using My Expense Buddy!\n";
    cout << "============================================\n";
    
    return 0;
}
