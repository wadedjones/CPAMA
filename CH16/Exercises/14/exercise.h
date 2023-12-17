#ifndef EXERCISE_H
#define EXERCISE_H

#define RECTANGLE 0
#define CIRCLE 1

struct point {
  int x, y;
};

struct shape {
  int shape_kind;
  struct point center;
  union {
    struct {
      int height, width;
    } rectangle;
    struct {
      int radius;
    } circle;
  } u;
};

#endif
