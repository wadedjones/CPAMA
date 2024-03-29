#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: date mm/dd/yyyy or mm-dd-yyyy\n");
    exit(EXIT_FAILURE);
  }
  int month, day, year;

  char *month_str[12] = {"January",   "February", "March",    "April",
                         "May",       "June",     "July",     "August",
                         "September", "October",  "November", "December"};

  char *str = argv[1];

  if (sscanf(str, "%d%*[-/]%d%*[-/]%d", &month, &day, &year) == 3) {
    printf("%s %d, %d\n", month_str[month - 1], day, year);
  }

  return 0;
}
