#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ROOMS = 10;
const double ROOM_RATE = 1000.0;

// Global variables
bool isBooked[MAX_ROOMS] = {false}; // Array to track booking status
string customersName[MAX_ROOMS]; // Array to for customer names


// Function to show menu
void showMenu(){
    cout << "--- Anaa's Hotel ---" << endl;
    cout << "1. View Room Status(specific room)" << endl;
    cout << "2. View all room status" << endl;
    cout << "3. Book a room" << endl;
    cout << "4. Check out" << endl;
    cout << "5. Search booking info" << endl;
    cout << "6. Exit" << endl;
    cout << "-------------------------------------------" << endl;
}

// Function to view room status
void viewRoomStatus(int roomStatus) {
    if (roomStatus < 1 || roomStatus > MAX_ROOMS) {
        cout << "Invalid room number.\n";
        return;
    }
    if (isBooked[roomStatus - 1]) {
        cout << "Room " << roomStatus << " is booked by " << customersName[roomStatus - 1] << endl;
    } else {
        cout << "Room " << roomStatus << " is available.\n";
    }
}
// Function to view all room status
void viewAllRooms() {
    cout << "Room Status:\n";
    for (int i=0; i<MAX_ROOMS; i++) {
        cout << "Room " << (i + 1) << ": ";
        if (isBooked[i]) {
            cout << "Booked by " << customersName[i] << endl;
        } else {
            cout << "Available" << endl;
        }
    }
}
// Function to book a room
void bookRoom() { 
    int room;
    string name;
    cout << "Enter room number (1-10): ";
    cin >> room;

    if (room < 1 || room > MAX_ROOMS) {
        cout << "Invalid room number." << endl;
        return;
    }

    if (!isBooked[room - 1]) {
        cout << "Enter customer name: ";
        cin.ignore(); //this will give a clear input
        getline(cin, name);
        isBooked[room - 1] = true;
        customersName[room - 1] = name;

        ofstream bookinginfoFile("bookings.txt", ios::app);
        bookinginfoFile << "Room " << room << " booked by " << name << endl;
        bookinginfoFile.close();

        cout << "Room " << room << " booked successfully for " << name << endl;
    } else {
        cout << "Room already booked."<<endl;
    }
}

// Function to checkout from the room
void checkoutRoom() {
    int roomInn, days, amountPaid;
    
    cout << "Enter room number: ";
    cin >> roomInn;

    if (roomInn < 1 || roomInn > MAX_ROOMS || !isBooked[roomInn - 1]) {
        cout << "Room is not booked or invalid." << endl;
        return;
    }

    cout << "Enter number of days stayed: ";
    cin >> days;

    int totalBill = days * ROOM_RATE;

    cout << "Total bill: " << totalBill << endl;
    cout << "Enter amount paid: ";
    cin >> amountPaid;

    int balance = amountPaid - totalBill;

    if (balance > 0)
        cout << "Change to return: " << balance << endl;
    else if (balance < 0)
        cout << "Outstanding balance: " << -balance << endl;
    else
        cout << "Payment complete.\n";

    ofstream checkoutFile("checkout.txt", ios::app);
    checkoutFile << "Room " << roomInn << ",\n";
    checkoutFile << "Customer: " << customersName[roomInn - 1] << ",\n";
    checkoutFile << "Days: " << days << ",\n";
    checkoutFile << "Bill: " << totalBill << ",\n";
    checkoutFile << "Paid: " << amountPaid << "\n\n";
    checkoutFile.close();

    isBooked[roomInn - 1] = false;
    customersName[roomInn - 1] = "";

    cout << "Checked out successfully.\n";
}
// Function to search booking info
void searchBookingInfo() {
    int roomSearch;
    cout << "Enter room number (1-10): ";
    cin >> roomSearch;

    if (roomSearch < 1 || roomSearch > MAX_ROOMS) {
        cout << "Invalid room number.\n";
        return;
    }

    if (isBooked[roomSearch - 1]) {
        cout << "Room is booked by " << customersName[roomSearch - 1] << ".\n";
    } else {
        cout << "Room is available.\n";
    }
}


int main(){
    int choice;
    do{
    showMenu();
    cout << "Enter your choice: (1-6)";
    cin >> choice;

    switch (choice) {
        case 1:
            int roomNumber;
            cout << "Enter room number (1-10): ";
            cin >> roomNumber;
            if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
                cout << "The number you have entered is invalid ! Please enter correct number." << endl;
            } else {
                viewRoomStatus(roomNumber);
            }
            break;

        case 2:
            viewAllRooms();
            break;
        case 3:
            bookRoom();
            break;
        case 4:
            checkoutRoom();
            break;
        case 5:
            searchBookingInfo();
            break;
        case 6:
            cout << "Exiting the program" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    } while (choice != 6);
    return 0;
}
