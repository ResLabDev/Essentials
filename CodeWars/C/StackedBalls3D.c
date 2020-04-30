// Stacked Balls - 3D
/*
I have stacked some cannon balls in a triangle-based pyramid.
Kata Task
Given the number of layers of my stack, what is the total height?
Return the height as multiple of the ball diameter.
Example
The image above shows a stack of 3 layers.
Notes
layers >= 0
approximate answers (within 0.001) are good enough
*/

#include <math.h>

double stack_height_3d(int layers)
{
    const double h = sqrt(6) / 3.0;

    return ((layers) ? (float)(layers - 1) * h + 1.0 : 0) ;
}

int main (void)
{
    printf("%d: %lf: \n", 0, stack_height_3d(0));
    printf("%d: %lf: \n", 1, stack_height_3d(1));
    printf("%d: %lf \n", 2, stack_height_3d(2));
    printf("%d: %lf \n", 3, stack_height_3d(3));
    printf("%d: %lf \n", 4, stack_height_3d(4));

    return 0;
}


