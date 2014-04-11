#include <stdio.h> // printf()
#include <stdlib.h> //  atoi()

int sumNumbers(int num);
void sumOfSqrs(int num);

int sumSqrs;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Gives difference between the sum of the squares of the\n");
        printf("first N natural numbers and the square of the sum\n\n");
        printf("USAGE: %s <N>\n", argv[0]);
        return 1;
    }

    int num = atoi(argv[1]);

    int sum = sumNumbers(num);
    int sqrSum = sum * sum;

    sumOfSqrs(num);

    printf("%d\n", sqrSum - sumSqrs);   

    return 0;
}

int sumNumbers(int num) 
{
    return ( (num*num)/2 + num/2 );
}

void sumOfSqrs(int n)
{
    int i;
    for (i = 0; i < n+1; i++) {
        sumSqrs += i*i;
    }
}
