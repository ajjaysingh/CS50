#include <stdio.h>
#include <string.h>
#include <cs50.h>

int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isAlpha_String(char *str) {
    int return_value = 1;
    for (int i = 0; str[i] != '\0'; ++i)
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))){
            return_value = 0;
            break;
        }
    return return_value;
}

int isUpper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Please enter a number as an argument!\n");
        return 1;
    }
    if (!isAlpha_String(argv[1])){
        printf("Keyword must only contain letters A-Z and a-z\n");
        return 1;
    }

    string toEncrypt = GetString();
    int n, key_len;
    n = strlen(toEncrypt);
    int key[n], key_string[n+1];
    key_len = strlen(argv[1]);
    
    for (int i = 0, j = 0; i < n; ++i) {
        if (isAlpha(toEncrypt[i])) {
            key_string[i] = argv[1][j % key_len];
            ++j;
        }
        else
            key_string[i] = toEncrypt[i];
    }
    
    for (int i = 0; i < n; ++i) {    // calculate caesar-key for each each character in the key string
        if (isAlpha(key_string[i])) {
            if(isUpper(argv[1][i % key_len]))
                key[i] = key_string[i] - 'A';
            else
                key[i] = key_string[i] - 'a';
        }
        else
            key[i] = 0;
    }

    for (int i = 0; toEncrypt[i] != '\0'; ++i) {
        if (isAlpha(toEncrypt[i])) {
            if (isUpper(toEncrypt[i]))
                toEncrypt[i] = 'A' + ((toEncrypt[i] - 'A') + key[i]) % 26;
            else
                toEncrypt[i] = 'a' + ((toEncrypt[i] - 'a') + key[i]) % 26;
        }
    }
    
    printf("%s\n", toEncrypt);

    return 0; 
}