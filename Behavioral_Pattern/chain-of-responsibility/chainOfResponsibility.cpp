Chain Of Responsibility:
--------------------------
1. Chain of Responsibility pattern ek aisa design pattern hai jo request ko uske sender (bhejne wale) 
   aur receiver (lene wale) ke beech loosely couple karta hai. 
2. Is pattern me ek request ko ek se zyada objects ke chain ke through forward kiya jata hai jab tak 
   koi ek object us request ko handle na kar le.

Simple Explanation:
--------------------
==> Jab ek request aati hai, toh usse handle karne ka zimma chain me shamil objects ke paas hota hai.
==> Har object chain me check karta hai ki kya woh us request ko handle kar sakta hai ya nahi. 
    Agar nahi kar sakta, toh woh request agle object ko pass kar deta hai.
==> Ye process tab tak repeat hota hai jab tak koi object us request ko handle na kar le, ya chain ka end na ho jaye.

When To Use Chain of Responsibility:
------------------------------------
1. Jab ek request ko ek se zyada objects handle kar sakte hain aur aap chahte hain ki automatically 
   decide ho ki kaunsa object request ko handle kare.
(E.g., Complaint handling system me different levels of support staff.)

2. Jab aap chahte hain ki request kisi specific object ko explicitly assign na karein.
(E.g., Aap directly nahi batana chahte ki "Manager hi problem solve karega.")

3. Jab aapko dynamically decide karna ho ki kaun kaun request handle kar sakte hain.
(E.g., User permissions ke base par.)

Example:
----------
Sochiye ek customer ke complaints handle karne ka system hai. Agar problem simple hai, 
toh "Customer Support Executive" solve karega. Agar woh solve nahi kar paaye, 
toh request "Team Lead" ko jayegi. 
Agar problem fir bhi solve nahi hui, toh "Manager" tak pahunchegi. 
Yehi Chain of Responsibility ka real-world example hai.
---------------------------------------------------------------------------------------------------
Sender --------> Obj1----> Obj2 --------> Obj3 ------> Receiver
SO when sender will send some request then it will go throuth multiple chains of objects.
















  
