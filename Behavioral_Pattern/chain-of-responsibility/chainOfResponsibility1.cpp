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
=======================================================================================
Explanation:

Base Class (Handler):
=====================
Defines an interface for handling requests.
Holds a pointer to the next handler (nextHandler) in the chain.

Concrete Handlers:
==================
Each class (e.g., CustomerSupportExecutive, TeamLead, Manager) implements the handleRequest method.
Each handler processes the request it can handle and forwards unhandled requests to the next handler.

Main Function:
===============
Objects are chained together (cse -> lead -> manager).
Requests are passed through the chain until an appropriate handler processes them.
//========================================================================================
virtual void handleRequest(const string& issueType);
why it is virtual??

Ans ==>
1. Without virtual, the method call would be resolved at compile-time based on the static type of the pointer or reference.
2. With virtual, the method call is resolved at runtime based on the actual type of the object the pointer refers to.

Example to Understand:
    Handler* handler = new TeamLead();
    handler->handleRequest("Medium");

Without virtual: The base class's handleRequest is called regardless of the actual object type (TeamLead).
With virtual: The handleRequest implementation of TeamLead is called, as it's the actual type of the object.

If virtual is not used:
The compiler will statically bind the handleRequest call to the base class (Handler) implementation.
===========================================================================================

