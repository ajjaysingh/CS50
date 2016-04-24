#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"
#include <math.h>

#define QUARTERS 25
#define DIME 10
#define NICKLES 5
#define PENNIES 1

int main() {
    float amount;
    int cents, coins;
    coins = 0;

    printf("O hai! How much change is owed?\n");

    //take positive floating point input $.Cents
    while ((amount = GetFloat()) < 0)                   //the other way of doing this accurately is to take input as string and
        printf("How much change is owed?\n");           // then getting the values before and after the point accurately and then
                                                        // doing the calculation accordingly.
    cents = (int) round(amount * 100);
    coins = coins + cents / QUARTERS;
    cents = cents % QUARTERS;
    coins = coins + cents / DIME;
    cents = cents % DIME;
    coins = coins + cents / NICKLES;
    cents = cents % NICKLES;
    coins = coins + cents;

    printf("%d\n",coins);
    return 0;
} 