#### 19. Declare a structure with the following members whose tag is `pinball_machine`:
> `name` - a string of up to 40 characters  
> `year` - an integer (representing year of manufacturer)  
> `type` - an enumeration with the values `EM` and `SS` (electromechanical and solid state)  
> `players` - an integer (representing the max number of players)  

---

#### Answer:

```c
struct pinball_machine {
    char name[40];
    int year;
    enum {
        EM, SS
    } type;
    int players;
}
```
