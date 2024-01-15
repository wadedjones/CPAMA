#### 5. State whether each of the following statements is true or false. Justify each answer.

> (a) Every variable with static storage duration has file scope.  
> (b) Every variable declared inside a function has no linkage.  
> (c) Every variable with internal linkage has static storage duration.  
> (d) Every parameter has block scope.  

---

#### Answer:

> (a) False. Static variables declared inside blocks keep their value, but can't be seen outside the block scope.  
> (b) False. A variable inside a function can be declared as extern.  
> (c) True. If a variable can be accessed by the entire file, it must be static.  
> (d) True.  
