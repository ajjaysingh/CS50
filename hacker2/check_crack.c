#define _XOPEN_SOURCE       // this should be at the top before including any library
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <cs50.h>
#include <string.h>

char SET[64] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','.','/'};

int check(char *word, char *hash) {
    char salt[3], *password;
    int found = 0;
    salt[2] = '\0';
    for (int firstC = 0; firstC < 62 && !found; ++firstC) {
        for(int secondC = 0; secondC < 62; ++secondC) {
            salt[0] = SET[firstC];
            salt[1] = SET[secondC];
            password = crypt(word, salt);
            if (!strcmp(hash, password)){
                found = 1;
                break;
            }
            salt[0] = firstC - 32;
            password = crypt(word, salt); 
        }
    }
    return found;
}

char res[10] = "NOT FOUND";

char *find_crypt(char *word, char *result){
    char salt[3], *password;
    int found = 0;
    salt[2] = '\0';
    for (int firstC = 0; firstC < 62 && !found; ++firstC) {
        for(int secondC = 0; secondC < 62; ++secondC) {
            salt[0] = SET[firstC];
            salt[1] = SET[secondC];
            password = crypt(word, salt);
            if (!strcmp(result, password)){
                found = 1;
                printf("FOUND!!!\nsalt = %s\n", salt);
                break;
            }
            salt[0] = firstC - 32;
            password = crypt(word, salt); 
        }
    }
    if(found ==1)
        return result;
    else
        return res;
}

int main(int argc, char ** argv) {
    if (argc != 2){
        printf("Please provide one argument!\n");
        return 1;
    }
    
    FILE *fp = fopen("/usr/share/dict/words", "r");
    char *hash;
    // int found = 0, count;
    // salt[2] = '\0';
    
    // count = 0;
    // while (!feof(fp)) {
    //     fscanf(fp, "%s", word);
    //     word[strlen(word)] = '\0';
    //     salt[0] = word[0];
    //     salt[1] = word[1];
        // printf("%s\n",argv[1]);
        // printf("%d\t%lu\n",count,strlen(word));
        // break;
        // if (check(word, argv[1])){
        //     found = 1;
        //     break;
        // }
        // printf("%s\n", crypt("12345", salt));
        char word[10] = "PBJ";
        char salt[3] = "50";
        // word[4] = salt[2] = '\0';
        // hash = crypt("12345", "50");
        hash = crypt(word, salt);
        printf("hash = %s\n", hash);
        if(strcmp(hash, argv[1]) == 0){
            printf("found!!!! %s\n", word);
            // break;
        }
        // break;
        // ++count;
    // }
    // if (found == 1)
    //     printf("%s\n", word);
    // else
    //     printf("Not Found\n");

    // char *hash = crypt("12345", "50");
    // printf("%s\n", hash);
    
    return 0;
}