#### Suppose that the `direction` variable is declared in the following way:

```c
enum {NORTH, SOUTH, EAST, WEST} direction;
```

#### Let `x` and `y` be `int` variables. Write a `switch` statement that tests the value of `direction`, incrementing `x` if `direction` is `EAST`, decrementing `x` if the `direction` is `WEST`, incrementing `y` if the `direction` is `SOUTH`, and decrementing `y` if the `direction` is `NORTH`.

---

#### Answer:

```c
int x, y;

switch (direction) {
    case NORTH:
        y--;
        break;
    case SOUTH:
        y++;
        break;
    case EAST:
        x++;
        break;
    case WEST:
        x--;
        break;
    default:
        break;
}
```
