/* 
 * Prints Largest Prime Factor of a Number 
 */

#include <stdio.h> // printf()
#include <stdlib.h> // atol()
#include <string.h> // memset()
#include <math.h> // sqrt(), pow()

/* Yields Array of Prime Numbers using Sieve of Erat. */
void sieveOfEratosthenes(char *);
/* Tests if it's a factor of given number */
int isFactor(long int);

static long int num; 

int main(int argc, char **argv)
{
    // check for correct usage
    if (argc != 2) {
        printf("\tUSAGE ERROR\n"
               "USAGE: %s <desiredNumber>\n"
               "\n\tEXAMPLE\n"
               "> Problem 3: Find the largest prime factor of\n> "
               "the number 600851475143.\n"
               "COMMAND: %s 600851475143\n"
               "yields answer of 6857\n",  argv[0], argv[0]);
        return 1;
    }
    // check for correct usage
    if (argc != 2) {
        printf("USAGE: %s <desiredNum>\n", argv[0]);
        printf("EXAMPLE: %s 405\n", argv[0]);
        return -1;
    }
    
    // store argument as long int
    long int temp = atol(argv[1]);
    num = temp;

    /* allocate enough memory for true/false array
       array will hold values for true (prime num)
                           or for false (not prime) 
    */
    int sizeArray = sqrt(num);
    char *array = (char *) malloc(sizeArray + 1);

    /* fill array with true values */
    long int i;
    for (i = 0; i < sqrt(num); i++) {
        array[i] = '1';
    }

    // fill array with prime numbers below sqrt(num)
    sieveOfEratosthenes(array);

    long int largestPrimeFactor;
    // find number that is prime and factor of desired number
    for (i = 2; i < sqrt(num); i++) {
        if (array[i] == '1' && isFactor(i) == 1) {
            largestPrimeFactor = (long int) i;
        }
    }

    // print result
    printf("%ld\n", largestPrimeFactor);

    free(array); // free allocated memory
    return 0;
}

/* method extracted from wikipedia page */
void sieveOfEratosthenes(char *array)
{
    long int i, j = 0;
    for (i = 2; i < sqrt(num); i++) {
        if (array[i] == '1') {
            j = pow(i, 2);
            while (j < sqrt(num)) {
                array[j] = '0';
                j += i;
            }
        } 
    }
}

int isFactor(long int n)
{
    return (num % n == 0);
}
