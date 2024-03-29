#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 12
#define MAX_FLIGHTS 100

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "usage: flights.c <filename>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char *filename = argv[1];

  /* flight times converted to minutes from midnight */
  int flight_mins[MAX_FLIGHTS][2] = {0};
  /* array for reading file and using sscanf */
  char flight_times[MAX_LEN];

  int d_hr, d_min, a_hr, a_min; // depart hour/min, arrive hour/min
  int idx = 0;                  // flight_mins index
  int depart = 0; // parsing and converting user desired departure time

  if ((fp = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while (fgets(flight_times, MAX_LEN, fp) != NULL) {
    if (flight_times[0] == '\n') {
      continue;
    }
    flight_times[strcspn(flight_times, "\n")] = '\0';
    sscanf(flight_times, "%d%*[:]%d %d%*[:]%d", &d_hr, &d_min, &a_hr, &a_min);
    flight_mins[idx][0] = (d_hr * 60) + d_min;
    flight_mins[idx][1] = (a_hr * 60) + a_min;
    idx++;
  }

  printf("Enter desired departure time: ");
  scanf(" %d%*[:]%d", &d_hr, &d_min);
  d_hr *= 60;
  depart = d_hr + d_min;

  int num = 0; // index for flight_mins (since midnight)

  while (depart > flight_mins[num][0] && num < idx) {
    num++;
  }

  /* check closest depart time */
  if (num > 0) {
    if (((flight_mins[num][0] + flight_mins[num - 1][0]) / 2) > depart) {
      num--;
    }
  }

  /* check if desired depart time is passed latest depart time */
  if (num == idx) {
    num--;
  }

  printf("Departure Time: %2d:%.2d\n", flight_mins[num][0] / 60,
         flight_mins[num][0] % 60);
  printf("Arrival   Time: %2d:%d\n", flight_mins[num][1] / 60,
         flight_mins[num][1] % 60);

  fclose(fp);

  return 0;
}
