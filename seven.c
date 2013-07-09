#include <stdio.h> // printf()
#include <stdlib.h> // atol()
#include <math.h> // pow()

void sieveOfEratosthenes(char *array);

long int counter, num;
const int sizeArray = 1024 * 1024;

int main(int argc, char **argv) 
{
    // store argument as long int
    long int temp = atol(argv[1]);
    num = temp;

    /* allocate enough memory for true/false array
       array will hold values for true (prime num)
                           or for false (not prime) 
    */
    char *array = (char *) malloc(sizeArray + 1);

    /* fill array with true values */
    long int i;
    for (i = 0; i < sizeArray; i++) {
        array[i] = '1';
    }

    // fill array with prime numbers below sqrt(num)
    sieveOfEratosthenes(array);

    i = 1;
    while (i < sizeArray) {
        //printf("array[%ld] = %c\n", i, array[i]);
        if(array[i] == '1') {printf("%ld\n", i);}
        if(counter == num) {break;}
        i++;
    }
/*
    i = sizeArray;
    do {
        if (array[i] == '1') {
            counter = i;    
        }
        i--;
    } while (counter != 0);
*/
    printf("%ld\n", counter);

    free(array);
    return 0;
}

/* method extracted from wikipedia page */
void sieveOfEratosthenes(char *array)
{
    long int i, j = 0;

    for (i = 2; i < sizeArray; i++) {
        if (array[i] == '1') {
            j = pow(i, 2);
            while (j < sizeArray) {
                array[j] = '0';
                j += i;
            }
        } 
    }
}
