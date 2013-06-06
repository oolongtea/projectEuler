#include <stdio.h> // printf()
// #include <stdlib.h> // atoi()

void sieveOfEratosthenes(char *array);

long int counter;


int main(int argc, char **argv) 
{
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
    sieveOfEratosthenes();

    

}

/* method extracted from wikipedia page */
void sieveOfEratosthenes(char *array)
{
    long int i, j = 0;

    while (

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
