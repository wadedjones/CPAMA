#ifndef LINE_H
#define LINE_H

#include <stdio.h>

#define MAX_LINE_LEN 60
/* clear_line: Clears current line. */

void clear_line(char line[MAX_LINE_LEN + 1]);

/* add_word: Adds word to the end of the current line. If not the first
 * word in the line, adds a space before the word. */

void add_word(const char *word, char line[MAX_LINE_LEN + 1]);

/* space_remaining: Returns the number of chars left in current line. */

int space_remaining(void);

/* write_line: Writes the current line with justification. */

void write_line(FILE *fp, char line[MAX_LINE_LEN + 1]);

/* flush_line: Writes the current line without justification. If the
 * line is empty, it does nothing. */

void flush_line(FILE *fp, char line[MAX_LINE_LEN + 1]);

#endif
