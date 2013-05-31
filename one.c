/*
  Find sum of multiples of two numbers that are less than a number.
*/

#include <stdio.h> // printf()
#include <stdlib.h> // atoi()

/* Functions */
int multipleOf(int);
void findSumOfMultiples(int, int, int);

/* Resulting Sum */
static int sumOfMultiples;

int main (int argc, char **argv)
{
    if (argc != 4) {
        printf("USAGE: %s <multiple> <multiple> <lessThan>\n", argv[0]);
        printf("EXAMPLE: %s 3 5 100\n", argv[0]);
        return 1;
    }

    int multiple1 = atoi(argv[1]);
    int multiple2 = atoi(argv[2]);
    int lessThan = atoi(argv[3]);

    findSumOfMultiples(multiple1, multiple2, lessThan);
    
    printf("sum of multiples of %d and %d below %d is %d\n",
                multiple1, multiple2, lessThan, sumOfMultiples); 

    return 0;
}

int isMultipleOf(int number, int divisor) 
{
    return number % divisor;
}

void findSumOfMultiples(int multiple1, int multiple2, int lessThan)
{
    int i = 0;

    while (i < lessThan) {
        if (!isMultipleOf(i, multiple1) || !isMultipleOf(i, multiple2)) {
            sumOfMultiples += i;
        } 
        i++;
    }

}
