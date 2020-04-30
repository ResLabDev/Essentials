/*
A square of squares
You like building blocks. You especially like building blocks that are squares. And what you even like more, is to arrange them into a square of square building blocks!
However, sometimes, you can't arrange them into a square. Instead, you end up with an ordinary rectangle! Those blasted things! If you just had a way to know, whether you're currently working in vain… Wait! That's it! You just have to check if your number of building blocks is a perfect square.

Task
Given an integral number, determine if it's a square number:

In mathematics, a square number or perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself.

The tests will always use some integral number, so don't worry about that in dynamic typed languages.

Examples
is_square(-1) // returns false
is_square(0)  // returns true
is_square(3)  // returns false
is_square(4)  // returns true
is_square(25) // returns true
is_square(26) // returns false
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_square(int n)
{
    bool b_ret = false;
    int squareRoot = (int)sqrt((double)n);

    b_ret = (((squareRoot * squareRoot) == n) ? true : false);
    return b_ret;
}

main (void)
{
    printf((is_square(25) == true) ? "TRUE" : "FALSE");
    return 0;
}
