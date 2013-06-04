/* Prints Prime Factors of a Number */

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

    // print numbers that are prime and factor of desired number
    for (i = 2; i < sqrt(num); i++) {
        if (array[i] == '1' && isFactor(i) == 1) {
            printf("%ld\n", i);
        }
    }

    free(array); // free allocated memory
    return 0;
}

/* method extracted from wikipedia page */
void sieveOfEratosthenes(char *array)
{
    long int i, j, k = 0;
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
