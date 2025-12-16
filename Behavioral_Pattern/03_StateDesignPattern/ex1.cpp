#include <iostream>
using namespace std;

//==============================================================================================
/*
TV --> Context class, jo state ko manage karega.
*/
class TV
{
    
};
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
    //
    virtual void powerPressed(TV* tv) = 0;
    virtual void channelIncreasePressed(TV* tv) = 0;
    virtual void channelDecreasePressed(TV* tv) = 0;
    virtual void soundIncreasePressed(TV* tv) = 0;
    virtual void soundDecreasePressed(TV* tv) = 0;
    
    virtual ~ITVStates()//virtual destructor.
    {}
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
};

//----------------------------------------------------------------------------
class TVOffState : public ITVStates
{};

//----------------------------------------------------------------------------
class TVMuteState : public ITVStates
{};

//======================================================================================================




int main()
{
    std::cout<<"Hello World";

    return 0;
}
