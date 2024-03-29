#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50

void encrypt_msg(char *infile, char *outfile, int shift);

int main(void) {

  char infile[MAX_FILE_NAME], outfile[MAX_FILE_NAME];
  int shift;

  printf("Enter name of file to be encrypted: ");
  scanf(" %s", infile);

  printf("Enter shift amount (1-25): ");
  scanf(" %d", &shift);

  strcpy(outfile, infile);
  strcat(outfile, ".enc");

  encrypt_msg(infile, outfile, shift);

  return 0;
}

void encrypt_msg(char *infile, char *outfile, int shift) {

  FILE *in_fp, *out_fp;

  if ((in_fp = fopen(infile, "r")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", infile);
    exit(EXIT_FAILURE);
  }

  if ((out_fp = fopen(outfile, "w")) == NULL) {
    fprintf(stderr, "cannot save file %s\n", outfile);
    exit(EXIT_FAILURE);
  }

  int c;

  while ((c = fgetc(in_fp)) != EOF) {
    if (c >= 'a' && c <= 'z') {
      c = (((c - 'a') + shift) % 26 + 'a');
      fputc(c, out_fp);
    } else if (c >= 'A' && c <= 'Z') {
      c = (((c - 'A') + shift) % 26 + 'A');
      fputc(c, out_fp);
    } else {
      fputc(c, out_fp);
    }
  }

  fclose(in_fp);
  fclose(out_fp);
}
