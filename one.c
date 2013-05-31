/*
  Find sum of multiples of
*/

#include <stdio.h>
//#include <math.h>

int multipleOf(int src);
static int sumOfMultiples;

int main (int argc, char **argv)
{
    if (argc != 2) {
        

    return 0;
}

int multipleOf(int number, int divisor) {
    return number % divisor;
}
