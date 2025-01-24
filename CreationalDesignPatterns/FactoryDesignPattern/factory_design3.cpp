#include <iostream>
#include <memory>
using namespace std;
//=======================================================================
// Define an Abstract Class (Creator)
class Document 
{
public:
    virtual void open() = 0;  // Abstract method
    virtual ~Document() {}
};

// Concrete Classes:
class WordDocument : public Document 
{
public:
    void open() override 
    {
        std::cout << "Opening Word Document." << std::endl;
    }
};

class PDFDocument : public Document 
{
public:
    void open() override
    {
        std::cout << "Opening PDF Document." << std::endl;
    }
};

class ExcelDocument : public Document 
{
public:
    void open() override 
    {
        std::cout << "Opening Excel Document." << std::endl;
    }
};
//=====================================================================
// Factory Class:
// Define the Factory Method which will create the Objcet of type Document
class Application 
{
public:
    virtual Document* createDocument() = 0;  // Factory Method
    virtual ~Application() {}
};

// Implement Factory Method in Subclasses (Concrete Creators)
class WordApp : public Application 
{
public:
    Document* createDocument() override 
    {
        return new WordDocument();
    }
};

class PDFApp : public Application 
{
public:
    Document* createDocument() override 
    {
        return new PDFDocument();
    }
};

class ExcelApp : public Application 
{
public:
    Document* createDocument() override 
    {
        return new ExcelDocument();
    }
};

//================================================================
void clientCode(Application* app) 
{
    Document* doc = app->createDocument();  // Factory Method Call
    doc->open();  // Call Product Method
    delete doc;   // Cleanup
}

int main() 
{
    Application* app;

    // Example: Create Word Document
    app = new WordApp();
    clientCode(app);
    delete app;

    // Example: Create PDF Document
    app = new PDFApp();
    clientCode(app);
    delete app;

    return 0;
}

