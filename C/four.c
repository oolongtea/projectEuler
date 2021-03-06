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
    // check for correct usage
    if (argc != 2) {
        printf("\tUSAGE ERROR\n"
               "USAGE: %s <numOfDigits>\n"
               "\n\tEXAMPLE\n"
               "> Problem 4: Find the largest palindrome from the\n> "
               "product of two 3-digit numbers.\n"
               "COMMAND: %s 3\n"
               "yields answer of 906609\n",  argv[0], argv[0]);
        return 1;
    }

    // store number of digits
    int digits = atoi(argv[1]);

    // double for loop finds i * j, converts to char*, 
    // compares with reverse string, and stores in 'palin' variable
    // note: this takes a very long time
    int i, j, palin = 0;
    for (i = 1; numOfDigits(i) < (digits+1); i++) {
        for (j = 1; numOfDigits(j) < (digits+1); j++) {
            int num = i * j;
            char *str = int2str(num);
            char *rev = revStr(str);
            if (isPalindrome(str, rev) == 0 && (num > palin)) {
                palin = num;
            }
            free(rev);
            free(str); 
        }
    }

    // print result
    printf("%d\n", palin);
    return 0;
}

int numOfDigits(int num)
{
    return log10(num) + 1;
}

// integer to char*
char *int2str(int num)
{
    int size = numOfDigits(num) + 1;
    char *str = (char *) malloc(size);
    memset(str, 0, size-1);
    sprintf(str, "%d", num);

    return str;
}

// reverses string with XOR
char *revStr(char *num)
{
    int size = strlen(num) + 1;
    char *rev = (char *) malloc(size);
    memset(rev, 0, size);
    strcpy(rev, num);

    // XOR method
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

