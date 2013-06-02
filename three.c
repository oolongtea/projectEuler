#include <stdio.h> // printf()
#include <stdlib.h> // atoi()
#include <string.h> // memset()
#include <math.h> // sqrt(), pow()

void sieveOfEratosthenes(int *);

static int largestPrimeFactor, num;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("USAGE: %s <desiredNum>\n", argv[0]);
        printf("EXAMPLE: %s 405\n", argv[0]);
        return -1;
    }

    int temp = atoi(argv[1]);
    num = temp;
    int sizeArray = sizeof(int) * num;
    int *array = (int *) malloc(sizeArray);
    //memset(array, 1, sizeArray);
    printf("size array: %d\n", sizeof(array));

    int i;
    for (i = 0; i < num; i++) {
        array[i] = 1;
        printf("array[%d] = %d\n", i, array[i]);
    }

    printf("b4 sieve\n");
    sieveOfEratosthenes(array);
    printf("after sieve\n");

    int s = 0;
    while (s < num) {
        printf("%d ", array[s]);
        if (s % 5 == 0) {printf("\n");}
        s++;
    }
    
/*    
    while (s < num) {
        //printf("inside while\n");
        if (array[s] == 1) {
            printf("inside if\n");
            printf("%d\n", s);
        }
        s++;
    }
 */   
    printf("after while\n");

    free(array);
    return 0;
}

void sieveOfEratosthenes(int *array)
{
    int i, j, k = 0;
    for (i = 0; i < sqrt(num); i++) {
        printf("inside for\n");
        if (array[i] == 1) {
            printf("inside if\n");
            for (j = pow(i, 2); j < num; j += (i*i)) {
                //printf("inside second for\n");
                printf("j: %d\n", j);
                array[j] = 0;
                k++;
            }
        } 
    }
}
