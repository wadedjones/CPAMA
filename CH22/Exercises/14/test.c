#include <stdio.h>
#include <stdlib.h>

char *my_fgets(char *restrict str, int size, FILE *restrict stream);
int my_fputs(const char *str, FILE *stream);

int main(void) {
  FILE *fp;

  if ((fp = fopen("test.txt", "r")) == NULL) {
    printf("failed opening file\n");
    exit(EXIT_FAILURE);
  }

  char str[100];
  my_fgets(str, 100, fp);

  my_fputs(str, stdout);

  return 0;
}

char *my_fgets(char *str, int size, FILE *stream) {
  int ch;
  int i = 0;
  while (i < size - 1) {
    if ((ch = getc(stream)) == EOF) {
      if (i == 0 || ferror(stream)) {
        return NULL;
      }
      break;
    }
    str[i++] = ch;
    if (ch == '\n') {
      break;
    }
  }
  str[i] = '\0';
  return str;
}

int my_fputs(const char *str, FILE *stream) {
  while (*str != '\0') {
    if (putc(*str, stream) == EOF) {
      return EOF;
    }
    str++;
  }
  return 0;
}
