#### 13. The following function is supposed to insert a new node into its proper place in an ordered list, returning a pointer to the first node in the modified list. Unfortunatedly, the function doesn't work correctly in all cases. Explain what's wrong with it and show how to fix it. Assume that the `node` structure is the one defined in Section 17.5.

```c
struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {
    struct node *cur = list, *prev = NULL;
    while (cur->value <= new_node->value) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = new_node;
    new_node->next = cur;
    return list;
}
```

---

#### Answer:

```c
struct node *insert_into_ordered_list(struct node *list,
                                      struct node *new_node) {
  struct node *cur = list, *prev = NULL;
  if (cur == NULL) {
    return new_node;
  }
  while (cur->value <= new_node->value) {
    if (cur->next == NULL) {
      cur->next = new_node;
      return list;
    }
    prev = cur;
    cur = cur->next;
  }
  if (prev == NULL) {
    new_node->next = cur;
    return new_node;
  }
  prev->next = new_node;
  new_node->next = cur;
  return list;
}
```
