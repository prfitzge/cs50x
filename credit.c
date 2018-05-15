#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//This program is designed to determine if a CC# is valid
int main(void)
{
    long long cc;
    long long valNum;
    int numDigits = 0;
    int curDigit;
    int reduceDigit = 0;
    long validNum;
    int oddSum = 0;
    int evenSum = 0;
    long ccStart;

    //prompt user to enter the cc#. Loop until the proper input is provided.
    do
    {
        cc = get_long_long("Enter a credit card number: ");
    }
    while (cc < 0);

    valNum = cc;
    //begin validation steps
    while (valNum != 0)
    {
        //incrememnt the digit counter
        numDigits += 1;

        //use modulo to get the last digit of the array
        curDigit = valNum % 10;

        //logic to sort the sets of digits for validation
        if (numDigits % 2 != 0)
        {
            //the odd digits -- sum
            oddSum += curDigit;
            //printf("oddsum: %i\n", oddSum);
        }
        else
        {
            //the even digits -- double then sum
            curDigit *= 2;

            //exception case to catch '10'
            if (curDigit == 10)
            {
                evenSum += 1;
            }
            //curDigit > 10
            else if (curDigit % 10 > 0)
            {
                //loop to get all the digits if the doubled value is > 10
                while (curDigit % 10 > 0)
                {
                    reduceDigit = (curDigit % 10);
                    curDigit /= 10;
                    evenSum += reduceDigit;
                }
                //final digit
                evenSum += curDigit;
            }
            //curDigit < 10
            else
            {
                //curDigit ends up being singular-digit #
                evenSum += curDigit;
            }
        }
        valNum /= 10;
    }

    //sum the two subtotals
    validNum = evenSum + oddSum;

    if (validNum % 10 != 0)
    {
        //invalid CC#
        printf("INVALID\n");
    }
    else
    {
        if (numDigits == 16 || numDigits == 13 || numDigits == 15)
        {
            //valid CC#
            //conditional logic to determine which CC company
            numDigits -= 2;
            ccStart = cc / pow(10, numDigits);

            if (ccStart == 34 || ccStart == 37)
            {
                printf("AMEX\n");
            }
            else if (40 <= ccStart && ccStart <= 49)
            {
                printf("VISA\n");
            }
            else if (51 <= ccStart && ccStart <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
