#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main (){
    int numStudents;
    string userID, bookCategory;
    int daysKept;
    float fine;
    ofstream outFile ("borrow_record.txt");

    cout << "=== Library Borrowing System ===" << endl;
    cout << "Type 'exit' as User ID to stop." << endl;
    
    while (true)
    {
        cout << "\nEnter user ID:\n";
        cin >> userID;

        if (userID == "exit"){
            break;
        }
        char moreBooks='y';
        while (moreBooks!= 'n')
        {
            cout << "Enter Book Category (fiction, science, history): ";
            cin >> bookCategory;

            cout << "Enter number of days book was kept: ";
            cin >> daysKept;


            if (daysKept <= 14) {
                fine = 0;
            } else {
                fine = (daysKept - 14) * 2;
            }
            cout << "Student: " << userID << ", Category: " << bookCategory
            << ", Days Kept: " << daysKept << ", Fine: Rs. " << fine << endl;

            outFile << "Student: " << userID << ", Category: " << bookCategory
                    << ", Days Kept: " << daysKept << ", Fine: Rs. " << fine << endl;

            cout << "Do you want to enter another book for this student? (y/n): ";
            cin >> moreBooks;
        }
        
    }
    outFile.close();
    cout << "\nAll records saved in 'borrow_records.txt'." << endl;

    return 0;    
}
