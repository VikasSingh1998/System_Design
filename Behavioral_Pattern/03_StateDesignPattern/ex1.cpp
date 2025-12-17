#include <iostream>
using namespace std;

class TV;
class ITVStates;
class TVOnState;
class TVOffState;
class TVMuteState;
//===============================================================================================
/*
State Pattern ka most Important Rule
-----------------------------------------
--> State --> TV ka condition 
--> ACTION/EVENTS --> buttonPressed, powerPressed, channelIncreasePressed etc these are events.
--> State Interface me hum ACTION/EVENTS rakhte hai.
--> Hr EVENTS/ACTION ke liye hum alag alag function banayege.
--> ITVStates ke jitne bhi concrete class honge(Hr states ke liye hum ek class banayege), wo sab in methods ko implement karenge.

--> TV may have many states ====> ON, OFF, MUTE etc
--> channel +/- or sound increase/decrease ---> ye sab states nhi hota hai. --> these are the behaviours.
--> ITVStates --> isme hum EVENTS/ACTION rakhte hai.
    Ex: powerPressed, channelIncreasePressed, soundIncreasePressed etc.

--> 
Remember:
    State Interface --> sare possible actions.
    Concrete States --> un actions ka behaviours.
*/

class ITVStates //State Interface
{
public:
    //we will write all the ACTION/EVENTS as a function 
    //Each state class will override these functions.
    virtual void powerPressed(TV* tv) = 0;
    virtual void channelIncreasePressed(TV* tv) = 0;
    virtual void channelDecreasePressed(TV* tv) = 0;
    virtual void soundIncreasePressed(TV* tv) = 0;
    virtual void soundDecreasePressed(TV* tv) = 0;
    
    virtual ~ITVStates()//virtual destructor.
    {}
};

//==============================================================================================
/*
TV --> Context class, jo state ko manage karega.
Responsibility:
1. Current state ko hold karna.
2. state ko chage karna.

Q: Why we are passing "this"??
Ans ==> Short answer (1 line 💎) ===> 👉 State ko TV ka control dene ke liye

Q: 🧠 Thoda deep samjho (step-by-step)
1️⃣ TV = Context
2️⃣ State = Behavior + Transition decision

State ka kaam:
--> Sirf print karna ❌
--> Decide karna ki next state kya hoga ✅

🧠 Design Rule (Yaad rakhna)
Context passes itself to the State so that the State can change the Context.

📌 Interview ready answer (Use this verbatim)
We pass this so that the state object can access and modify the context, including changing the current state during a transition.
*/

class TV
{
private:
    ITVStates* currentState;
    
public:
    TV(ITVStates* InitialState)//TV will be created with OFF state initially.
    {
        currentState = InitialState;
    }
    void setState(ITVStates* s)
    {
        currentState = s;
    }
    void powerPressed()
    {
        currentState->powerPressed(this);
    }
    void channelIncreasePressed()
    {
        currentState->channelIncreasePressed(this);
    }
    void channelDecreasePressed()
    {
        currentState->channelDecreasePressed(this);
    }
    void soundIncreasePressed()
    {
        currentState->soundIncreasePressed(this);
    }
    void soundDecreasePressed()
    {
        currentState->soundDecreasePressed(this);
    }
    

};

//==================================================================================================
/*
--> jitne bhi states hai wo sab ITVStates ke methods ko implement karenge.
-------->
Q: Hr state me sare methods kyu jaruri hai???
Ans:
1. Bez remote ka Hur button hr state me press ho sakta hai.
2. Isliye hr state ko decide karna padega ki is ACTION/EVENTS ka kya karna hai.
3. Ex: if TV is on and channelIncreasePressed then increase the channel(send increaseChannel command.)
   Ex: if tv is off and channelIncreasePressed then no need to increase the channel.(just print some log.)
   
4. so different states will haves same methods but each methods behaviours will be different in each states.
5. function same but reaction different ==> this is the soul of the state design Pattern.

-------> 
Q: Kab ITVStates me function add ya remove karna chahiye??
Ans: 
jab koi new EVENTS add ho(remote me new button add hone pr.)

*/
//----------------------------------------------------------------------------
class TVOnState : public ITVStates
{
public:
    //Here each state will override the functions of ITVStates.
    void powerPressed(TV* tv)
    {
        cout<<"TV ON - power button pressed!"<<endl;
        // tv->setState(new TVOffState());
        // Forward declaration is not sufficient when creating objects.
        // A class must be fully defined before using new.
    }
    void channelIncreasePressed(TV* tv)
    {
        cout<<"TV ON - channelIncreasePressed!"<<endl;
    }
    void channelDecreasePressed(TV* tv)
    {
        cout<<"TV ON - channelDecreasePressed!"<<endl;
    }
    void soundIncreasePressed(TV* tv)
    {
        cout<<"TV ON - soundIncreasePressed!"<<endl;
    }
    void soundDecreasePressed(TV* tv)
    {
        cout<<"TV ON - soundDecreasePressed!"<<endl;
    }
};

//----------------------------------------------------------------------------
class TVOffState : public ITVStates
{
public:
    //Here each state will override the functions of ITVStates.
    void powerPressed(TV* tv)
    {
        cout<<"TV OFF - power button pressed!"<<endl;
        tv->setState(new TVOnState());//Here TVOnState class is already defined, so no error.
    }
    void channelIncreasePressed(TV* tv)
    {
        cout<<"TV OFF - channelIncreasePressed!"<<endl;
    }
    void channelDecreasePressed(TV* tv)
    {
        cout<<"TV OFF - channelDecreasePressed!"<<endl;
    }
    void soundIncreasePressed(TV* tv)
    {
        cout<<"TV OFF - soundIncreasePressed!"<<endl;
    }
    void soundDecreasePressed(TV* tv)
    {
        cout<<"TV OFF - soundDecreasePressed!"<<endl;
    }
};

//----------------------------------------------------------------------------
class TVMuteState : public ITVStates
{
public:
    //Here each state will override the functions of ITVStates.
    void powerPressed(TV* tv)
    {
        cout<<"TV MUTE - power button pressed!"<<endl;
    }
    void channelIncreasePressed(TV* tv)
    {
        cout<<"TV MUTE - channelIncreasePressed!"<<endl;
    }
    void channelDecreasePressed(TV* tv)
    {
        cout<<"TV MUTE - channelDecreasePressed!"<<endl;
    }
    void soundIncreasePressed(TV* tv)
    {
        cout<<"TV MUTE - soundIncreasePressed!"<<endl;
    }
    void soundDecreasePressed(TV* tv)
    {
        cout<<"TV MUTE - soundDecreasePressed!"<<endl;
    }
};

//======================================================================================================
int main()
{
    std::cout<<"Hello World"<<endl;
    //Create on TV with initial OFF state.
    TV tv(new TVOffState());
    tv.powerPressed();
    tv.powerPressed();
    tv.powerPressed();

    return 0;
}
/*
main.cpp: In member function ‘virtual void TVOnState::powerPressed(TV*)’:
main.cpp:136:37: error: invalid use of incomplete type ‘class TVOffState’
  136 |         tv->setState(new TVOffState());
      |                                     ^
main.cpp:7:7: note: forward declaration of ‘class TVOffState’
    7 | class TVOffState;
    
----------------------------------------------------------------
After adding comment:

// tv->setState(new TVOffState());
// Forward declaration is not sufficient when creating objects.
// A class must be fully defined before using new.
----------------------------------------------------------------
Hello World
TV OFF - power button pressed!
TV ON - power button pressed!
TV ON - power button pressed!
*/
