#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int line_length(const char *filename, int n);

int main(void) {
  char *filename = "test.txt";

  int n = line_length(filename, 11);

  printf("Line Length: %d\n", n);

  return 0;
}

int line_length(const char *filename, int n) {
  FILE *fp;
  char buf[100];

  if ((fp = fopen(filename, "r")) == NULL) {
    printf("Error opening %s\n", filename);
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if ((fgets(buf, 100, fp)) == NULL) {
      return 0;
    }
    buf[strcspn(buf, "\n")] = 0;
  }

  fclose(fp);

  return strlen(buf);
}
