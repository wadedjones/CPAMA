#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define FILENAME_LEN 255
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int main(int argc, char **argv) {

  if (argc != 4) {
    fprintf(
        stderr,
        "usage: merge_inventory <filename1> <filename2> <merged_filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp_in1, *fp_in2, *fp_out;
  char *filename1 = argv[1];
  char *filename2 = argv[2];
  char *outfile = argv[3];

  if ((fp_in1 = fopen(filename1, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename1);
    exit(EXIT_FAILURE);
  }

  if ((fp_in2 = fopen(filename2, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename2);
    exit(EXIT_FAILURE);
  }

  if ((fp_out = fopen(outfile, "wb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", outfile);
    exit(EXIT_FAILURE);
  }

  struct part part1, part2;
  int num_read1, num_read2;

  num_read1 = fread(&part1, sizeof(struct part), 1, fp_in1);
  num_read2 = fread(&part2, sizeof(struct part), 1, fp_in2);

  while (num_read1 == 1 && num_read2 == 1) {
    if (part1.number < part2.number) {
      fwrite(&part1, sizeof(struct part), 1, fp_out);
      num_read1 = fread(&part1, sizeof(struct part), 1, fp_in1);
    } else if (part1.number > part2.number) {
      fwrite(&part2, sizeof(struct part), 1, fp_out);
      num_read2 = fread(&part2, sizeof(struct part), 1, fp_in2);
    } else {
      if (strcmp(part1.name, part2.name) != 0) {
        printf("Part #%d names do not match, using %s\n", part1.number,
               part1.name);
      }
      part1.on_hand += part2.on_hand;
      fwrite(&part1, sizeof(struct part), 1, fp_out);
      num_read1 = fread(&part1, sizeof(struct part), 1, fp_in1);
      num_read2 = fread(&part2, sizeof(struct part), 1, fp_in2);
    }
  }

  while (num_read1 == 1) {
    fwrite(&part1, sizeof(struct part), 1, fp_out);
    num_read1 = fread(&part1, sizeof(struct part), 1, fp_in1);
  }

  while (num_read2 == 1) {
    fwrite(&part2, sizeof(struct part), 1, fp_out);
    num_read2 = fread(&part2, sizeof(struct part), 1, fp_in2);
  }

  fclose(fp_in1);
  fclose(fp_in2);
  fclose(fp_out);

  return 0;
}
