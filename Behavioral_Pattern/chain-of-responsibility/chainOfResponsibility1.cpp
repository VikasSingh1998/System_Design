#include <iostream>
#include <string>
using namespace std;

// Base class for all handlers
class Handler 
{
protected:
    Handler* nextHandler; // Pointer to the next handler in the chain

public:
    Handler()
    {
        nextHandler = nullptr;
    }
    virtual ~Handler()
    {
        // Jab base class ka pointer use karke child class ka object delete kiya jata hai, 
        // tabhi virtual destructor ki zarurat hoti hai. 
        // Agar destructor virtual nahi hoga, to sirf base class ka destructor chalega, 
        // aur child class ka destructor call nahi hoga. 
        // Isse resource leaks ya incomplete cleanup hone ka risk hota hai.
        //----------------------------
        // Key Concept:
        //----------------------------
        // Base class pointer ka use child class ka object handle karne ke liye hota hai (polymorphism ke wajah se).
        // Agar destructor virtual hai, to:
        // Delete karte waqt pehle child class ka destructor chalega.
        // Phir base class ka destructor chalega.
        // Agar destructor virtual nahi hai, to sirf base class ka destructor chalega, chahe object kis bhi derived class ka ho.
    }

    void setNextHandler(Handler* handler) 
    {
        nextHandler = handler;
    }

    virtual void handleRequest(const string& issueType)
    {
        if (nextHandler) 
        {
            nextHandler->handleRequest(issueType); // Pass the request to the next handler
        } 
        else
        {
            cout << "No one available to handle this issue.\n";
        }
    }
};

// Concrete Handler 1: Customer Support Executive
class CustomerSupportExecutive : public Handler 
{
public:
    void handleRequest(const string& issueType) override 
    {
        if (issueType == "Low") 
        {
            cout << "Customer Support Executive handled the low-level issue.\n";
        } 
        else if (nextHandler) 
        {
            cout << "Customer Support Executive is passing to nextHandler.\n";
            nextHandler->handleRequest(issueType); // Pass to next handler
        }
    }
};

// Concrete Handler 2: Team Lead
class TeamLead : public Handler 
{
public:
    void handleRequest(const string& issueType) override 
    {
        if (issueType == "Medium") 
        {
            cout << "Team Lead handled the medium-level issue.\n";
        } 
        else if (nextHandler) 
        {
            cout << "Team Lead is passing to nextHandler.\n";
            nextHandler->handleRequest(issueType); // Pass to next handler
        }
    }
};

// Concrete Handler 3: Manager
class Manager : public Handler 
{
public:
    void handleRequest(const string& issueType) override 
    {
        if (issueType == "High") 
        {
            cout << "Manager handled the high-level issue.\n";
        } 
        else if (nextHandler) 
        {
            cout << "Manager is passing to nextHandler.\n";
            nextHandler->handleRequest(issueType); // Pass to next handler
        }
        else
        {
            cout << "Manager is calling the base class Handler\n";
            Handler::handleRequest(issueType); // Call base class for default message
        }
    }
};

int main() 
{
    // Create handlers
    CustomerSupportExecutive cse;
    TeamLead lead;
    Manager manager;

    // Set up the chain
    cse.setNextHandler(&lead);
    lead.setNextHandler(&manager);

    // Example requests
    // cout << "Request: Low-level issue\n";
    // cse.handleRequest("Low");

    // cout << "\nRequest: Medium-level issue\n";
    // cse.handleRequest("Medium");

    // cout << "\nRequest: High-level issue\n";
    // cse.handleRequest("High");

    // cout << "\nRequest: Unknown issue type\n";
    cse.handleRequest("Unknown");

    return 0;
}

