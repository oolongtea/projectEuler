#include <stdio.h> // printf()
#include <stdlib.h> //  atoi()

int sumNumbers(int num);
void sumOfSqrs(int num);

int sumSqrs;

int main(int argc, char **argv)
{
    int num = atoi(argv[1]);

    int sum = sumNumbers(num);
    int sqrSum = sum * sum;

    sumOfSqrs(num);

    printf("sln: %d\n", sqrSum - sumSqrs);   

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
