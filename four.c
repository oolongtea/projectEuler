#include <stdio.h> // printf(), sprintf()
#include <stdlib.h> // atoi()     // atol()
#include <string.h> // strlen()    // memset()
#include <math.h>// log10()      // sqrt(), pow()

int numOfDigits(int num);
char *int2str(int num);
char *revStr(char *num);
int isPalindrome(char *str1, char *str2);


int main(int argc, char **argv)
{
    // checks for correct usage
    if (argc != 2) {
        printf("> This program yields the largest palindrome \n");
        printf("> made from the product of two n-digit numbers.\n");
        printf("USAGE: %s <numOfDigits>\n", argv[0]);
        printf("EXAMPLE: %s 2\t\n", argv[0]);
    }

    int digits = atoi(argv[1]);

    int i, j = 0;
    for (i = 1; numOfDigits(i) < (digits+1); i++) {
    for (j = 1; numOfDigits(j) < (digits+1); j++) {
    int num = i * j;
    char *str = int2str(num);
    char *rev = revStr(str);
    if (isPalindrome(str, rev) == 0) {printf("%d * %d = %d\n",i,j,num);}
    //printf("num: %d\tstr: %s\trev: %s\n", num, str, rev);
    //printf("palindrome: %d\n", isPalindrome(str, rev));
    free(rev);
    free(str); 
    }
    }
    return 0;
}

int numOfDigits(int num)
{
    return log10(num) + 1;
}

char *int2str(int num)
{
    //printf("numdig: %d\n", numOfDigits(num));
    int size = numOfDigits(num) + 1;
    char *str = (char *) malloc(size);
    memset(str, 0, size-1);
    sprintf(str, "%d", num);
    //printf("%s\n", str);
    return str;
}

// reverses string with XOR
char *revStr(char *num)
{
    int size = strlen(num) + 1;
    char *rev = (char *) malloc(size);
    memset(rev, 0, size);
    strcpy(rev, num);

    char *beg = rev;
    char *end = rev + strlen(rev) - 1;
    while (rev < end) {
        *rev ^= *end;
        *end ^= *rev;
        *rev ^= *end;
        rev++;
        end--;
    }
    rev = beg;
    return rev;
}


int isPalindrome(char *str1, char *str2)
{
    return strcmp(str1, str2);
}

