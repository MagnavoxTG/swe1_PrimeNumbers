#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_prime(long long int n);
int prime_factor(long long int n);

void main() {
    int x = 0;
    char intreadout[255] = "";
    long long int number = 0;

    while (x != 1) {
        // printf shows a message asking you to enter a positive number
        printf("\nPlease enter a positive number (f.e. 202): ");
        //scanf writes the input into a string (char array)
        scanf("%s", intreadout);
        // strspan checks how many of the specified character are inside the string and gives an integer
        // strlen checks how long the string (char array) is and gives an integer
        // if they are the same then there are only allowed characters in the string
        if (strspn(intreadout, "0123456789") == strlen(intreadout)) {
            number = (long long int)atoll(intreadout);
            printf("All prime numbers up to %lli:\n", number);
            if (is_prime(number) == 2) {
                printf("Entering the number 1 seems rather pointless doesnt it");
            }
            for (long long int n = number; n >= 2; n--){
                if (is_prime(n) == 1){
                    printf("%lli\n",n);
                }
            }
            prime_factor(number);
            x = 1;
        } else {
            printf("invalid input");
        }
    }
}

int is_prime(long long int n) {
    if (n == 1) {
        return 2;
    }
    for(long long i = 2; i <= n/2; ++i) {
        // if the number is divisible then its not a prime number
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int prime_factor(long long int n) {
    int i = 2;
    printf("\nThe prime factors of the number %lli are: ",n);
    while (n != 1) {
        if (is_prime(n) == 0) {
            if (n%i == 0){
                n = n / i;
                printf("%i ",i);
            } else {
                i++;
            }
        } else {
            printf("%lld",n);
            n = n/n;
        }
    }
}