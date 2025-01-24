Factory Design Pattern
========================
Factory Design Pattern ek Creational Design Pattern hai 
jo object creation ka responsibility factory method ko deta hai, 
taaki client ko exact class ke baare mein pata na ho. 
  
Is pattern mein client sirf interface ya base class ke saath interact karta hai, 
aur object creation ka logic factory par delegate hota hai. 
  
Ye Open/Closed Principle ko follow karta hai aur flexibility provide karta hai, 
jisme naye object types add karna easy hota hai bina existing code ko modify kiye. 
Iska use tab hota hai jab object creation complex ho ya client ko specific class se independent rakhna ho.
-------------------------------------------------------------------------------------
Important Points for Interviews
------------------------------------
==> Factory Pattern ka kaam object creation ko simplify karna hai bina client ko concrete class ke baare me bataye.
==> Ye pattern Open/Closed Principle ko follow karta hai (aap naye features add kar sakte ho bina existing code ko todhe).
==> Ye tab useful hai jab alag-alag types ke products ko frequently add karna ho.
======================================================================================
Key Differences with Abstract Factory
----------------------------------------
Factory Method: Sirf ek product type ke liye method provide karta hai.
Abstract Factory: Multiple related products ke liye factory methods provide karta hai.
