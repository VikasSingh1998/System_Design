#include <iostream>
using namespace std;

class Singleton 
{
private:
    static Singleton* instance; // Static instance variable
    Singleton() 
    { 
        cout << "Singleton Instance Created" << endl; 
    }

public:
    // Delete copy constructor and assignment operator to prevent duplication
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance()  // Static method
    {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() 
    {
        cout << "Hello from Singleton!" << endl;
    }
};

// Initialize static instance pointer
Singleton* Singleton::instance = nullptr;

/*
Correct way to initialize a static member:
================================================
1. Static members belong to the class, not to objects.
==> They must be defined outside the class before they can be used.

2. Singleton::instance = nullptr; (without Singleton*) is incorrect syntax
==> Because the compiler expects the type of instance during definition.
*/

int main() 
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    
    if (s1 == s2)
    {
        cout << "Both instances are the same." << endl;
    }
    else
    {
        cout << "Both instances are NOT same." << endl;
    }

    return 0;
}
/*
Why Use static?
==> To Ensure Only One Instance Exists
      static Singleton* instance; → This makes instance belong to the class, not to any object.
      This ensures only one instance of Singleton is shared across the program.

==> To Allow Access Without an Object
The function getInstance() is static, so we can call it as:
      Singleton* s1 = Singleton::getInstance();

      
Without static, we would need an object first, but the Singleton should control its own instance creation.
*/
