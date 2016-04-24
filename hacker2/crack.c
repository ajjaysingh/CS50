#define _XOPEN_SOURCE       // this should be at the top before including any library
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <cs50.h>
#include <string.h>


int dictionary_attack (char* hash) { //perform the dictionary attack
    FILE *fp = fopen("/usr/share/dict/words", "r");
    char word[50], salt[3], *password;
    int found = 0;
    salt[2] = '\0';
    salt[0] = hash[0];
    salt[1] = hash[1];
    
    while (!feof(fp)) {
        fscanf(fp, "%s", word);
        word[strlen(word)] = '\0';

        password = crypt(word, salt);
        if(strcmp(hash, password) == 0){
            found = 1;
            printf("%s\n", word);
            break;
        }
    }
    if (found == 1)
        return 1;
    else
        return 0;
}

int check1(char *hash, char *salt, char *word) { //iterates over the first character
    char *password;
    for (char pos8 = 32; pos8 < 127; ++pos8){
        word[0] = pos8;
        password = crypt(word, salt);
        if(strcmp(hash, password) == 0){
            printf("%s\n", word);
            return 1;
        }
    }
    return 0;
}

int check2(char *hash, char *salt, char *word) {    //iterate over the second character
    char *password;
    for (char pos7 = 32; pos7 < 127; ++pos7) {
        word[1] = pos7;
        if(check1(hash, salt, word))
            return 1;    
    }
    return 0;
}

int check3(char *hash, char *salt, char *word) {    //iterate over the third character
    char *password;
    for (char pos6 = 32; pos6 < 127; ++pos6) {
        word[2] = pos6;
        if(check2(hash, salt, word))
            return 1;    
    }
    return 0;
}

int check4(char *hash, char *salt, char *word) {    //iterate over the forth character
    char *password;
    for (char pos5 = 32; pos5 < 127; ++pos5) {
        word[3] = pos5;
        if(check3(hash, salt, word))
            return 1;    
    }
    return 0;
}

int check5(char *hash, char *salt, char *word) {    //iterate over the fifth character
    char *password;
    for (char pos4 = 32; pos4 < 127; ++pos4) {
        word[4] = pos4;
        if(check4(hash, salt, word))
            return 1;    
    }
    return 0;
}

int check6(char *hash, char *salt, char *word) {    //iterate over the sixth character
    char *password;
    for (char pos3 = 32; pos3 < 127; ++pos3) {
        word[5] = pos3;
        if(check5(hash, salt, word))
            return 1;    
    }
    return 0;
}

int check7(char *hash, char *salt, char *word) {    //iterate over the seventh character
    char *password;
    for (char pos2 = 32; pos2 < 127; ++pos2) {
        word[6] = pos2;
        if(check6(hash, salt, word))
            return 1;    
    }
    return 0;
}

int check8(char *hash, char *salt, char *word) {    //iterate over the eighth character
    char *password;
    for (char pos1 = 32; pos1 < 127; ++pos1) {
        word[7] = pos1;
        if(check7(hash, salt, word))
            return 1;    
    }
    return 0;
}

int brute_force (char* hash) {                      //start the brute force attack to crack the password
    int len;
    char salt[3], *password, word[9];
    salt[2] = '\0';
    salt[0] = hash[0];
    salt[1] = hash[1];
    len = 1;

    word[len] = '\0';
    // printf("check1\n");
    if(check1(hash, salt, word)){
        return 1;
    }
    else{
        // printf("check2\n");
        len++;
        word[len] = '\0';
        if(check2(hash, salt, word))
            return 1;
        else{
            // printf("check3\n");
            len++;
            word[len] = '\0';
            if(check3(hash, salt, word))
                return 1;
            else{
                // printf("check4\n");
                len++;
                word[len] = '\0';
                if(check4(hash, salt, word))
                    return 1;
                else{
                    // printf("check5\n");
                    len++;
                    word[len] = '\0';
                    if(check5(hash, salt, word))
                        return 1;
                    else{
                        // printf("check6\n");
                        len++;
                        word[len] = '\0';
                        if(check6(hash, salt, word))
                            return 1;
                        else{
                            // printf("check7\n");
                            len++;     //len becomes 7 means it will check all hashes of words with lenght 7
                            word[len] = '\0';
                            if(check7(hash, salt, word))
                                return 1;
                            else{
                                // printf("check8\n");
                                len++;
                                word[len] = '\0';
                                if(check8(hash, salt, word))
                                    return 1;
                                else
                                    return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main(int argc, char ** argv) {
    if (argc != 2){
        printf("Please provide one argument!\n");
        return 1;
    }
    int found = 0;
    
    if (dictionary_attack(argv[1]))
        found = 1;
    else if(!found)
        brute_force(argv[1]);

    
    return 0;
}