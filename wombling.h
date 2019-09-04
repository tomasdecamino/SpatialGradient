//tomasdecamino.com 

#include <math.h>

struct vector {
  float mag = 0;
  float ang = 0;
};

/*  
  detects de direction of gradient 
  using 4 points in quadrant
  configured,
  top:    s2, s4
  bottom: s1, s3
*/


struct vector gradient(float s1, float s2, float s3, float s4) {
  vector v;
  float dx = s4 - s3 + 0.5 * (s3 - s4 + s2 - s1);
  float dy = s1 - s3 + 0.5 * (s3 - s4 + s2 - s1);
  v.mag = sqrt(square(dx) + square(dy));
  v.ang = atan2(dx, dy) + PI;
  return v;
}
