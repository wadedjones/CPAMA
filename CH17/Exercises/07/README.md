#### 7. The following loop is supposed to delete all nodes from a linked list and release the memory that they occupy. Unfortunately, the loop is incorrect. Explain what's wrong with it and show how to fix the bug.  

```c
for (p = first; p != NULL; p = p->next) {
    free(p);
}
```

---

#### Answer: Freeing `p` inside the loop body will cause the list `first` to be freed, severing the connection to the next node.  

```c
while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
}
```
