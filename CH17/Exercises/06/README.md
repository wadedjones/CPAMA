#### 6. Modify the `delete_from_list` function so that it uses only one pointer variable instead of two (`cur` and `prev`).  

---

#### Answer:

```c
void delete_from_list(struct node **list, int n) {
  struct node *prev = *list;

  while (prev) {
    if (prev->value == n) {
      *list = prev->next;
      break;
    }
    list = &prev->next;
    prev = prev->next;
  }
}
```
