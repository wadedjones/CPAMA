#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: uncompress_file <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fpin, *fpout;
  char *filename = argv[1];
  char *rle_check = filename + strlen(filename);

  for (; *rle_check != '.'; rle_check--)
    ;

  if (strcmp(rle_check, ".rle") != 0) {
    fprintf(stderr, "usage: filename must include '.rle' extension\n");
    exit(EXIT_FAILURE);
  }

  char *outname = malloc(strlen(filename) - 4);
  strncpy(outname, filename, strlen(filename) - 4);

  int count, position = 0;
  unsigned char byte;

  if ((fpin = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  if ((fpout = fopen(outname, "wb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", outname);
    exit(EXIT_FAILURE);
  }

  free(outname);

  while (fread(&byte, sizeof(unsigned char), 1, fpin) > 0) {
    if (position % 2 == 0) {
      count = (int)byte;
    } else {
      for (int i = 0; i < count; i++) {
        fwrite(&byte, sizeof(unsigned char), 1, fpout);
      }
    }
    position++;
  }

  fclose(fpin);
  fclose(fpout);

  return 0;
}
