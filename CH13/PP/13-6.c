/* Improve the planet.c program of section 13.7 by having it ignore case when
 * comparing command-line arguments with strings in the planets array. */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int is_equal(char *planet, char *input);

int main(int argc, char *argv[]) {
  char *planets[] = {"Mercury", "Venus",  "Earth",   "Mars", "Jupiter",
                     "Saturn",  "Uranus", "Neptune", "Pluto"};

  int i, j;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      if (is_equal(planets[j], argv[i])) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }
    if (j == NUM_PLANETS)
      printf("%s is not a planet.\n", argv[i]);
  }

  return 0;
}

int is_equal(char *planet, char *input) {
  int i;

  for (i = 0; i < strlen(planet) + 1; i++) {
    if (toupper(planet[i]) != toupper(input[i]))
      break;
    if (planet[i] == '\0')
      return 1;
  }
  return 0;
}
