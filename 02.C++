#include <iostream>
#include <string>
using namespace std;

// Base class Vehicle is designed to be abstract and serve as a blueprint for all types of vehicles.
class Vehicle {
protected:
    // Protected members allow derived classes like Truck and Bus to access these directly.
    // If these were private, only the Vehicle class itself could access them.
    // Protected strikes a balance: it keeps data hidden from external code,
    // but accessible to subclasses that need to display or use them.
    string Vehicle_Model;
    string Registration_Number;
    int Vehicle_Speed;
    double Fuel_Capacity;
    double Fuel_Consumption;

public:
    // Constructor to initialize common vehicle attributes.
    Vehicle(string Vehicle_Model, string Registration_Number, int Vehicle_Speed, double Fuel_Capacity, double Fuel_Consumption)
    {
        // The 'this->' keyword is used to distinguish between the parameter and the class member.
        this->Vehicle_Model = Vehicle_Model;
        this->Registration_Number = Registration_Number;
        this->Vehicle_Speed = Vehicle_Speed;
        this->Fuel_Capacity = Fuel_Capacity;
        this->Fuel_Consumption = Fuel_Consumption;
    }

    // Pure virtual function makes this class abstract.
    // Forces all derived classes to implement the Display method in their own way.
    virtual void Display() = 0;
};

// Derived class Truck inherits from Vehicle.
class Truck : public Vehicle {
private:
    // A truck-specific data member, could represent payload, axle count, etc.
    int Data_Member;

public:
    // Constructor uses initializer list to call the base class constructor.
    Truck(string Vehicle_Model, string Registration_Number, int Vehicle_Speed, double Fuel_Capacity, double Fuel_Consumption, int Data_Member)
        : Vehicle(Vehicle_Model, Registration_Number, Vehicle_Speed, Fuel_Capacity, Fuel_Consumption), Data_Member(Data_Member) {}

    // Setter for the truck-specific data.
    void setData_Member(int Data_Member)
    {
        this->Data_Member = Data_Member;
    }

    // Getter for the truck-specific data.
    int getData_Member()
    {
        return Data_Member;
    }

    // Overrides the pure virtual function from Vehicle to provide specific output for trucks.
    void Display() override
    {
        // Direct access to protected members from the base class
        // This is only possible because they are 'protected', not 'private'
        cout << "Vehicle Model: " << Vehicle_Model << endl;
        cout << "Registration Number: " << Registration_Number << endl;
        cout << "Vehicle Speed: " << Vehicle_Speed << " km/h" << endl;
        cout << "Fuel Capacity: " << Fuel_Capacity << " liters" << endl;
        cout << "Fuel Consumption: " << Fuel_Consumption << " l/100km" << endl;
        cout << "Data Member of truck: " << getData_Member() << " Kg" << endl;
    }
};

// Derived class Bus inherits from Vehicle.
class Bus : public Vehicle {
private:
    // Bus-specific data member representing number of passengers.
    int No_Passangers;

public:
    // Constructor to initialize both base and derived members.
    Bus(string Vehicle_Model, string Registration_Number, int Vehicle_Speed, double Fuel_Capacity, double Fuel_Consumption, int No_Passangers)
        : Vehicle(Vehicle_Model, Registration_Number, Vehicle_Speed, Fuel_Capacity, Fuel_Consumption), No_Passangers(No_Passangers) {}

    // Setter for passengers.
    void setNo_Passangers(int No_Passangers)
    {
        this->No_Passangers = No_Passangers;
    }

    // Getter for passengers.
    int getNo_Passangers()
    {
        return No_Passangers;
    }

    // Overrides the base class method to show bus-specific details.
    void Display() override
    {
        // Again, protected access allows us to display inherited members
        cout << "Vehicle Model: " << Vehicle_Model << endl;
        cout << "Registration Number: " << Registration_Number << endl;
        cout << "Vehicle Speed: " << Vehicle_Speed << " km/h" << endl;
        cout << "Fuel Capacity: " << Fuel_Capacity << " liters" << endl;
        cout << "Fuel Consumption: " << Fuel_Consumption << " l/100km" << endl;
        cout << "Passengers of bus: " << getNo_Passangers() << " Persons" << endl;
    }
};

int main() {
    // Demonstrating polymorphism: the base class pointer holds derived class object
    Vehicle* v1 = new Truck("Volvo", "TR123", 90, 500, 30, 777);
    v1->Display(); // Calls Truck's Display()
    delete v1;     // Always delete heap-allocated objects to avoid memory leaks

    cout << endl;

    Vehicle* v2 = new Bus("Mercedes", "BS456", 80, 300, 25, 45);
    v2->Display(); // Calls Bus's Display()
    delete v2;

    return 0;
}
