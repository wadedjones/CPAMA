#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int num_files = 1;

  if (argc < 2) {
    printf("usage: canopen <filename>\n");
    exit(EXIT_FAILURE);
  }

  bool failure = false;

  while (num_files < argc) {
    if ((fp = fopen(argv[num_files], "r")) == NULL) {
      printf("%s can't be opened\n", argv[num_files]);
      failure = true;
    } else {
      printf("%s can be opened\n", argv[num_files]);
    }
    num_files++;
    fclose(fp);
  }

  if (failure) {
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
