#include <stdio.h>
#include "cs50.h"

int main() {
    int height, hashes, spaces; //hashes store the no of hashes to be printed per line
    hashes = 1;                 //spaces store the no of spaces to be printed per line

    printf("Enter a non-negative integer < 24: ");
    height = GetInt();
    while ( height < 0 || height >= 24) {
        printf("Retry: ");
        height = GetInt();
    } //get the height

    spaces = height - 1;
    for (int iter = 0; iter < height; ++iter) {
        for (int s = 0; s < spaces; ++s)
            printf(" ");
        for (int s = 0; s < hashes; ++s)
            printf("#");
        printf(" ");
        for (int s = 0; s < hashes; ++s)
            printf("#");
        printf("\n");
        --spaces;
        ++hashes;
    }

    return 0;
}