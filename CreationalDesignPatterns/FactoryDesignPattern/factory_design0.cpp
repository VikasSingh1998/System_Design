#include <iostream>
using namespace std;

// Abstract class representing a vehicle
class Vehicle 
{
public:
    virtual void printVehicle() = 0; // Pure virtual function
    virtual ~Vehicle() {}           // Virtual destructor
};

// Concrete class for Two-Wheeler
class TwoWheeler : public Vehicle 
{
public:
    void printVehicle() override 
    {
        cout << "I am two wheeler" << endl;
    }
};

// Concrete class for Four-Wheeler
class FourWheeler : public Vehicle 
{
public:
    void printVehicle() override {
        cout << "I am four wheeler" << endl;
    }
};

// Factory Interface
class VehicleFactory 
{
public:
    virtual Vehicle* createVehicle() = 0; // Factory method
    virtual ~VehicleFactory() {}
};

// Concrete Factory for TwoWheeler
class TwoWheelerFactory : public VehicleFactory 
{
public:
    Vehicle* createVehicle() override 
    {
        return new TwoWheeler();
    }
};

// Concrete Factory for FourWheeler
class FourWheelerFactory : public VehicleFactory 
{
public:
    Vehicle* createVehicle() override 
    {
        return new FourWheeler();
    }
};

int main() 
{
    VehicleFactory* twoWheelerFactory = new TwoWheelerFactory();
    Vehicle* twoWheeler = twoWheelerFactory->createVehicle();
    twoWheeler->printVehicle();

    VehicleFactory* fourWheelerFactory = new FourWheelerFactory();
    Vehicle* fourWheeler = fourWheelerFactory->createVehicle();
    fourWheeler->printVehicle();

    // Clean up memory
    delete twoWheeler;
    delete twoWheelerFactory;
    delete fourWheeler;
    delete fourWheelerFactory;

    return 0;
}

