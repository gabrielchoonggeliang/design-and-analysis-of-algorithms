#include <iostream>
#include <string>
#include "admin.hpp"
#include "reception.hpp"

using namespace std;

// Function prototypes
bool authenticateUser();
void systemPanel();
void adminControlPanel();
void receptionControlPanel();

// Global variables
const string correctUsername = "user";
const string correctPassword = "123456";

int main() {
    cout << "Welcome to the Hotel Management System\n";

    // Authenticate the user
    if (authenticateUser()) {
        // User is authenticated, show the system panel
        systemPanel();
    } else {
        cout << "Authentication failed. Exiting...\n";
    }

    return 0;
}

bool authenticateUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    return (username == correctUsername && password == correctPassword);
}

void systemPanel() {
    int choice;
    cout << "System Panel\n";
    cout << "1. Log in as Admin\n";
    cout << "2. Log in as Reception Staff\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            adminControlPanel();
            break;
        case 2:
            receptionControlPanel();
            break;
        case 3:
            cout << "Exiting the system...\n";
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
    }
}

