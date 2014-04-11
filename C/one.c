/*
  Find sum of multiples of two numbers that are less than a number.

  Project Euler #1
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
    // check for correct usage
    if (argc != 4) {
        printf("\tUSAGE ERROR\n"
               "USAGE: %s <multiple> <multiple> <lessThan>\n"
               "\n\tEXAMPLE\n"
               "> Problem 1: Find the sum of all the multiples of"
               " 3 or 5 below 1000.\n"
               "COMMAND: %s 3 5 1000\n"
               "yields answer of 233168\n",  argv[0], argv[0]);
        return 1;
    }

    // collect command-line arguments as int's
    int multiple1 = atoi(argv[1]);
    int multiple2 = atoi(argv[2]);
    int lessThan = atoi(argv[3]);

    // find sum of multiples and put result into 'sumOfMultiples'
    findSumOfMultiples(multiple1, multiple2, lessThan);
    
    //print result
    printf("%d\n", sumOfMultiples); 

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
