/* Copies a file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512

int main(int argc, char **argv) {
  FILE *source_fp, *dest_fp;
  char buf[BUFSIZE] = {0};
  int num_read;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if ((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }

  while ((num_read = fread(buf, sizeof(char), BUFSIZE, source_fp)) > 0) {
    fwrite(buf, sizeof(char), num_read, dest_fp);
  }

  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}
