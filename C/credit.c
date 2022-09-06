//Program to calculate the sytactic validity of a given credit card number.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long tot; /*stores the running total during check*/
    long cc = get_long("please enter a card number: "); /*gets credit card (cc) num from user*/
    long first = cc; /*duplicates cc for checking first digits*/
    long i = cc; /*duplicates cc for main calculation*/
    long m = 0; /*for storing modulus during main calculation*/
    bool alt = false; /*for alternating action preformed on each digit*/
    int count = 0; /*count num of digits in cc*/
    char res = 'i'; /*store type of cc, I = invalid by default*/

    //main calculation loop.
    //add the value of every other digit to tot (option 1)
    //for the other digits, sum the digits of the result of digit * 2 (option 2)
    //count keeps track of num of digits in cc
    do
    {
        //increment c. get last digit of i
        count ++;
        m = i % 10;

        //alternate between option 1&-1
        if(alt)
        {
            //takes the current digit (m), multiplies by two (m2)
            long m2 = m*2;/*for getting digits of m * 2*/

            //add each digit of the result to tot
            do
            {
                tot = tot+(m2%10);
                m2 = m2/10;

            }
            while(m2>0);

        }
        else
        {
            //add digit to tot
            tot = tot+m;
        }

        //divide i by ten, to lose m, alt * -1 to switch option for next digit
        i = i/10;
        alt = !alt;

    }
    while(i>0);

    //if tot has more than one digit, get the last
    if(tot>10){tot = tot%10;}

    //check card types and if valid. Store in res
    if(tot==0)
    {
        while(first>100){first = first/10;}
        if ((count==13 || count==16) && m==4){res = 'V';}
        else if(count==15 && (first==34 || first==37)){res = 'A';}
        else if(count ==16 && (50<first && first<56)){res = 'M';}
    }

    //print result based on res
    if(res=='A'){printf("AMEX\n");}
    else if(res=='M'){printf("MASTERCARD\n");}
    else if(res=='V'){printf("VISA\n");}
    else{printf("INVALID\n");}
}