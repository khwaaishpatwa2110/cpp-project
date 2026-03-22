# 🚗 Car Rental System — C++ OOP Project

A console-based Car Rental System built in C++ demonstrating core Object-Oriented Programming concepts: **Encapsulation**, **Inheritance**, and **Polymorphism**.

---

## 📌 1. Introduction

The **Car Rental System** is a menu-driven console application developed in C++ that simulates a basic car rental service. It allows users to:

- View all cars in the system
- View only available cars
- Rent a car by providing customer details
- Return a rented car
- Generate a billing receipt after renting

The project is built using OOP principles in C++, making the code structured, modular, and easy to understand.

---

## 🎯 2. Objectives of the Project

- Apply core C++ OOP concepts — Encapsulation, Inheritance, and Polymorphism — in a real-world scenario
- Implement a **base class `Vehicle`** with a derived class `Car` using Inheritance
- Demonstrate **Polymorphism** through function overriding (`displayInfo()`)
- Use **Encapsulation** to bundle data and behavior within classes
- Build a clean, interactive console menu system
- Practice dynamic memory allocation using pointers and arrays

---

## 🛠️ 3. Methodology / System Design

### Class Structure

```
Vehicle          (Base Class — stores common car properties)
└── Car          (Derived Class — adds seating capacity)

Customer         (Stores customer details)
Rental           (Links Customer + Vehicle, generates receipt)
CarRentalSystem  (Main controller — manages cars, rentals, menu)
```

### OOP Concepts Used

| Concept | How It Is Applied |
|---|---|
| **Encapsulation** | Data and functions are bundled together inside classes (`Vehicle`, `Customer`, `Rental`) |
| **Inheritance** | `Car` inherits from `Vehicle`, reusing common properties like `id`, `brand`, `model`, `ratePerDay` |
| **Polymorphism** | `displayInfo()` is defined in `Vehicle` and overridden in `Car` to show car-specific details |
| **Abstraction** | User interacts only through the `CarRentalSystem` menu; internal logic is hidden |

### System Flow

```
Start
  └── Initialize 5 default cars
        └── Show Menu
              ├── 1. View All Cars
              ├── 2. View Available Cars
              ├── 3. Rent a Car → Enter details → Generate Receipt
              ├── 4. Return a Car → Mark as available
              └── 5. Exit
```

### Default Cars Loaded

| ID | Brand | Model | Rate/Day | Seats |
|---|---|---|---|---|
| 1 | Hyundai | Creta | Rs.3000 | 5 |
| 2 | Kia | Seltos | Rs.3200 | 5 |
| 3 | BMW | X5 | Rs.6000 | 5 |
| 4 | Toyota | Fortuner | Rs.5000 | 7 |
| 5 | Audi | A6 | Rs.7000 | 5 |

---

## 💻 4. Implementation / Source Code

### How to Compile and Run

**Requirements:** Any C++11 compatible compiler (g++, MSVC, Clang)

```bash
# Compile
g++ -o car_rental car_rental_system.cpp

# Run (Linux/Mac)
./car_rental

# Run (Windows)
car_rental.exe
```

### Key Classes Overview

#### `Vehicle` — Base Class
```cpp
class Vehicle {
public:
    int id;
    string brand, model;
    float ratePerDay;
    int isAvailable;   // 1 = available, 0 = rented

    void displayInfo();
};
```

#### `Car` — Derived from Vehicle
```cpp
class Car : public Vehicle {
public:
    int seats;

    void displayInfo();  // overrides Vehicle::displayInfo()
};
```

#### `Customer` — Stores Rental Customer Info
```cpp
class Customer {
public:
    int id;
    string name, contact;

    void display();
};
```

#### `Rental` — Manages Billing
```cpp
class Rental {
    static int count;    // auto-increments rental ID
    Customer customer;
    Vehicle* vehicle;
    int days;
    float total;         // total = ratePerDay * days
public:
    void receipt();
};
```

#### `CarRentalSystem` — Main Controller
```cpp
class CarRentalSystem {
    Vehicle* v[5];       // stores 5 cars
    Rental* rentals[10]; // stores up to 10 rentals
public:
    void showVehicles(int onlyAvailable);
    void rentVehicle();
    void returnVehicle();
    void menu();
};
```

### Sample Output

```
========== CAR RENTAL SYSTEM ==========
1. View All Cars
2. View Available Cars
3. Rent a Car
4. Return a Car
5. Exit
---------------------------------------
Enter your choice: 3

----- CAR LIST -----

[CAR]
ID: 1
Brand: Hyundai
Model: Creta
Rate: Rs.3000/day
Status: Available
Seats: 5

Enter Car ID: 1
Enter your name: Khwaaish
Enter contact: 9876543210
Enter days: 2

----- RECEIPT -----
Rental ID: 1
Customer ID: 1
Name: Khwaaish
Contact: 9876543210
Vehicle: Hyundai Creta
Days: 2
Total: Rs.6000
```

---

## ✅ 5. Conclusion

The **Car Rental System** successfully demonstrates all major Object-Oriented Programming concepts in C++:

- **Encapsulation** bundles data and functions together inside each class
- **Inheritance** allows `Car` to reuse properties and behavior from the `Vehicle` base class
- **Polymorphism** enables `displayInfo()` to show car-specific details by overriding the base class function
- **Abstraction** keeps the menu interface simple while hiding internal logic from the user

This project serves as a strong foundation that can be extended further with file storage, database integration, or a graphical user interface (GUI).

---

## 👤 Author

**Khwaaish**  
C++ OOP Project — Submitted: 31 March 2026

---

## 📁 Repository Structure

```
car-rental-system/
├── car_rental_system.cpp   ← Main source code
└── README.md               ← Project documentation
```
