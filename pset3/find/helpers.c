/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int mid, left, right;
    left = 0;
    right = n - 1;
    
    while ((left <= right)) {
        mid = (left + right) / 2;
        if (values[mid] == value){
            return true;
        }
        else if (values[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int temp;
    for (int i = n - 1; i > 0; --i) {
        for (int j = 1; j < i; ++j) {
            if (values[j-1] > values[j]) {
                temp = values[j-1];
                values[j-1] = values[j];
                values[j] = temp;
            }
        }
    }
    return;
}