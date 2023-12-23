#include <stdio.h>
#include <stdlib.h>

#define TOTAL_FLIGHTS sizeof(times) / sizeof(times[0])

struct flight_times {
  char departure[10], arrival[10];
};

int find_closest_flight(struct flight_times times[], int desired_time,
                        int total_flights);

int main(void) {
  int hr, min, desired_time, time_num;
  struct flight_times times[] = {{"8:00AM", "10:16AM"}, {"9:43AM", "11:52AM"},
                                 {"11:19AM", "1:31PM"}, {"12:47PM", "3:00PM"},
                                 {"2:00PM", "4:08PM"},  {"3:45PM", "5:55PM"},
                                 {"7:00PM", "9:20PM"},  {"9:45PM", "11:58PM"}};

  printf("Enter departure time: ");
  scanf("%d :%d", &hr, &min);

  desired_time = hr * 60 + min;

  time_num = find_closest_flight(times, desired_time, TOTAL_FLIGHTS);

  printf("Departure: %s, Arrival: %s\n", times[time_num].departure,
         times[time_num].arrival);

  return 0;
}

int find_closest_flight(struct flight_times times[], int desired_time,
                        int total_flights) {
  int i;

  for (i = 0; i < total_flights; i++) {
    printf("departure: %d\n", atoi(times[i].departure) * 60);
    printf("desired time: %d\n", desired_time);
    if (desired_time < 780) {
      if (atoi(times[i].departure) * 60 < desired_time &&
          atoi(times[i].departure) * 60 > desired_time - 60)
        return i;
    } else {
      if ((atoi(times[i].departure) + 12) * 60 < desired_time &&
          (atoi(times[i].departure) + 12) * 60 > desired_time - 60) {
        return i;
      }
    }
  }
  return i;
}
