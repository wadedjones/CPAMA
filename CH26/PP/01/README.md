#### 1. (a) Write a program that calls the `rand` function 1000 times, printing the low-order bit of each value it returns (0 if the return value is even, 1 if it's odd). Do you see any patterns? (Often, the last few bits of `rand`'s return value aren't especially random.)

#### (b) How can we improve the randomness of rand for generating numbers within a small range?

---

#### Answer: (a) see `random.c`.

#### (b) For generating numbers in the range 0 to N - 1, the formula rand() / (RAND_MAX / N + 1) often gives better results than rand() % N. For example, if N is 2 and RAND_MAX is 32767, the formula works out to rand() / 16384, which yields 0 if the return value of rand is less than 16384 and 1 if it's greater than or equal to 16384. 
