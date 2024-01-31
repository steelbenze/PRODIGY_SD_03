#include <bits/stdc++.h>
using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
    string emailAddress;
};

// Function prototypes
void addContact(vector<Contact> &contacts);
void viewContacts(const vector<Contact> &contacts);
void editContact(vector<Contact> &contacts);
void deleteContact(vector<Contact> &contacts);
void saveContactsToFile(const vector<Contact> &contacts, const string &filename);
void loadContactsFromFile(vector<Contact> &contacts, const string &filename);

int main() {
    vector<Contact> contacts;
    string filename = "contacts.txt";
    loadContactsFromFile(contacts, filename);

    char choice;
    do {
        cout << "\nContact Management System" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Save Contacts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                addContact(contacts);
                break;
            case '2':
                viewContacts(contacts);
                break;
            case '3':
                editContact(contacts);
                break;
            case '4':
                deleteContact(contacts);
                break;
            case '5':
                saveContactsToFile(contacts, filename);
                break;
            case '6':
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != '6');

    return 0;
}

void addContact(vector<Contact> &contacts) {
    Contact newContact;
    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.emailAddress);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts(const vector<Contact> &contacts) {
    cout << "Contacts List:" << endl;
    for (const auto &contact : contacts) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phoneNumber << ", Email: " << contact.emailAddress << endl;
    }
}

void editContact(vector<Contact> &contacts) {
    string nameToEdit;
    cout << "Enter the name of the contact you want to edit: ";
    getline(cin, nameToEdit);
    for (auto &contact : contacts) {
        if (contact.name == nameToEdit) {
            cout << "Enter new phone number: ";
            getline(cin, contact.phoneNumber);
            cout << "Enter new email address: ";
            getline(cin, contact.emailAddress);
            cout << "Contact updated successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void deleteContact(vector<Contact> &contacts) {
    string nameToDelete;
    cout << "Enter the name of the contact you want to delete: ";
    getline(cin, nameToDelete);
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == nameToDelete) {
            it = contacts.erase(it);
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found!" << endl;
}

void saveContactsToFile(const vector<Contact> &contacts, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &contact : contacts) {
            file << contact.name << "," << contact.phoneNumber << "," << contact.emailAddress << endl;
        }
        file.close();
        cout << "Contacts saved to file successfully!" << endl;
    } else {
        cout << "Unable to open file for saving contacts!" << endl;
    }
}

void loadContactsFromFile(vector<Contact> &contacts, const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Contact contact;
            size_t pos1 = line.find(",");
            size_t pos2 = line.find(",", pos1 + 1);
            contact.name = line.substr(0, pos1);
            contact.phoneNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
            contact.emailAddress = line.substr(pos2 + 1);
            contacts.push_back(contact);
        }
        file.close();
        cout << "Contacts loaded from file successfully!" << endl;
    } else {
        cout << "No existing contacts file found. Starting with an empty contact list." << endl;
    }
}
