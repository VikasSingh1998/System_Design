Singleton Design Pattern 🚀
📌 Definition
The Singleton Design Pattern ensures that only one instance of a class is created and provides a global point of access to that instance.

🔥 Why Use Singleton?
Restricts multiple object creation → Saves memory.
Ensures global access → All parts of the program share the same instance.
Useful for shared resources → Example: Logger, Database Connection, Configuration Manager.


📌 Key Features
Private Constructor → Prevents external instantiation.
Static Instance Variable → Stores the single instance.
Static getInstance() Method → Controls access to the instance.
