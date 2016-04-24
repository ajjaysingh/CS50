#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int isAlpha(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isUpper(char c){
    return (c >= 'A' && c <= 'Z');
}

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Please enter a number as an argument!\n");
        return 1;
    }

    int k = atoi(argv[1]) % 26;
    string toEncrypt = GetString();

    for (int i = 0; toEncrypt[i] != '\0'; ++i) 
        if (isAlpha(toEncrypt[i])) {
            if(isUpper(toEncrypt[i]))
                toEncrypt[i] = 'A' + ((toEncrypt[i] - 'A') + k) % 26;
            else
                toEncrypt[i] = 'a' + ((toEncrypt[i] - 'a') + k) % 26;
        }
    
    printf("%s\n", toEncrypt);

    return 0;
}