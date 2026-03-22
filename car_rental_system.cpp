#include <iostream>
#include <string>
using namespace std;

// Base Class
class Vehicle {
public:
    int id;
    string brand;
    string model;
    float ratePerDay;
    int isAvailable; // 1 = available, 0 = rented

    Vehicle(int id, string brand, string model, float rate) {
        this->id = id;
        this->brand = brand;
        this->model = model;
        this->ratePerDay = rate;
        isAvailable = 1;
    }

    void displayInfo() {
        cout << "\nID: " << id << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Rate: Rs." << ratePerDay << "/day" << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Rented") << endl;
    }
};

// Car Class
class Car : public Vehicle {
public:
    int seats;

    Car(int id, string brand, string model, float rate, int seats)
        : Vehicle(id, brand, model, rate) {
        this->seats = seats;
    }

    void displayInfo() {
        cout << "\n[CAR]";
        Vehicle::displayInfo();
        cout << "Seats: " << seats << endl;
    }
};

// Customer Class
class Customer {
public:
    int id;
    string name;
    string contact;

    Customer(int id, string name, string contact) {
        this->id = id;
        this->name = name;
        this->contact = contact;
    }

    void display() {
        cout << "Customer ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Contact: " << contact << endl;
    }
};

// Rental Class
class Rental {
    static int count;
    int rentalId;
    Customer customer;
    Vehicle* vehicle;
    int days;
    float total;

public:
    Rental(Customer c, Vehicle* v, int d) : customer(c) {
        rentalId = ++count;
        vehicle = v;
        days = d;
        total = v->ratePerDay * d;
        v->isAvailable = 0;
    }

    void receipt() {
        cout << "\n----- RECEIPT -----\n";
        cout << "Rental ID: " << rentalId << endl;
        customer.display();
        cout << "Vehicle: " << vehicle->brand << " " << vehicle->model << endl;
        cout << "Days: " << days << endl;
        cout << "Total: Rs." << total << endl;
    }
};

int Rental::count = 0;

// System Class
class CarRentalSystem {
    Vehicle* v[5];
    Rental* rentals[10];
    int vCount, rCount, cId;

public:
    CarRentalSystem() {
        vCount = 5;
        rCount = 0;
        cId = 1;

        v[0] = new Car(1, "Hyundai", "Creta", 3000, 5);
        v[1] = new Car(2, "Kia", "Seltos", 3200, 5);
        v[2] = new Car(3, "BMW", "X5", 6000, 5);
        v[3] = new Car(4, "Toyota", "Fortuner", 5000, 7);
        v[4] = new Car(5, "Audi", "A6", 7000, 5);
    }

    void showVehicles(int onlyAvailable) {
        cout << "\n----- CAR LIST -----\n";
        for (int i = 0; i < vCount; i++) {
            if (!onlyAvailable || v[i]->isAvailable) {
                v[i]->displayInfo();
            }
        }
    }

    Vehicle* findVehicle(int id) {
        for (int i = 0; i < vCount; i++) {
            if (v[i]->id == id && v[i]->isAvailable)
                return v[i];
        }
        return NULL;
    }

    void rentVehicle() {
        int id, days;
        string name, contact;

        showVehicles(1);

        cout << "\nEnter Car ID: ";
        cin >> id;

        Vehicle* vehicle = findVehicle(id);
        if (vehicle == NULL) {
            cout << "Car not available\n";
            return;
        }

        cin.ignore();
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter contact: ";
        getline(cin, contact);

        cout << "Enter days: ";
        cin >> days;

        Customer c(cId++, name, contact);
        rentals[rCount++] = new Rental(c, vehicle, days);

        rentals[rCount - 1]->receipt();
    }

    void returnVehicle() {
        int id;
        cout << "\nEnter Car ID to return: ";
        cin >> id;

        for (int i = 0; i < vCount; i++) {
            if (v[i]->id == id && !v[i]->isAvailable) {
                v[i]->isAvailable = 1;
                cout << "Car returned successfully\n";
                return;
            }
        }
        cout << "Invalid ID\n";
    }

    void menu() {
        int ch;
        do {
            cout << "\n========== CAR RENTAL SYSTEM ==========\n";
            cout << "1. View All Cars\n";
            cout << "2. View Available Cars\n";
            cout << "3. Rent a Car\n";
            cout << "4. Return a Car\n";
            cout << "5. Exit\n";
            cout << "---------------------------------------\n";

            cout << "Enter your choice: ";
            cin >> ch;

            switch (ch) {
                case 1: showVehicles(0); break;
                case 2: showVehicles(1); break;
                case 3: rentVehicle(); break;
                case 4: returnVehicle(); break;
                case 5: cout << "Thank you! Goodbye.\n"; break;
                default: cout << "Invalid choice\n";
            }

        } while (ch != 5);
    }
};

int main() {
    CarRentalSystem s;
    s.menu();
    return 0;
}