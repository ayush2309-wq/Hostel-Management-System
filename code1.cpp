#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Hostel {
    string name;
    int rent;
    int beds;

public:
    Hostel(string n = "", int r = 0, int b = 0) {
        name = n;
        rent = r;
        beds = b;
    }

    string getName() { return name; }
    int getRent() { return rent; }
    int getBeds() { return beds; }

    void loadFromFile() {
        ifstream in("Hostel.txt");
        if (in) {
            in >> name >> rent >> beds;
            in.close();
        }
    }

    void updateBeds(int newBeds) {
        beds = newBeds;
        ofstream out("Hostel.txt");
        out << name << " " << rent << " " << beds << endl;
        out.close();
    }

    bool reserveBed() {
        loadFromFile();
        if (beds > 0) {
            updateBeds(beds - 1);
            return true;
        }
        return false;
    }

    void showData() {
        loadFromFile();
        cout << "\n--- Hostel Info ---\n";
        cout << "Name: " << name << "\nRent: " << rent << "\nBeds Available: " << beds << endl;
    }
};

class Student {
    string name, roll, address;

public:
    void inputDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll No: ";
        getline(cin, roll);
        cout << "Enter Address: ";
        getline(cin, address);
    }

    void saveToFile() {
        ofstream out("Students.txt", ios::app);
        out << name << " | " << roll << " | " << address << endl;
        out.close();
    }

    static void showAll() {
        ifstream in("Students.txt");
        string line;
        cout << "\n--- Student Records ---\n";
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
};

int main() {
    // Setup default hostel file if missing
    ifstream test("Hostel.txt");
    if (!test.good() || test.peek() == EOF) {
        ofstream out("Hostel.txt");
        out << "5star 7000 5" << endl;
        out.close();
        cout << "✅ Default Hostel.txt created with 5 beds.\n";
    }
    test.close();

    Hostel hostel;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n=== Hostel Management ===" << endl;
        cout << "1. Reserve a Bed" << endl;
        cout << "2. Show Data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) {
            case 1: {
                hostel.loadFromFile();
                if (hostel.getBeds() > 0) {
                    Student s;
                    s.inputDetails();
                    if (hostel.reserveBed()) {
                        s.saveToFile();
                        cout << "✅ Bed reserved successfully.\n";
                    }
                } else {
                    cout << "❌ No beds available.\n";
                }
                break;
            }

            case 2:
                hostel.showData();
                Student::showAll();
                break;

            case 3:
                running = false;
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
