#### 14. Modify the `delete_from_list` function (Section 17.5) so that its first parameter has type `struct node **` and its return type is void. `delete_from_list` must modify its first argument to point to the list after the desired node has been deleted.

---

#### Answer:

```c
void delete_from_list(struct node **list, int n) {
    struct node *p = *list;

    while (prev != NULL) {
        if (prev->value == n) {
            *list = prev->next;
            break;
        }
        list = &prev->next;
        prev = prev->next;
    }
}
```
