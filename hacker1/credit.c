#include <stdio.h>
#include <math.h>
#include "cs50.h"

//returns the no of digits in the card number
int numDigits(long long cardNo) {
    int i = 0;
    while (cardNo){
        cardNo /= 10;
        ++i;
    }
    return i;
}

//returns the sum as per algo
int getSum(long long cardNo) {
    int divisor, sum, digit, iter;
    divisor = 10;
    sum = 0;
    iter = 1;
    while (cardNo) {
        digit = cardNo % divisor;
        cardNo = cardNo / divisor;
        if (iter%2)
            sum = sum + digit;
        else {
            digit = digit*2;
            while (digit) {
                sum = sum + digit % 10;
                digit = digit / 10;
            }
        }
        ++iter;
    }
    return sum;
}

int main() {
    long long cardNo;
    int sum, firstTwo;
    sum = firstTwo = 0;

    printf("Number: ");
    cardNo = GetLongLong();

    firstTwo =  cardNo / pow(10, numDigits(cardNo) - 2);
    sum = getSum(cardNo);

    if (!(sum % 10)) {
        switch (firstTwo) {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            case 34:
            case 37:
                printf("AMEX\n");
                break;
            default:
                if ((firstTwo / 10) == 4)
                    printf("VISA\n");
                else
                    printf("INVALID\n");
        }
    }
    else
        printf("INVALID\n");

    return 0;
}