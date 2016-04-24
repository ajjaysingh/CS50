#include <stdio.h>
#include <cs50.h>

//converts a lower case character to upper case
char toUpper(char c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    return c;
}

int main() {
    string name;
    char prev;
    name = GetString();

    if (name[0] != ' ')
        printf("%c", toUpper(name[0]));
    prev = name[0];
    for (int i = 0; name[i] != '\0'; ++i) {
        if (prev == ' ' && name[i] != ' ')
            printf("%c", toUpper(name[i]));
        prev = name[i];
    }
    printf("\n");
    return 0;
}