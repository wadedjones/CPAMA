#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: compress_file <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fpin, *fpout;
  const char *filename = argv[1];

  if ((fpin = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  unsigned char byte, next, count;
  long int position;

  char *outfile = malloc(sizeof(filename) + 5);
  stpcpy(outfile, filename);
  strcat(outfile, ".rle");

  if ((fpout = fopen(outfile, "wb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", outfile);
    exit(EXIT_FAILURE);
  }
  free(outfile);

  while (fread(&byte, sizeof(unsigned char), 1, fpin) > 0) {
    count = 1;
    position = ftell(fpin);

    while (fread(&next, sizeof(unsigned char), 1, fpin) > 0 && byte == next) {
      count++;
    }
    fwrite(&count, sizeof(unsigned char), 1, fpout);
    fwrite(&byte, sizeof(unsigned char), 1, fpout);
    fseek(fpin, position + (count - 1), SEEK_SET);
  }

  fclose(fpin);
  fclose(fpout);

  return 0;
}
