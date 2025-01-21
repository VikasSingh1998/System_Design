import java.util.*;

// Base class for all handlers
abstract class Handler 
{
    protected Handler nextHandler; // Pointer to the next handler in the chain

    public Handler() 
    {
        nextHandler = null;
    }

    // Set the next handler in the chain
    public void setNextHandler(Handler handler) 
    {
        this.nextHandler = handler;
    }

    // Handle request method (virtual in C++)
    public void handleRequest(String issueType) 
    {
        if (nextHandler != null) 
        {
            nextHandler.handleRequest(issueType); // Pass the request to the next handler
        } 
        else 
        {
            System.out.println("No one available to handle this issue.");
        }
    }
}

// Concrete Handler 1: Customer Support Executive
class CustomerSupportExecutive extends Handler 
{
    @Override
    public void handleRequest(String issueType) 
    {
        if (issueType.equals("Low")) 
        {
            System.out.println("Customer Support Executive handled the low-level issue.");
        } 
        else if (nextHandler != null) 
        {
            System.out.println("Customer Support Executive is passing to nextHandler.");
            nextHandler.handleRequest(issueType); // Pass to next handler
        }
    }
}

// Concrete Handler 2: Team Lead
class TeamLead extends Handler 
{
    @Override
    public void handleRequest(String issueType) 
    {
        if (issueType.equals("Medium")) 
        {
            System.out.println("Team Lead handled the medium-level issue.");
        } 
        else if (nextHandler != null) 
        {
            System.out.println("Team Lead is passing to nextHandler.");
            nextHandler.handleRequest(issueType); // Pass to next handler
        }
    }
}

// Concrete Handler 3: Manager
class Manager extends Handler 
{
    @Override
    public void handleRequest(String issueType) 
    {
        if (issueType.equals("High")) 
        {
            System.out.println("Manager handled the high-level issue.");
        } 
        else if (nextHandler != null) 
        {
            System.out.println("Manager is passing to nextHandler.");
            nextHandler.handleRequest(issueType); // Pass to next handler
        } 
        else 
        {
            System.out.println("Manager is calling the base class Handler.");
            super.handleRequest(issueType); // Call base class for default message
        }
    }
}

// Main class to test the chain
public class Main 
{
    public static void main(String[] args) 
    {
        // Create handlers
        CustomerSupportExecutive cse = new CustomerSupportExecutive();
        TeamLead lead = new TeamLead();
        Manager manager = new Manager();

        // Set up the chain
        cse.setNextHandler(lead);
        lead.setNextHandler(manager);

        // Example requests
        // System.out.println("Request: Low-level issue");
        // cse.handleRequest("Low");

        // System.out.println("\nRequest: Medium-level issue");
        // cse.handleRequest("Medium");

        // System.out.println("\nRequest: High-level issue");
        // cse.handleRequest("High");

        System.out.println("\nRequest: Unknown issue type");
        cse.handleRequest("Unknown");
    }
}
