//program to calculate the Coleman-Liau index of a given text.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void hundCoef(string txt, float *avgLenP, float *avgSentP);

int main(void)
{
    string txt = get_string("input text: ");
    float const consts[3] = {0.0588, 0.296, 15.8};
    float avgLen;
    float avgSent;
    int index;

    //funct to calculate terms for equation passed txt, and pointers to avgLen + avgSent
    hundCoef(txt, &avgLen, &avgSent);

    //calculate Coleman-Liau index. Using constants stored in consts, and computed values from hundCoef
    index = round((consts[0] * avgLen) - (consts[1] * avgSent) - consts[2]);

    //print output. Higher + lower edgecases, and main output.
    if (index < 1){printf("Grade Before Grade 1\n");}
    else if (index > 16){printf("Grade 16+\n");}
    else{printf("Grade %i\n", index);}
}

void hundCoef(string txt, float *avgLenP, float *avgSentP)
{
    float coef;
    int totW = 0;
    int totS = 0;
    int totL = 0;
    bool ignore = false;

    //loop through chars in txt
    for (int x = 0; x < strlen(txt); x++)
    {

        //if char is ' ', '!', '.', '?' and last char was not
        if ((txt[x] == 32 || txt[x] == 63 || txt[x] == 33 || txt[x] == 46) && !(ignore))
        {
            //count word
            totW++;

            //if sentance end char, count sentance, ignore = false, to miss space at start of new sentance
            if (txt[x] == 63 || txt[x] == 33 || txt[x] == 46){ totS++; ignore = true;}
        }
        //if char is letter, count letter, ignore = false, to catch next sentance end
        else if ((64 < txt[x]) && (txt[x] < 123)){totL++; ignore = false;}
    }

    //calculate per 100 Coefficient
    coef = 100 / (float)totW;

    //calculate total leters per 100, and sentaces per 100, in vars in main using passed pointers
    *avgLenP = coef * totL;
    *avgSentP = coef * totS;

}
