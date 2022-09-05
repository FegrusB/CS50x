//short program to output a mario obsicle to the console, of a height given by the user.

#include <cs50.h>
#include <stdio.h>
#include <string.h> /* included for strcpy() */
#include <stdlib.h> /* included for free() */

// variables used to build strings.
const char h[] = "#";
const char s[] = " ";

char *strrev(string str);

//main loop. Gets input from user, outputs constructed string to console.
int main(void)
{
    int ans;
    bool done = false;
    char out[8] = "";

    //loop for getting ans from user, loops untill done is true, done is true if 0<ans<9
    while(!(done))
    {
        ans = get_int("Please enter a number between 1 and 8: "); /* read ans from console */
        if((ans>0)&&(ans<9)){done = true;} /* If ans within bounds, exit loop.*/
    }

    //main loop for building output. Loop once for each line.
    for(int x=0;x<ans;x++)
    {
        //setup initial string, with spaces to equalise length, and hashes corresponding to line number
        strcpy(out,""); /* First clear the string. */
        for(int y = 0; y < ans-(x+1) ; y++){strcat(out,s);} /* concat out, and s(" "). */
        for(int z=0;z<x+1;z++){strcat(out,h);} /* concat out, and h("#"). */

        //print left side, middle spaces, and out reversed to form the right side
        char *c = strrev(out); /*get a pointer to the reversed string, created by strrev on the heap */
        printf("%s  %s\n",out,c); /*print both sides with spaces */
        free(c); /*free mem used by strrev*/
    }
}

//method to reverse a given string, and return a pointer to it on the heap.
char *strrev(string str)
{
    char *strOut = malloc(10); /* allocates space on the heap for the finished string */
    int len = strlen(str); /* gets/stores the length of input string */
    char *p = &str[len-1]; /* creates a pointer to the end of the input string */

    //loop to reverse input string, using pointer arithmetic
    for(int i=0;i<(len);i++)
    {
        strOut[i] = *p; /* stores the value pointed to by p in the heap string */
        p--; /* decrement p to get location of next char */
    }

    strOut[len] = '\0'; /* add string terminator */

    return strOut; /*return pointer to string on heap */
}

