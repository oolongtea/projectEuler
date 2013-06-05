#include <stdio.h> // printf()
#include <stdlib.h> // atoi()

int isFactor(int num, int divisor);
int isEvenlyDivisible(int num);

int result;

int main (int argc, char **argv)
{
    result = 2520;
    
    while (isEvenlyDivisible(result) == 0) {
        result++;
    }

    printf("result: %d\n", result);

    return 0;
}

int isFactor(int num, int divisor)
{
    return num % divisor;
}

int isEvenlyDivisible(int num)
{
    int i; 
    for (i = 1; i < 21; i++) {
        if (isFactor(num, i) != 0) {
            //printf("fail test\n");
            return 0;
        }
    }
    return 1;
}
