#include <iostream>
#include <memory>
using namespace std;

//=======================================================================
// Vehicle Interface (Abstract Class):
// Ek interface ya abstract class banate hain jo saare vehicles ke liye common methods define karega.
class Vehicle 
{
public:
    virtual void displayType() = 0; // Pure virtual function
    virtual ~Vehicle() {} // Virtual destructor
};

// Concrete Classes:
// Ab aap alag-alag classes implement karte ho jo Vehicle interface ko extend karti hain.
class Car : public Vehicle 
{
public:
    void displayType() override 
    {
        std::cout << "This is a Car." << std::endl;
    }
};

class Bike : public Vehicle 
{
public:
    void displayType() override 
    {
        std::cout << "This is a Bike." << std::endl;
    }
};

class Truck : public Vehicle 
{
public:
    void displayType() override 
    {
        std::cout << "This is a Truck." << std::endl;
    }
};
//=====================================================================
// Factory Class:
// Ek factory class banate hain jo user input ke hisaab se object create karega.

class VehicleFactory 
{
public:
    static Vehicle* createVehicle(const std::string& type) 
    {
        if (type == "Car") 
        {
            return new Car();
        } 
        else if (type == "Bike") 
        {
            return new Bike();
        } 
        else if (type == "Truck") 
        {
            return new Truck();
        } 
        else 
        {
            return nullptr; // Agar type match nahi karta
        }
    }
};
//================================================================
// Client Code:
// Factory ke through objects create karte hain aur unka use karte hain.

int main() 
{
    std::string input;
    std::cout << "Enter vehicle type (Car, Bike, Truck): ";
    std::cin >> input;

    Vehicle* vehicle = VehicleFactory::createVehicle(input);

    if (vehicle) 
    {
        vehicle->displayType();
        delete vehicle; // Memory cleanup
    } 
    else 
    {
        std::cout << "Invalid vehicle type!" << std::endl;
    }

    return 0;
}

/*
Output:
Input: Car
Output: This is a Car.

Input: Bike
Output: This is a Bike.

Input: Truck
Output: This is a Truck.

Input: Plane
Output: Invalid vehicle type!
*/

