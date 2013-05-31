#include <stdio.h> // printf()
#include <math.h> // pow()

int fibonacci(int);
int isEven(int);
void sumFiboNums(int);

static int sum;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("USAGE: %s <maxFibonacciNumber>\n", argv[0]);
        printf("EXAMPLE: %s 1000\n", argv[0]);
        return 1;
    }

    int lessThan = atoi(argv[1]);
    sumFiboNums(lessThan);

    printf("Sum of even-valued Fibonacci numbers less than");
    printf(" %s is %d\n", argv[1], sum);

    return 0;
}

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
    printf("%d\n", n);
    while (n < lessThan) {
        i++;
        if (isEven(n)) {
            sum += n;
        }
        n = fibonacci(i);
    }
}
