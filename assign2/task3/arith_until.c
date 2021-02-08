/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

void calculation(float radiusMil) {
  float radiusIn, areaIn, circIn;
  if (radiusMil == 0) {
    printf("Exit\n");
    return;
  }
  else {
    radiusIn = radiusMil / 25.4;
    areaIn = PI * radiusIn * radiusIn;
    circIn = PI * 2 * radiusIn;
    printf("Circle's area is %3.2f (sq in).\n", areaIn);
  printf("Its circumference is %3.2f (in).\n", circIn);
  printf("Enter radius (in mm):\n");
  scanf("%f", &radiusMil);
  calculation(radiusMil);
  return;

  }

}


int main()
{
  float r;
  printf("Enter radius (in mm):\n");
  scanf("%f", &r);
  calculation(r);
  
}
