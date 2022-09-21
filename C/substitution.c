//implimentation of a simple substitution cipher. Takes key as command line arguaments (cla), uses key for alphabetic substitution, eg a is swaped for first letter of key
//key must be 26 chars long, cant contain duplicates or non-alphabetic characters

#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *sub(char key[26]);

int main(int argc, char *argv[])
{
    //read key from argv, check for length, duplicates and non-alphabetic chars
    char key[26];
    bool checked[26] = {false};

    //check correct num and length of cla given. return 1 (error) if incorrect.
    //if correct, coppy cla to key
    if (argc != 2){ printf("Wrong inputs. ./substitution [key]\n"); return 1;}
    else if (strlen(argv[1]) != 26){printf("Key is of wrong length. Must be 26 chars \n"); return 1;}
    else{ strcpy(key, argv[1]);}

    //loop through key. Capitalise if lower case. Check for duplicates or non-alphabetic chars, return 1 (error) if incorrect.
    for (int i = 0; i < strlen(key); i++)
    {
        //if lowercase capitalise,check if not within bounds of capital leters, then if letter in key[i] has already been used, if not record, return error
        if (96 < key[i] && key[i] < 123){ key[i] = key[i] - 32;}
        if (!(64 < key[i] && key[i] < 91)){ printf("Key cannot contain non alphabetic chars \n"); return 1;}
        if (checked[(key[i] - 65)]){ printf("Duplicated chars in key."); return 1;}
        else{ checked[(key[i] - 65)] = true;}
    }

    //call sub function with prepaired key. Output returned ciphertext. free memory used to return.
    char *out = sub(key);
    printf("ciphertext: %s\n", out);
    free(out);
}


char *sub(char key[26])
{
    //get plaintext, allocate mem for ciphertext
    string plaintext = get_string("plaintext: ");
    char alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char *outtext = malloc(strlen(plaintext));
    int modifier[25];

    //loop through key, calculate how much int value of char needs to be changed by
    for (int i = 0; i < 26; i++){ modifier[i] = alph[i] - key[i];}

    //loop through plaintext, apply change calculated for modifier
    for (int i = 0; i < strlen(plaintext); i++)
    {
        int index = 0;
        bool c = false;

        //get lettter of alphabet for capital/lower, convert to index to check against in key. If alphabetic c = T
        if (64 < plaintext[i] && plaintext[i] < 91){index = plaintext[i] - 65; c = true;}
        else if (96 < plaintext[i] && plaintext[i] < 123){index = plaintext[i] - 97; c = true;}

        //if alphabetic preform modification, store char in outtext, if non-alphabetic store straight in outtext.
        if (c){ outtext[i] = plaintext[i] - modifier[index];}
        else{ outtext[i] = plaintext[i];}
    }

    //return pointer to finished outtext
    return outtext;
}

