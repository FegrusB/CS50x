#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
//program to calculate the scrabble score of two works, and print the winner

// points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //print winner or tie
    if(score1>score2){printf("Player 1 wins!");}
    else if(score1<score2){printf("Player 2 wins!");}
    else{printf("Tie!");}
}

//takes a string, and returns the total scrabble score of the chars
int compute_score(string word)
{
    //total to be returned
    int tot = 0;

    //calculating loop
    for(int x=0; x<strlen(word);x++)
    {
        //get int value of char, normalise to lowercase, and - int value of a, to use as index. If not letter, continue
        int y = (word[x]);
        if((64<y)&&(y<91)){y = y-65;}
        else if((96<y)&&(y<123)) {y = y-97;}
        else{continue;}

        //get scrabble score of letter, add to tot
        tot = tot + POINTS[y];
    }

    //return total score
    return tot;
}
