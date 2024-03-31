#include <math.h>
#include <stdio.h>

void find_root(double a, double b, double c);

int main(void) {
  double a, b, c;

  printf("Enter value of a: ");
  scanf("%lf", &a);

  printf("Enter value of b: ");
  scanf("%lf", &b);

  printf("Enter value of c: ");
  scanf("%lf", &c);

  find_root(a, b, c);

  return 0;
}

void find_root(double a, double b, double c) {
  double root1, root2, radical;

  radical = b * b - (4 * a * c);
  if (radical < 0) {
    printf("The roots are complex.\n");
    return;
  }
  radical = sqrt(radical);
  root1 = (-b + radical) / (2 * a);
  root2 = (-b - radical) / (2 * a);

  if (root1 == root2) {
    printf("The single root is: %lf\n", root1);
  } else {
    printf("Root 1: %lf\n", root1);
    printf("Root 2: %lf\n", root2);
  }
}
