#include <stdio.h> // printf(), sprintf()
#include <stdlib.h> // atoi()     // atol()
#include <string.h> // strlen()    // memset()
#include <math.h>// log10()      // sqrt(), pow()

int numOfDigits(int num);
char *int2str(int num);
char *revStr(char *num);
int isPalindrome(int num);


int main(int argc, char **argv)
{
    // checks for correct usage
    if (argc != 2) {
        printf("> This program yields the largest palindrome \n");
        printf("> made from the product of two n-digit numbers.\n");
        printf("USAGE: %s <numOfDigits>\n", argv[0]);
        printf("EXAMPLE: %s 2\t\n", argv[0]);
    }

    int num = atoi(argv[1]);

    char *str = int2str(num);
    char *rev = revStr(str);
    printf("num: %d\tstr: %s\trev: %s\n", num, str, rev);

    free(rev);
    free(str); 
    return 0;
}

int numOfDigits(int num)
{
    return log10(num) + 1;
}

char *int2str(int num)
{
    int size = numOfDigits(num) + 1;
    char *str = (char *) malloc(size);
    memset(str, 0, size);
    sprintf(str, "%d", num);
    printf("%s\n", str);
    return str;
}

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

/*
int isPalindrome(char *num);
{
    
}
*/
