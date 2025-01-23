Command Design Pattern
========================
Command Pattern ek aisa design pattern hai jo ek request ko ek object ke andar wrap karta hai. 
Simple shabdon mein, agar humein kisi action ko perform karna ho, toh hum us action ko 
ek object ke form mein represent karte hain. 
Is pattern ka fayda ye hai ki hum apne code ko zyada flexible aur reusable bana sakte hain. 
---------------------------------------------------------------
Yeh pattern alag-alag scenarios mein useful hota hai:

Kab Use Karein?
Action ko parameterize karna (Parameterize objects by actions):
Agar humein alag-alag actions perform karne hain, toh hum har action ko ek object ke form mein wrap kar sakte hain aur clients ke saath share kar sakte hain. Example: Light on/off commands alag objects honge.

Requests ko queue ya log karna (Queue or log requests):
Agar humein multiple requests ko ek sequence mein execute karna ho ya future mein repeat karna ho, toh un requests ko queue mein rakh sakte hain ya log kar sakte hain.

Undo operations support karna:
Agar koi galat operation perform ho gaya, toh usko undo karne ka feature milta hai. Example: Agar user ne "delete" kiya, toh undo karke wapas laa sakte hain.

Changes ko log karna (Logging changes):
Agar system crash ho jaye, toh hum logged changes ke basis par system ko restore kar sakte hain.

High-level operations ko structure karna:
Complex systems ko simple operations ke upar build karna easy ho jata hai. Primitive operations ko wrap karke high-level functionality banai ja sakti hai.

Simple Fayde:
Flexibility: Requests ko dynamic tarike se handle kar sakte hain.
Reusability: Alag-alag commands ko re-use karna easy hota hai.
History Maintain karna: Hum requests ki history track kar ke unhe dubara execute kar sakte hain ya undo kar sakte hain.
Ek Example Samajhiye:
Maan lijiye, aapke paas ek Remote Control hai jo Light aur Fan ko control karta hai. Light ko on/off karna aur Fan ko on/off karna alag-alag actions hain. Hum har action ko ek Command object ke andar wrap karte hain, aur remote control ke through unhe execute karte hain. Undo ka bhi support rahega.

Yeh pattern aise scenarios ke liye perfect hai jahan multiple operations ko dynamic tarike se manage karna ho aur system flexible aur robust banana ho.










