#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 3) {
    fprintf(stderr, "usage: win_to_unix <filename1> <filename2>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp_in, *fp_out;

  if ((fp_in = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "cannot open file: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((fp_out = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "cannot save file: %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }

  int ch;

  while ((ch = fgetc(fp_in)) != EOF) {
    if (ch != '\x0d' && ch != '\x1a') {
      fputc(ch, fp_out);
    }
  }

  fclose(fp_in);
  fclose(fp_out);

  return 0;
}
