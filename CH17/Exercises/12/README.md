#### 12. Write the following function:

```c
struct node *find_last(struct node *list, int n);
```

#### The `list` paramter points to a linked list. The function should return a pointer to the last node that containes `n`; it should return NULL if `n` deosn't appear in the list. Assume that the `node` structure is the one defined in Section 17.5.

---

#### Answer:

```c
struct node *find_last(struct node *list, int n) {
    struct node *temp = NULL;

    while (list != NULL) {
        if (list->value == n) {
            temp = list;
        }
        list = list->next;
    }
    return temp;
}
```
