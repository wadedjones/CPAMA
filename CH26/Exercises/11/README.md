#### 11. Although the `bsearch` function is normally used with a sorted array, it will sometimes work correctly with an array that is only partially sorted. What condition must an array satisfy to guarantee that `bsearch` works properly for a particular key? Hint: The answer appears in the C standard.

---

#### Answer: As long as one half of the array containing the key is correctly sorted, the `bsearch` function should work correctly.
