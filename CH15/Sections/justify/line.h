#ifndef LINE_H
#define LINE_H

/* clear_line: Clears current line. */

void clear_line(void);

/* add_word: Adds word to the end of the current line. If not the first
 * word in the line, adds a space before the word. */

void add_word(const char *word);

/* space_remaining: Returns the number of chars left in current line. */

int space_remaining(void);

/* write_line: Writes the current line with justification. */

void write_line(void);

/* flush_line: Writes the current line without justification. If the
 * line is empty, it does nothing. */

void flush_line(void);

#endif
