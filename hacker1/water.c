#include <stdio.h>
#include <stdlib.h>
#define OUNCE 128

// int clean_Input() {
//     while (getchar()!='\n');
//     return 1;
// }

// // Take only integer input otherwise retry
// int getInt() {
//     int in, num;
//     char ch;
//     do {
//       printf("minutes: ");
//       in = scanf("%d%c", &num, &ch);
//     } while ((in == 0 || ch != '\n') && clean_Input()); //retry input if characters input are 0 or the next char to num in not newline
//     return num;
// }

// returns 1 if read is successful 0 if unsuccessful and the read string is returned in the array
int read(char* arr) {
    int pos, ret;
    ret = 1;
    pos = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch < '0' || ch > '9') {
            while (getchar() != '\n');
            ret = 0;
            break;
        }
        arr[pos++] = ch;
    }
    arr[pos] = '\n';
    if (arr[0] == '\n')
        ret = 0;    
    return ret;
}

int getInt(){
    char arr[500];
    int num;
    while(!read(arr) || (atoi(arr) == 0)){
        printf("Retry: ");
    }
    num = atoi(arr);
    return num;
}

int main() {
    int minutes, bottles;
    double waterUsed;
    
    printf("minutes: ");
    minutes = getInt();
    
    waterUsed = 1.5 * minutes * OUNCE;
    bottles = (int) (waterUsed / 16);
    
    printf("bottles: %d\n", bottles);
    return 0;
}