#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //declaring input file
    ifstream inputFile("students.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open students.txt" << endl;
        return 1;
    }

    // Student attributes are stored in separate variables
    int id1, age1;
    float gpa1;
    char section1;
    string name1;

    int id2, age2;
    float gpa2;
    char section2;
    string name2;

    //code starts:
    if (!(inputFile >> id1)) {
        cerr << "Error: Invalid file format or insufficient data." << endl;
        return 1;
    }
    inputFile.ignore(); // a newline
    getline(inputFile, name1);
    inputFile >> age1 >> gpa1 >> section1;

    if (!(inputFile >> id2)) {
        cerr << "Error: Invalid file format or insufficient data." << endl;
        return 1;
    }
    inputFile.ignore(); // a newline
    getline(inputFile, name2);
    inputFile >> age2 >> gpa2 >> section2;

    inputFile.close();
    //criteria conditions
    float minGPA;
    char targetSection;
    cout << "Enter minimum GPA: ";
    cin >> minGPA;
    cout << "Enter target section: ";
    cin >> targetSection;

    // Determine qualification and honors score based on criteria
    bool qualifies1 = (gpa1 >= minGPA && section1 == targetSection);
    bool qualifies2 = (gpa2 >= minGPA && section2 == targetSection);

    float honorsScore1 = qualifies1 ? gpa1 * age1 : -1;
    float honorsScore2 = qualifies2 ? gpa2 * age2 : -1;

    bool outstanding1 = honorsScore1 > 75;
    bool outstanding2 = honorsScore2 > 75;

    // Determine top student after criteria match
    string topStudentName = "None";
    int topStudentID = -1;
    float topHonorsScore = -1;

    if (qualifies1 && (!qualifies2 || honorsScore1 > honorsScore2)) {
        topStudentName = name1;
        topStudentID = id1;
        topHonorsScore = honorsScore1;
    } else if (qualifies2) {
        topStudentName = name2;
        topStudentID = id2;
        topHonorsScore = honorsScore2;
    }

    // Printing results
    cout << "\n--------------------------------------------------\n";
    cout << "         Dual Student Performance Comparator      \n";
    cout << "--------------------------------------------------\n";
    cout << "\nStudent Records:\n";
    cout << "--------------------------------------------------\n";

    cout << "ID: " << id1 << ", Name: " << name1
         << ", Age: " << age1 << ", GPA: " << gpa1
         << ", Section: " << section1 << ", Honors Score: ";
    if (qualifies1)
        cout << honorsScore1 << (outstanding1 ? ", Status: Outstanding" : "") << "\n";
    else
        cout << "N/A\n";

    cout << "ID: " << id2 << ", Name: " << name2
         << ", Age: " << age2 << ", GPA: " << gpa2
         << ", Section: " << section2 << ", Honors Score: ";
    if (qualifies2)
        cout << honorsScore2 << (outstanding2 ? ", Status: Outstanding" : "") << "\n";
    else
        cout << "N/A\n";

    cout << "--------------------------------------------------\n";

    if (topStudentID != -1) {
        cout << "\nTop Student:\n";
        cout << "ID: " << topStudentID << ", Name: " << topStudentName
             << ", Honors Score: " << topHonorsScore << "\n";

        ofstream outputFile("top_student.txt");
        if (outputFile) {
            outputFile << "ID: " << topStudentID << ", Name: " << topStudentName
                       << ", Honors Score: " << topHonorsScore << "\n";
            outputFile.close();
        } else {
            cerr << "Error: Unable to write to top_student.txt" << endl;
        }
    } else {
        cout << "No top student found.\n";
    }

    return 0;
}
