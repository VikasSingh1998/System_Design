#include <iostream>
#include <memory>
using namespace std;

//===============================================================
// ==> There will be one abstract class "Vechicle", which will be base class.
// ==> Now it will have child class, which will be Concrete class.
//---------------------------------------------------------------
// 1. Product Interface
// Abstract class representing a vehicle
class Vehicle 
{
public:
    virtual void printVehicle() = 0; // Pure virtual function
    virtual ~Vehicle() {}           // Virtual destructor
};

// 2. Concrete Products
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
//---------------------------------------------------------------
// ==> Now there will be one Interface "VehicleFactory" which will create the Vehicle.
// Factory Interface
class VehicleFactory 
{
public:
    //This method will return the pointer of type Vehicle.
    virtual unique_ptr<Vehicle> createVehicle() = 0; // Factory method
    virtual ~VehicleFactory() {}
};

// Concrete Factory for TwoWheeler
class TwoWheelerFactory : public VehicleFactory 
{
public:
    unique_ptr<Vehicle> createVehicle() override 
    {
        //make_unique is a modern way to create "unique_ptr" objects
        return make_unique<TwoWheeler>();
    }
};

// Concrete Factory for FourWheeler
class FourWheelerFactory : public VehicleFactory 
{
public:
    unique_ptr<Vehicle> createVehicle() override 
    {
        return make_unique<FourWheeler>();
    }
};

// Client class
class Client 
{
private:
    unique_ptr<Vehicle> pVehicle;

public:
    Client(unique_ptr<VehicleFactory> factory) 
    {
        pVehicle = factory->createVehicle(); // Delegates creation to the factory
    }

    Vehicle* getVehicle() 
    {
        return pVehicle.get(); // Returns a raw pointer to the vehicle
    }
};

// Driver function
int main() 
{
    unique_ptr<VehicleFactory> twoWheelerFactory = make_unique<TwoWheelerFactory>();
    Client twoWheelerClient(move(twoWheelerFactory));
    Vehicle* twoWheeler = twoWheelerClient.getVehicle();
    twoWheeler->printVehicle();

    unique_ptr<VehicleFactory> fourWheelerFactory = make_unique<FourWheelerFactory>();
    Client fourWheelerClient(move(fourWheelerFactory));
    Vehicle* fourWheeler = fourWheelerClient.getVehicle();
    fourWheeler->printVehicle();

    return 0;
}
/* ========================================================================================
                     Vehicle(Abstract Classs)                      Factory(Interface)
                    /       \                                           /       \
                  /           \                                        /         \
    2WheelerVehicle       4wheelerVehicle                   2wheelerFactory       4WheelerFactory



2WheelerFactory creates the 2 Wheeler Vehicles.
4WheelerFactory creates the 4 wheeler Vehicles.

*/


                       
