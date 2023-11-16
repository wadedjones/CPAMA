/* Modify PP 8 from chapter 5 so that it includes the following function:
 *
 * void find_closest_flight(int desired_time, int *departure_time, int
 * *arrival_time);
 *
 * This function will find the flight whose departure time is closest to
 * desired_time (expressed in minutes since midnight). It will store the
 * departure and arrival times of this flight (also expressed in minutes since
 * midnight) int the variables pointed to by departure_time and arrival_time,
 * respectively. */

/* Departure time Arrival time */
/*		 8:00AM		10:16AM d1
 *		 9:43AM		11:52AM d2
 *		11:19AM		 1:31PM d3
 *		12:47PM		 3:00PM d4
 *		 2:00PM		 4:08PM d5
 *		 3:45PM		 5:55PM d6
 *		 7:00PM		 9:20PM d7
 *		 9:45PM		11:58PM d8
 *		 */

#include <stdio.h>

#define d1 480
#define d2 583
#define d3 679
#define d4 767
#define d5 840
#define d6 945
#define d7 1140
#define d8 1305
#define a1 616
#define a2 712
#define a3 811
#define a4 900
#define a5 968
#define a6 1075
#define a7 1280
#define a8 1438

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time);

int main(void) {
  int hr, min, desired_time, departure_time, arrival_time;

  printf("Enter departure time: ");
  scanf("%d :%d", &hr, &min);

  desired_time = hr * 60 + min;

  find_closest_flight(desired_time, &departure_time, &arrival_time);

  printf("Departure: %d, Arrival: %d\n", departure_time, arrival_time);

  return 0;
}

void find_closest_flight(int desired_time, int *departure_time,
                         int *arrival_time) {
  if (desired_time < d1 + (d2 - d1) / 2) {
    *departure_time = d1;
    *arrival_time = a1;
  } else if (desired_time < d2 + (d3 - d2) / 2) {
    *departure_time = d2;
    *arrival_time = a2;
  } else if (desired_time < d3 + (d4 - d3) / 2) {
    *departure_time = d3;
    *arrival_time = a3;
  } else if (desired_time < d4 + (d5 - d4) / 2) {
    *departure_time = d4;
    *arrival_time = a4;
  } else if (desired_time < d5 + (d6 - d5) / 2) {
    *departure_time = d5;
    *arrival_time = a5;
  } else if (desired_time < d6 + (d7 - d6) / 2) {
    *departure_time = d6;
    *arrival_time = a6;
  } else if (desired_time < d7 + (d8 - d7) / 2) {
    *departure_time = d7;
    *arrival_time = a7;
  } else {
    *departure_time = d8;
    *arrival_time = a8;
  }
}
