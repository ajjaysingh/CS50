#include <stdio.h>
#include <stdlib.h>
#define OUNCE 128

// returns 1 if read is successful 0 if unsuccessful and the read string is returned in the array
int read(char* arr) {
    int pos, ret;
    ret = 1;
    pos = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch < '0' || ch > '9') {
            ret = 0;
            while (getchar() != '\n');   //to clean up the standard input
            break;
        }
        arr[pos++] = ch;
    }
    arr[pos] = '\n';
    if (arr[0] == '\n') // if only newline char then should retry
        ret = 0;    
    return ret;
}

//returns a positive interger less than 23
int getHeight() {
    char arr[500];
    int num;
    do {
        printf("Height: ");
        while (!read(arr)) {
            printf("Retry: ");
        }
        num = atoi(arr);
    } while (num < 0 || num > 23);
    return num;
}

void draw(int height) {
    int len, lines, spaces;    // len stores the no of # to print
    len = 2;                   // lines stores the no of lines printed till now
    lines = 0;
    spaces = height - 1;        // stores the no of spaces to print per line
    while (lines < height) {
        for (int iter = 0; iter < spaces; ++iter)
            printf(" ");
        for (int iter = 0; iter < len; ++iter)
            printf("#");
        printf("\n");
        --spaces;
        ++len;
        ++lines;
    }
}

int main() {
    int height;
    
    height = getHeight();
    
    draw(height);
    
    return 0;
}