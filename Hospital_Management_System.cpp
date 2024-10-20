#include <iostream>
#include <vector>
#include <algorithm>  // For find_if
#include <string>
using namespace std;

// Structure to hold patient details
struct Patient {
    string name;
    int age;
    string disease;
};

// Function to display a patient's details
void displayPatient(const Patient& p) {
    cout << "Name: " << p.name << ", Age: " << p.age << ", Disease: " << p.disease << endl;
}

// Function to add a new patient
void addPatient(vector<Patient>& patients) {
    Patient p;
    cout << "Enter patient name: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, p.name);
    cout << "Enter patient age: ";
    cin >> p.age;
    cout << "Enter disease: ";
    cin.ignore();
    getline(cin, p.disease);
    patients.push_back(p);
    cout << "Patient added successfully!" << endl;
}

// Function to view all patients
void viewPatients(const vector<Patient>& patients) {
    if (patients.empty()) {
        cout << "No patients found!" << endl;
    } else {
        for (const auto& p : patients) {
            displayPatient(p);
        }
    }
}

// Function to search for a patient by name
void searchPatient(const vector<Patient>& patients) {
    string name;
    cout << "Enter the name of the patient to search: ";
    cin.ignore();
    getline(cin, name);

    auto it = find_if(patients.begin(), patients.end(), [&name](const Patient& p) {
        return p.name == name;
    });

    if (it != patients.end()) {
        cout << "Patient found: " << endl;
        displayPatient(*it);
    } else {
        cout << "Patient not found!" << endl;
    }
}

int main() {
    vector<Patient> patients;  // To store patient records
    int choice;

    do {
        cout << "\nHospital Management System" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. View All Patients" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient(patients);
                break;
            case 2:
                viewPatients(patients);
                break;
            case 3:
                searchPatient(patients);
                break;
            case 4:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
