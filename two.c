/* Find sum of Fibonacci numbers below a specified number */

#include <stdio.h> // printf()
#include <stdlib.h> // atoi()
#include <math.h> // pow()

/* Functions */
int fibonacci(int);
int isEven(int);
void sumFiboNums(int);

/* Resulting Sum */
static int sum;

int main(int argc, char **argv)
{
    /* test for correct usage */
    if (argc != 2) {
        printf("USAGE: %s <maxFibonacciNumber>\n", argv[0]);
        printf("EXAMPLE: %s 1000\n", argv[0]);
        return 1;
    }

    /* Find Sum of Fibonacci Numbers less than 'lessThan' */
    int lessThan = atoi(argv[1]);
    sumFiboNums(lessThan);

    /* Print Result */
    printf("Sum of even-valued Fibonacci numbers less than");
    printf(" %s is %d\n", argv[1], sum);

    return 0;
}

/* Find a Fibonacci number with Binet's formula */
int fibonacci(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    /* Binet's formula */
    return (int) ((pow(phi, (double) n) - pow(psi, (double) n)) / sqrt(5));

}

int isEven(int n)
{
    if (n % 2 ==0) 
        return 1;
    else 
        return 0;
}

void sumFiboNums(int lessThan)
{ 
    int i = 2;
    int n = fibonacci(i);
    
    while (n < lessThan) { // while Fibonacci number < 'lessThan'
        i++;
        if (isEven(n)) { // add even values to the sum
            sum += n;
        }
        n = fibonacci(i);
    }
}
