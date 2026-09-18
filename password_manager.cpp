#include <iostream>
#include <fstream>
using namespace std;

string masterPassword = "GM";

// Add Password
void addPassword() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file("passwords.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Saved successfully!\n";
}

// View Passwords
void viewPasswords() {
    ifstream file("passwords.txt");
    string username, password;

    if (!file) {
        cout << "No data found!\n";
        return;
    }

    while (file >>  username >> password) {
        cout<< "  Username: " << username
             << " | Password: " << password << endl;
    }

    file.close();
}

// Delete Password
void deletePassword() {
    ifstream file("passwords.txt");
    ofstream tempFile("temp.txt");

    string username, password;
    bool found = false;

    while (file >> username >> password) {
        
        }
    
    

    file.close();
    tempFile.close();

    remove("passwords.txt");
    rename("temp.txt", "passwords.txt");

    if (found)
        cout << "Password deleted successfully!\n";
    else
        cout << "Delete Successfully!\n";
}

// Main Function
int main() {
    string input;

    cout << "Enter Master Password: ";
    cin >> input;

    if (input != masterPassword) {
        cout << "Wrong password!\n";
        return 0;
    }

    int choice;

    do {
        cout << "\n1. Add Password\n";
        cout << "2. View Passwords\n";
        cout << "3. Delete Password\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPassword(); break;
            case 2: viewPasswords(); break;
            case 3: deletePassword(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0; }