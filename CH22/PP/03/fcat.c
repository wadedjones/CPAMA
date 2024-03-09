#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024

int main(int argc, char **argv) {

  if (argc < 2) {
    fprintf(stderr, "Usage: fcat <filename1> <filename2> ...");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  int num_files = 1;

  while (num_files < argc) {
    if ((fp = fopen(argv[num_files], "r")) == NULL) {
      fprintf(stderr, "Cannot open file %s\n", argv[num_files]);
    } else {
      char str[BUF];
      while ((fgets(str, BUF, fp)) != NULL) {
        str[strcspn(str, "\n")] = 0;
        puts(str);
      }
    }
    num_files++;
    fclose(fp);
  }

  return 0;
}
