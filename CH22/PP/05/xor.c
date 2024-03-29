/* Performs XOR encryption */

#include <stdio.h>
#include <stdlib.h>

void encrypt_file(const char *file1, char *file2, const char key);

int main(int argc, char **argv) {

  if (argc < 3) {
    fprintf(stderr, "usage: xor <filename1> <filename2>\n");
    exit(EXIT_FAILURE);
  }

  const char *file1 = argv[1];
  char *file2 = argv[2];
  const char key = '&';

  encrypt_file(file1, file2, key);

  return 0;
}

void encrypt_file(const char *file1, char *file2, const char key) {
  FILE *fp1, *fp2;
  int ch, ech;

  if ((fp1 = fopen(file1, "rb")) == NULL) {
    fprintf(stderr, "Cannot open file %s\n", file1);
    exit(EXIT_FAILURE);
  }

  if ((fp2 = fopen(file2, "wb")) == NULL) {
    fprintf(stderr, "Cannot open file %s\n", file2);
    exit(EXIT_FAILURE);
  }

  while ((ch = fgetc(fp1)) != EOF) {
    ech = ch ^ key;
    fputc(ech, fp2);
  }

  fclose(fp1);
  fclose(fp2);

  return;
}
