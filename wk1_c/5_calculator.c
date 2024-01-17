#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // overflow
    int a1 = 2000000000;
    int b1 = 2000000000;
    printf("%i\n", a1 + b1);  // there will be an error if you declare "int n = 4000000000", because n is overflow.

    long a2 = 2000000000;
    long b2 = 2000000000;
    printf("%li\n", a2 + b2);
    printf("-----------------------\n");

    // truncation
    long c1 = 1;
    long d1 = 3;
    printf("%li\n", c1 / d1);

    float e1 = c1 / d1;
    printf("%f\n", e1);    // Printf("%f", e / f) has a bug because 'e' and 'f' are "long" and "%f" is corrspond to "float".

    float c2 = 1;
    float d2 = 3;
    printf("%f\n", c2 / d2);

    float e2 = (float) c1 / (float) d1;
    printf("%f\n", e2);
    printf("%f\n", (float) (c1 / d1));
    printf("-----------------------\n");

    // Print more digits after the decimal point
    double e3 = (double) c1 / (double) d1;
    printf("%.20f\n", e2);
    printf("%.20f\n", e3);   // Accurate to the 15th digit after the decimal point
    printf("-----------------------\n");

    // As soon as you have more precise data type on the right, it just treat everything as folating point value so as that the math works out.
    int f1 = 73;
    int f2 = 72;
    int f3 = 33;

    printf("%i\n", (f1 + f2 + f3) / 3);
    printf("%f\n", (f1 + f2 + f3) / 3.0);  //  3.0 is the foating-ponit data type.
    printf("%f\n", (f1 + f2 + f3) / (float) 3);
    printf("%f\n", (f1 + f2 + f3) / (double) 3);
    printf("-----------------------\n");
}