function
<cmath> <ctgmath>
ceil
c++ version : C90C99C++98C++11
C99 C++11
Header <tgmath.h> provides a type-generic macro version of this function.

     double ceil (double x);
      float ceil (float x);
long double ceil (long double x);

作用：
Round up value
Rounds x upward, returning the smallest integral value that is not less than x.



Parameters：
x
Value to round up.

Return Value：
The smallest integral value that is not less than x (as a floating-point value).

Example
/* ceil example */
#include <stdio.h>      /* printf */
#include <math.h>       /* ceil */

int main ()
{
  printf ( "ceil of 2.3 is %.1f\n", ceil(2.3) );
  printf ( "ceil of 3.8 is %.1f\n", ceil(3.8) );
  printf ( "ceil of -2.3 is %.1f\n", ceil(-2.3) );
  printf ( "ceil of -3.8 is %.1f\n", ceil(-3.8) );
  return 0;
}
Edit & Run


Output:

ceil of 2.3 is 3.0
ceil of 3.8 is 4.0
ceil of -2.3 is -2.0
ceil of -3.8 is -3.0

See also
floor
Round down value (function )
fabs
Compute absolute value (function )
modf
Break into fractional and integral parts (function )