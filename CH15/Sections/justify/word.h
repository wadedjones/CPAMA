#ifndef WORD_H
#define WORD_H

/* read_word: Reads the next word from input and stores it in word.
 * Makes word empty if no word could be read because of end of file. Truncates
 * word if it's length exceeds len. Returns num of chars stored.
 */

int read_word(char *word, int len);

#endif
