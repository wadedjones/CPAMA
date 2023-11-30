/* Modify PP 11 from chapter 5 so that it uses arrays containing pointers to
 * strings instead of switch statements. For example, instead of using a switch
 * statement to print the word for the first digit, use the digit as an index
 * into an array that contains the strings "twenty", "thirty", and so forth. */

#include <stdio.h>

int main(void) {
  char *numbers_prefix[] = {"twenty", "thirty",  "forty",  "fifty",
                            "sixty",  "seventy", "eighty", "ninety"};
  char *numbers_postfix[] = {"",        "one",       "two",      "three",
                             "four",    "five",      "six",      "seven",
                             "eight",   "nine",      "ten",      "eleven",
                             "twelve",  "thirteen",  "fourteen", "fifteen",
                             "sixteen", "seventeen", "eighteen", "nineteen"};

  int prefix, postfix;

  printf("Enter a two digit number: ");
  scanf("%1d%1d", &prefix, &postfix);

  if (prefix == 1) {
    printf("%s\n", numbers_postfix[postfix + 10]);
  } else {
    printf("%s %s\n", numbers_prefix[prefix - 2], numbers_postfix[postfix]);
  }

  return 0;
}
