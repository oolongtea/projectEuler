#include <stdio.h> // printf()
#include <stdlib.h> // atol()
#include <string.h> // memset()
#include <math.h> // sqrt(), pow()

/* Yields Array of Prime Numbers using Sieve of Erat. */
void sieveOfEratosthenes(char *);
int isFactor(long int);

static long int largestPrimeFactor, num;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("USAGE: %s <desiredNum>\n", argv[0]);
        printf("EXAMPLE: %s 405\n", argv[0]);
        return -1;
    }

    long int temp = atol(argv[1]);
    num = temp;

    //printf("num: %ld\n", num);

    int sizeArray = sqrt(num);
    char *array = (char *) malloc(sizeArray + 1);
    //memset(array, 1, sizeArray);
    //printf("size array: %d\n", sizeof(array));

    /* fill array with true values */
    long int i;
    for (i = 0; i < sqrt(num); i++) {
        array[i] = '1';
        //printf("array[%d] = %d\n", i, array[i]);
    }

    //printf("b4 sieve\n");
    sieveOfEratosthenes(array);
    //printf("after sieve\n");

    for (i = 2; i < sqrt(num); i++) {
        if (array[i] == '1' && isFactor(i) == 1) {
            printf("%ld\n", i);
        }
    }

    /* Printing all values -- test
    int s = 0;
    while (s < num) {
        printf("%d ", array[s]);
        if (s % 10 == 0) {printf("\n\t%d\n", s);}
        s++;
    }
    */
    //printf("after while\n");

    free(array);
    return 0;
}

void sieveOfEratosthenes(char *array)
{
    long int i, j, k = 0;
    for (i = 2; i < sqrt(num); i++) {
        //printf("inside for\n");
        if (array[i] == '1') {
            //printf("inside if\n");
            j = pow(i, 2);
            while (j < sqrt(num)) {
                //printf("inside while\n");
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
